#include "stathack.hpp"

void StatHack::modify(GameType type) {
    switch (type) {
        case ASSULT_CUBE:                     
            DWORD *static_base;
            DWORD *dynamic_base;
            DWORD *health, *bullet;
                        
            static_base = (DWORD *) 0x50F4F4;
            dynamic_base = (DWORD *) *static_base;

            health = dynamic_base + 0xF8 / 4;
            bullet = (DWORD*) *(DWORD *) (*(dynamic_base + 0x374 / 4) + 0x14);
            
            while (1) {
                if (*health < 100) {
                    *health = 500;
                }

                if (*bullet < 5) {
                    *bullet = 20;
                }
            }
                    
            break;
    }       
}
