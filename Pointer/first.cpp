#include<iostream>
using namespace std;
int main () {
    int arr[5]={1,2,3,4,5};
    int i=3;
    int* p1=&i;
    int ** p2=&p1;

    cout <<endl<<endl<<"Sab chal rha hai "<<endl<<endl;
    cout<<"Value of p1 "<<p1<<endl;

    cout <<"Address of p1 "<<&p1<<endl;
    cout <<"Value at p2 "<<*p2<<endl;
    cout<<i<<endl;
    cout<<*p1<<endl;
    cout<<**p2<<endl;
    // cout<<"i[arr] is "<<i[arr];

}