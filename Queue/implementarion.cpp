#include<iostream>
using namespace std;

class Queue {
    public :
    int* arr;
    int front ;
    int rear;
    int size;
     
     // constructor
     Queue(int size) {
        this->size = size;
        arr=new int[size];
        front = 0;
        rear = -1;
     }

     // Pushing
     void push(int data ){
        if(rear >= size) {
            
            cout<<"Queue Overflow !! "<<endl;
           
        }
        else {
            rear++ ;
            arr[rear]=data;
             
        }
     }

     // Poping 
     void pop() {
        if(rear==front ) {
            cout<<"Queu is underflow !! "<<endl;
        }
        else {
            arr[front]=-1;
            front++ ;
            if(front == rear ) {
                front = 0;
                rear = 0;
            }
        }
     }

     // Front element 
     int qfront() {
        if(front == rear) {
            return -1 ;
        }
        else {
            return arr[front];
        }
     }
};

int main() {
    Queue  q(6);
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(15);
    q.push(20);
    
    q.pop();
    q.pop();

    cout<<q.qfront()<<endl;

 

    


}