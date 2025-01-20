#include<iostream>
using namespace std;
class A {
    public:
    void func1() {
        cout<<"Function 1 "<<endl;

    }
};

class B {
    public : 
    void func1() {
        cout<<"Function 1 "<<endl;
    }
};

class C: public A ,public B {

};


int main () {
    C object;
    object.A::func1();
     object.B::func1();
}