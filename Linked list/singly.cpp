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

void insertAtHead(Node* &head,int d) {
    // Create a new node
    Node* temp=new Node(d);

    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail, int d) {

    // Create a new node
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;

}

void insertAtPosition(Node* &head ,Node* &tail,int position,int d) {

    // Insert at starting
    if(position==1) {
        insertAtHead(head,d);
        return ;
    }

    


    Node* temp=head;
    int count=1;
    while(count<(position-1)) {
        temp=temp->next;
        count++;
    }

    // Inserting at last position
    if(temp->next==NULL) {
        insertAtTail(tail,d);
        return ;
    }


    // create a new node
    Node* NodeToInsert=new Node(d);


    NodeToInsert->next=temp->next;

    temp->next=NodeToInsert;

    
}

void print(Node* &head) {
    Node* temp= head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteNode(Node* &head,Node* &tail,int position) {
    // Deleting first node
    if(position==1) {
        Node* temp=head;
        head=head->next;
        // memory free start node
        temp->next=NULL;
        delete temp;
    }

    // Deleting any middle or last node
    else {
        Node* curr=head;
        Node*prev=NULL;
        int count=1;
        while(count<position) {
            prev=curr;
            curr=curr->next;
            count++;
        }

        if(curr->next==NULL) {
            tail=prev;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main() {

    // Created a new node
    Node* node1 = new Node(5);
   // cout<<"Data : "<<node1->data<<endl;
    // cout<<"Next : "<<node1->next<<endl;

    // Head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    print(head);

    // insertAtHead(head,12);
    insertAtTail(tail,10);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtPosition(head,tail,3,22);
    print(head);

    insertAtPosition(head,tail,1,25);
    print(head);

    insertAtPosition(head,tail,6,30);
    print(head);

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    deleteNode(head,tail,5);
    print(head);

    insertAtTail(tail,100);
    print(head);

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
}