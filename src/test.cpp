#include <iostream>

class Parent {
private:
    virtual int bar() { return 1; }
public:
    int foo() { return bar(); }
};

class Child : public Parent {
private: 
    virtual int bar() { return 2; } 
};

int main() {
    int a = 10;

    std:: cout << (int *) a + 1 << std::endl;

    return 0;
}