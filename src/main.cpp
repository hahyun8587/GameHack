#include "injector.hpp"

int main(int argc, char **argv) {
    Injector *injector = new Injector();
    
    injector->inject(L"ac_client.exe", argv[1]);

    return 0;
}