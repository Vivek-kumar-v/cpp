#include<iostream>
using namespace std;
 class Stack {

    // Properties
    public :
    int *arr;
    int top;
    int size;

    // Constructor
    Stack (int size) {
        this->size=size;
        arr=new int[size];
        top = -1;
    }

    // Pushing 
    void push(int element) {
        if(size-top > 1) {
          top++;
          arr[top]=element;  
        }
        else {
            cout<< " Stack is Underflow"<<endl;
        }
    }

    // Poping
    void pop() {
        if(top>=0) {
            top--;
        }
        else {
            cout<<" Stack Underflow "<<endl;
        }
    }

    // Top element
    int peak() {
        if(top>=0 ) {
            return arr[top];
        }
        else {
            cout << " Stack Underflow"<<endl;
            return -1;
        }
    }

    // IsEmpty 
    bool isEmpty () {
        if(top== -1) {
            return true;
        }
        else {
            return false;
        }
    }
    

 };

 int main() {
    Stack s(10);

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<< " Peak element : "<<s.peak()<<endl;
    s.pop();

    cout<< " Peak element : "<<s.peak()<<endl;

 }