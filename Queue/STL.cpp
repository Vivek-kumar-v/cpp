#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int>q;
    q.push(2);
    q.push(3);
    q.push(5);

    cout<<"front of queue is "<<q.front()<<endl;
    cout<<"size of queue is "<<q.size()<<endl;

    q.pop();
    cout<<"front of queue is "<<q.front()<<endl;
    cout<<"size of queue is "<<q.size()<<endl;

    if(q.empty()) {
        cout<<" Queue is empty "<<endl;
    }
    else {
        cout<<"Queue is not empty "<<endl;
    }
}