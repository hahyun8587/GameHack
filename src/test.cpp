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
    Child *child = new Child();

    std::cout << child->foo() << std::endl;

    return 0;
}