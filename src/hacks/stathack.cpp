#include "stathack.hpp"

void StatHack::modify(GameType type) {
    switch (type) {
        case ASSULT_CUBE:                     
            DWORD *static_base;
            DWORD *dynamic_base;
            DWORD *health;
            unsigned short *bullet;
            //VirtualProtect((void *) bullet, 3, PAGE_EXECUTE_READWRITE, &old_protect);
            
            static_base = (DWORD *) 0x50F4F4;
            dynamic_base = (DWORD *) *static_base;

            health = dynamic_base + 0xF8 / 4;
            *health = 500;

            /**
            while (1) {
                if (*health < 50) {
                    *health = 500;
                }
            }
            **/

            bullet = (unsigned short*) *(DWORD *) (*(DWORD *) ((DWORD) dynamic_base + 374) + 14);
            *bullet = 15;
                    
            break;
    }       
}
