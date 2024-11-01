#include <iostream>
using namespace std;

class Base {
public:
    virtual void foo() { cout << "Base::foo" << endl; }
};

class X : virtual public Base {
public:
    void foo() override { cout << "X::foo" << endl; }
};

class Y : virtual public Base {
public:
    void foo() override { cout << "Y::foo" << endl; }
};

class Derived : public X, public Y {
public:
    void foo() override { Y::foo(); X::foo(); cout << "Derived::foo" << endl; }
};

int main() {
    Derived d;
    X* px = &d;
    Y* py = &d;

    px->foo();  // "X::foo" 출력
    py->foo();  // "Y::foo" 출력
}
