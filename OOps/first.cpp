#include<iostream>
using namespace std;

    class Hero {

    private :
    int health;

    public :
    char level;
    char* name;

    // Simple constroctor
    Hero() {
        cout<<"Simple constroctor called : "<<endl;
        name=new char[100];
    }

    // Parameter constroctor
    Hero (int health,char level) {
        this->health=health;
        this->level=level;
    }

    // Copy constrocter
    Hero(Hero& temp) {
        this->health=temp.health;
        this->level=temp.level;
        cout<<"Copy constrocter called"<<endl;
    }
    void print() {

        cout<<"Health : "<<this->health<<endl;
        cout<<"Level : "<<this->level<<endl;
    }
    int getHealth() {
        return health;
    }     

    char getLevel() {
        return level;

    }   

    void setHealth(int h) {
        health=h;
    }

    void setLevel(char l) {
        level=l;
    }

    void setName(char name[]) {
        strcpy(this->name,name);
    }

    };

int main() {

    // creation of object static allocation

    Hero a;
    a.setHealth(50);
    a.setLevel('A');
    cout<<"Health is : "<<a.getHealth()<<endl;
    cout<<"Level is : "<<a.getLevel()<<endl;

    // dynamic memmory  allocation

    Hero* b= new Hero;
    b->setHealth(60);
    b->setLevel('B');
    cout<<"Health is : "<<b->getHealth()<<endl;
    cout<<"Level is : "<<b->getLevel()<<endl;

    a.print();
    cout<<endl<<endl;

    Hero s(10,'x');
    s.print();


    // Copy constrocter
    Hero r(s);
    r.print();

    
    





}