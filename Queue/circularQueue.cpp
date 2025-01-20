#include<iostream>
using namespace std ;
class Queue {
    public :
    int *arr;
    int front;
    int rear;
    int size;

    // Constructor 
   Queue(int n) {
        size = n;
        arr=new int[size];
        front =rear = -1;
        
   }

    // Function to push an element in a Queue 
    void push(int data) {
        if((front==0 && rear== size -1) || rear == (front-1) % (size -1)) {
            cout<<"Queue is full " << endl;
            return;
        }
        else if(front == -1) {
            front = rear = 0;
            arr[rear]=data;
        }
        else if(rear == size - 1  && front !=0) {
            rear=0;
            arr[rear]=data;
        }
        else {
            rear++;
            arr[rear]=data;
        }

    }

    // Function to pop an element from Queue
    int dequeu() {
        
        if(front == -1) {
            cout << "Queue is empty "<<endl;
            return -1;
        }
        int x = arr[front];
        arr[front] = -1;
        if(front == rear ) {
            
            front = rear = -1;
           
        }
        else if(front == size - 1) {
        
            front = 0;
          
        }
        else {
            front++;
           
        }
        return x;
    }
};


int main () {
    Queue q(5);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    cout<<"Front : "<<q.arr[q.front]<<endl;
    cout<<"Rear : "<<q.arr[q.rear]<<endl;

    int v=q.dequeu();
    cout<<q.front<<endl;
    cout<<v<<endl;
    cout<<"Front : "<<q.arr[q.front]<<endl;
    cout<<"Rear : "<<q.arr[q.rear]<<endl;

    q.push(8);

    cout<<q.rear<<endl;
    cout<<q.arr[q.rear]<<endl;

    q.push(9);


}

