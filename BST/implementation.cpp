#include<iostream>
#include<queue>
using namespace std;
class Node {
    public :
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBST(Node* root , int d) {
    // base case 
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(d > root->data) {
        // insert in right part
        root->right = insertInBST(root->right , d);
    }
    else {
        // insert in left part 
        root->left = insertInBST(root->left , d);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
       root = insertInBST(root,data);
        cin >> data;
    }
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

Node* minVal(Node* temp) {
    while(temp != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root , int val) {
    // base case 
    if(root == NULL) {
        return root;
    }
    if(root->data == val) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root ;
            return NULL;
        }
        // 1 child

        // left child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL) {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data > val) {
        //go to left part 
        root->left = deleteFromBST(root->left , val);
        return root;
    }
    else {
        // go to right part
        root->right = deleteFromBST(root->right , val);
        return root;
    }
}


int main() {

    Node* root = NULL;

    cout<<"Enter data to create BST "<<endl;
    takeInput(root);

    cout<<"Printing of BST"<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"inorder is : ";
    inorder(root);
    cout<<endl<<"Preorder is : ";
    preorder(root);
    cout<<endl<<"Postorder is : ";
    postorder(root);

    cout<<"after deletion "<<endl;
    deleteFromBST(root ,90);

    cout<<"Printing of BST"<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"inorder is : ";
    inorder(root);
    cout<<endl<<"Preorder is : ";
    preorder(root);
    cout<<endl<<"Postorder is : ";
    postorder(root);
    return 0;

    // INPUTS 50 20 70 10 30 90 110 -1
}