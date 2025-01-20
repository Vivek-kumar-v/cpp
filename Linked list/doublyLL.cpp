#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    // Constrocter

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // Distrocter
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Memory free for node with data : " << value << endl;
    }
};

// Get length
int getLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

// Traversing Node
void print(Node *head)
{
    Node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Insert at head
void insertAtHead(Node *&head, Node *&tail, int d)
{

    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
       
        head = temp;
        
    }
}

// Insert at tail
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    // Insert at starting
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < (position - 1))
    {
        temp = temp->next;
        count++;
    }

    // Inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    // create a new node
    Node *NodeToInsert = new Node(d);

    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    // Deleting first node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;

        // memory free start node
        temp->next = NULL;
        delete temp;
    }

    // Deleting any middle or last node
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr->next == NULL)
        {
            tail = curr->prev;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
        
    }
}

int main()
{
    // Node* node1=new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    print(head);

    cout << "Length : " << getLength(head) << endl;

    insertAtHead(head, tail, 20);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    insertAtHead(head, tail, 21);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    insertAtHead(head, tail, 22);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    insertAtTail(head, tail, 30);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    insertAtPosition(head, tail, 2, 40);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    insertAtPosition(head, tail, 4, 105);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    insertAtPosition(head, tail, 3, 101);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    deleteNode(head,tail,5);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;


}