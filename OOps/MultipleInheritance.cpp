#include<iostream>
using namespace std;


class Animal {


    public:

    int age;
    int weight;

    void Bark() {
        cout<<"Barking  "<<endl;
    }
};

class Human {

    public:
    string colour;

    void speak() {
        cout<<"Speaking  "<<endl;
    }
};

// Multiple Inheritance
class Hybrid : public Animal ,public Human {

};

int main() {
    Hybrid object1;
    object1.Bark();
    object1.speak();
}