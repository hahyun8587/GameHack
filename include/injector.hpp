#ifndef INJECTOR_H
#define INJECTOR_H

/**
 * @brief Injector that injects dll to target process.
 */
class Injector {
public:
    /**
     * @brief Injects `dll_name` named dll to `proc_name` named process. 
     * 
     * @param proc_name name of the process to be injected
     * @param dll_name name of the dll to inject
     */
    void inject(const wchar_t *proc_name, const char *dll_name);    
};

#endif
