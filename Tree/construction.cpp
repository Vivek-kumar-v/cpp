#include<iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root) {
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root= new Node(data);

    if(data == -1) {
        return NULL;
    }
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inserting right of "<<data <<endl;
    root ->right=buildTree(root->right);
    return root;
}

// Level Ordre traversar
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            // Old level complte
            cout<<endl;
            if(!q.empty()) {
                // still queue has some chil node
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data<<" ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }

        }
    }
}

// inorder traversal 
void inorder(Node* root) {
    if(root == NULL ) {
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Preorder traversal
void preorder(Node* root) {
    if(root == NULL) {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root ) {
    if(root== NULL) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


// Build tree from level order traversal
void buildFromLevelOrder(Node* &root) {
    queue<Node*>q;
    cout<<"Enter data for root "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left Node for "<<temp->data<<endl;
        int leftData;
        cin>> leftData;
    if(leftData != -1) {
        temp->left = new Node(leftData);
        q.push(temp->left);
    }
    cout<<"Ente right Node for "<<temp->data<<endl;
    int rightData;
    cin>>rightData;
    if(rightData != -1) {
        temp->right = new Node(rightData) ;
        q.push(temp->right);
    }
    }
}

int main() {
    Node* root = NULL;
    
    buildFromLevelOrder(root);
    // Creating a Tree
    root = buildTree (root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    levelOrderTraversal(root);
    cout<<endl<<"Inorder is ";
    inorder(root);
    cout<<endl<<"Preorder is  ";
    preorder(root);
    cout<<endl<<"Postorder is ";
    postorder(root);
}