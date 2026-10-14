//Create a Binary Tree
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Binary Tree created with root = " << root->data << endl;
    return 0;
}

//Inorder Traversal
void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

//Preorder Traversal
void preorder(Node* root) {
    if(root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

//Postorder Traversal
void postorder(Node* root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

//All Three Traversals
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;
    return 0;
}

//Create BST by inserting n elements
Node* insert(Node* root, int val) {
    if(!root) return createNode(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

//Search in BST
bool search(Node* root, int key) {
    if(!root) return false;
    if(root->data == key) return true;
    if(key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

//Insert in BST + Inorder
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Inorder after insertion: ";
    inorder(root);
    return 0;
}

// Delete Leaf Node in BST
Node* deleteLeaf(Node* root, int key) {
    if(!root) return nullptr;
    if(key < root->data) root->left = deleteLeaf(root->left, key);
    else if(key > root->data) root->right = deleteLeaf(root->right, key);
    else {
        if(!root->left && !root->right) { delete root; return nullptr; }
    }
    return root;
}

//Delete Node with One Child
Node* deleteOneChild(Node* root, int key) {
    if(!root) return nullptr;
    if(key < root->data) root->left = deleteOneChild(root->left, key);
    else if(key > root->data) root->right = deleteOneChild(root->right, key);
    else {
        if(!root->left && root->right) { Node* temp=root->right; delete root; return temp; }
        if(root->left && !root->right) { Node* temp=root->left; delete root; return temp; }
    }
    return root;
}

//Delete Node with Two Children (Inorder Successor)
Node* minValueNode(Node* node) {
    Node* current = node;
    while(current && current->left) current = current->left;
    return current;
}

Node* deleteTwoChildren(Node* root, int key) {
    if(!root) return nullptr;
    if(key < root->data) root->left = deleteTwoChildren(root->left, key);
    else if(key > root->data) root->right = deleteTwoChildren(root->right, key);
    else {
        if(root->left && root->right) {
            Node* succ = minValueNode(root->right);
            root->data = succ->data;
            root->right = deleteTwoChildren(root->right, succ->data);
        }
    }
    return root;
}

//Height of Binary Tree
int height(Node* root) {
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

//Count Total Nodes
int countNodes(Node* root) {
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//Count Leaf Nodes
int countLeaves(Node* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

//Menu-driven BST
#include <iostream>
using namespace std;

struct Node { int data; Node* left; Node* right; };
Node* createNode(int val){ return new Node{val,nullptr,nullptr}; }

Node* insert(Node* root,int val){
    if(!root) return createNode(val);
    if(val<root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}

void inorder(Node* root){ if(root){ inorder(root->left); cout<<root->data<<" "; inorder(root->right);} }
void preorder(Node* root){ if(root){ cout<<root->data<<" "; preorder(root->left); preorder(root->right);} }
void postorder(Node* root){ if(root){ postorder(root->left); postorder(root->right); cout<<root->data<<" ";} }
int height(Node* root){ return root?1+max(height(root->left),height(root->right)):0; }
int countNodes(Node* root){ return root?1+countNodes(root->left)+countNodes(root->right):0; }

int main(){
    Node* root=nullptr; int choice,val;
    do{
        cout<<"\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Height 6.CountNodes 7.Exit\nChoice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter value: "; cin>>val; root=insert(root,val); break;
            case 2: inorder(root); cout<<endl; break;
            case 3: preorder(root); cout<<endl; break;
            case 4: postorder(root); cout<<endl; break;
            case 5: cout<<"Height="<<height(root)<<endl; break;
            case 6: cout<<"Nodes="<<countNodes(root)<<endl; break;
        }
    }while(choice!=7);
    return 0;
}
