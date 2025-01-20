#include<iostream>
#include<stack>
using namespace std;



int main () {

    // creation staack
    stack<int> s;

    // push operation 
    s.push(2);
    s.push(3);
    s.push(4);

    // Pop operation
    s.pop();

    cout << "Printing top element "<<s.top()<< endl;

    if(s.empty()) {
        cout<< "Stack is Empty "<<endl;
    }
    else {
        cout<<"Stack is not Empty"<<endl;
    }

}