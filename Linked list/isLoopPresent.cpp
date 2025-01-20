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

// Function to detect loop
Node* floidDetectLoop(Node* head) {
    if(head==NULL) {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL) {
        fast=fast->next;
        if(fast!=NULL) {
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast) {
            cout<<"Cycle is present at "<< slow->data<<endl;
            return slow;
        }
    }
    return NULL;

}

int main() {
    Node* tail=NULL;

    insertNode(tail,3,5);
    insertNode(tail,5,6);
    insertNode(tail,6,7);
    insertNode(tail,5,10);
    insertNode(tail,10,8);  
    insertNode(tail,5,12);

    print(tail);

    if(floidDetectLoop(tail)!=NULL) {
        cout<<"Cycle is present "<<endl;
    }
    else {
        cout << "No cycle "<<endl;
    }
    


}