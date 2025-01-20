#include<iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;

    // Constroctor
    Node(int data) {
        this->data=data;
        this->next=NULL;
    }

    // Destrocter
    ~Node() {
        int value=this->data;
        //memory free
        if(this->next!=NULL) {
            delete next;
            this->next=NULL;
        }

        cout<<"Memory is free for node with data : "<<value<<endl;
    }
};

void insertNode(Node* &tail,int element,int d) {

    // assuming the element is present in list


    // empty list
    if(tail==NULL) {
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }

    else {
        // non empty list

        // assumong the element is present in list
        Node* curr=tail;
        while(curr->data!=element) {
            curr=curr->next;
        }

        // element found curr is representing element wala node

        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
        
    }
}

void deleteNode(Node* tail,int value) {
    // empty list
    if(tail==NULL) {
        cout<<"Empty list : "<<endl;
    }

    // non empty list 
    // assuming the value is present in linked list

    else 
    {
        Node* prev=tail;
        Node* curr=prev->next;


    while(curr->data!=value) {
        prev=curr;
        curr=curr->next;
    }

    // 1node linked list
    if(curr==prev) {
        tail=NULL;
    }


    // >2 node linked list
     else if(tail == curr) {
            tail=prev;
        }

    prev->next=curr->next;
    curr->next=NULL;
    
    delete curr;
    }

}

void print(Node* tail) {
    Node* temp=tail;
    if(tail==NULL) {
        cout<<"linked list is empty "<<endl;
        return;
    }
    do {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (tail!=temp) ;
        cout<<endl;
    
    
    
}

int main() {
    Node* tail=NULL;

    insertNode(tail,3,5);
    print(tail);

     
    insertNode(tail,5,6);
    print(tail);

     
    insertNode(tail,6,7);
    print(tail);

     
    insertNode(tail,5,10);
    print(tail);

     
    insertNode(tail,10,8);
    print(tail);

     
    insertNode(tail,5,12);
    print(tail);

    cout<<tail->data<<" "<<endl;
    

    deleteNode(tail,5);
    print(tail);
    


}