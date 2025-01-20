#include<iostream>
using namespace std;
class Hero {

    public:
    int health ;
    char level;
    char* name;
    static int timeToComplete;

    Hero() {
        cout<<"Simple constroctor called : "<<endl;
        name=new char[100];
    }

    Hero(Hero& temp) {
        char* ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        this->health=temp.health;
        this->level=temp.level;
        cout<<"Copy constrocter called"<<endl;
    }

    void print() {
        cout<<endl<<endl;
        cout<<"[ Name : "<<this->name<<" ,";
        cout<<"Health : "<<this->health<<" ,";
        cout<<"Level : "<<this->level<<" ]"<<endl<<endl;
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

    // Distructor 
    ~Hero() {
        cout<<"Distructor bhai called "<<endl;
    }
};

int Hero::timeToComplete=5;
int main() {

    cout<<"time to complete : "<<Hero::timeToComplete<<endl;
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('w');
    char name[6]="vivek";
    hero1.setName(name);
    hero1.print();

    Hero hero2(hero1);
    hero2.print();

    hero1.name[0]='N';
    hero1.print();

    hero2.print();

}