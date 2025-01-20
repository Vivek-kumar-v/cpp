#include<iostream>
using namespace std;

    class Human {

        public:
        int age;
        int weight;
        int height;

        int getAge() {
            return this->age;
        }

       void setWeight(int w) {
            this->weight =w;
        }
    };

    class Male : public Human {

        public:
        string colour;

        void sleep() {
            cout<<"Male is sleeping "<<endl;
        }
    };

int main() {

    
    Male object1;
    Human object2;

    cout<<object1.age<<endl;
    cout<<object1.weight<<endl;
    object1.setWeight(74);
    cout<<object1.weight<<endl;
    object1.sleep();
    cout<<object1.colour<<endl;
    cout<<endl;
    
}