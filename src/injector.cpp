#include <Windows.h>
#include <TlHelp32.h>
#include <string.h>
#include "injector.hpp"


#include <iostream>

#define BUF_SIZE 128

void Injector::inject(const wchar_t *tar_proc_name, const char *dll_name) {
    HANDLE snapshot;
    PROCESSENTRY32W pe;
    
    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    pe.dwSize = sizeof(PROCESSENTRY32W);
    
    Process32FirstW(snapshot, &pe);

    do {        
        if (!wcscmp(pe.szExeFile, tar_proc_name)) {
            std::cout << "found target process" << std::endl;
            std::wcout << tar_proc_name << std::endl;
            
            HANDLE process;
            HANDLE thread;
            FARPROC start_routine;
            void *base_addr;
            int dll_name_len;
            
            process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID); 
            dll_name_len = strlen(dll_name);
            base_addr = VirtualAllocEx(process, NULL, dll_name_len + 1, 
                                       MEM_COMMIT, PAGE_READWRITE);
                        
            WriteProcessMemory(process, base_addr, 
                               (void *) dll_name, dll_name_len + 1, NULL);
    
            start_routine = GetProcAddress(GetModuleHandleA("kernel32.dll"), 
                                           "LoadLibraryA");
   
            thread = CreateRemoteThread(process, NULL, 0, 
                                        (LPTHREAD_START_ROUTINE) start_routine, 
                                        base_addr, 0, NULL);
            DWORD exit_code = -1;
            std::cout << thread << std::endl;
            WaitForSingleObject(thread, INFINITE);
            GetExitCodeThread(thread, &exit_code);
            std::cout << exit_code << std::endl;
            VirtualFreeEx(process, base_addr, dll_name_len + 1, MEM_RELEASE);
            CloseHandle(thread);
            CloseHandle(process);
            
            break;
        }
    } while (Process32NextW(snapshot, &pe));
}
