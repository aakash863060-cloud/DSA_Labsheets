//Q1. Create and display a Singly Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};

    cout << "Linked List: ";
    display(head);
    return 0;
}

//Q2. Insert at Beginning
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void insertBeginning(Node*& head, int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    insertBeginning(head, 30);
    insertBeginning(head, 20);
    insertBeginning(head, 10);
    display(head);
    return 0;
}

//Q3. Insert at End
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    display(head);
    return 0;
}

//Q4. Insert at Given Position
    #include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void insertAtPos(Node*& head, int val, int pos) {
    Node* newNode = new Node{val, nullptr};
    if (pos == 1) { newNode->next = head; head = newNode; return; }
    Node* temp = head;
    for (int i=1; temp && i<pos-1; i++) temp = temp->next;
    if (!temp) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    insertAtPos(head, 10, 1);
    insertAtPos(head, 20, 2);
    insertAtPos(head, 15, 2);
    display(head);
    return 0;
}

//Q5. Delete from Beginning#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void deleteBeginning(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node{10, new Node{20, new Node{30, nullptr}}};
    deleteBeginning(head);
    display(head);
    return 0;
}

//Q6. Delete from End
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void deleteEnd(Node*& head) {
    if (!head) return;
    if (!head->next) { delete head; head=nullptr; return; }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node{10, new Node{20, new Node{30, nullptr}}};
    deleteEnd(head);
    display(head);
    return 0;
}

// Q7. Delete from Given Position
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void deleteAtPos(Node*& head, int pos) {
    if (!head) return;
    if (pos==1) { Node* temp=head; head=head->next; delete temp; return; }
    Node* temp=head;
    for(int i=1; temp && i<pos-1; i++) temp=temp->next;
    if (!temp || !temp->next) return;
    Node* del=temp->next;
    temp->next=del->next;
    delete del;
}

void display(Node* head) {
    while (head) { cout<<head->data<<" -> "; head=head->next; }
    cout<<"NULL\n";
}

int main() {
    Node* head=new Node{10,new Node{20,new Node{30,nullptr}}};
    deleteAtPos(head,2);
    display(head);
    return 0;
}

//Q8. Search for Element
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

bool search(Node* head, int key) {
    while (head) {
        if (head->data == key) return true;
        head = head->next;
    }
    return false;
}

int main() {
    Node* head=new Node{10,new Node{20,new Node{30,nullptr}}};
    cout<<(search(head,20)?"Found":"Not Found")<<endl;
    return 0;
}

//Q9. Count Nodes
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int countNodes(Node* head) {
    int count=0;
    while(head){count++;head=head->next;}
    return count;
}

int main() {
    Node* head=new Node{10,new Node{20,new Node{30,nullptr}}};
    cout<<"Total nodes: "<<countNodes(head)<<endl;
    return 0;
}

//Q10. Find Max & Min
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void findMaxMin(Node* head) {
    if(!head) return;
    int max=head->data, min=head->data;
    while(head){ if(head->data>max) max=head->data; if(head->data<min) min=head->data; head=head->next; }
    cout<<"Max="<<max<<" Min="<<min<<endl;
}

int main() {
    Node* head=new Node{10,new Node{5,new Node{30,nullptr}}};
    findMaxMin(head);
    return 0;
}

//Q11. Reverse Linked List
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void reverse(Node*& head) {
    Node* prev=nullptr; Node* curr=head; Node* next=nullptr;
    while(curr){ next=curr->next; curr->next=prev; prev=curr; curr=next; }
    head=prev;
}

void display(Node* head){while(head){cout<<head->data<<" -> ";head=head->next;}cout<<"NULL\n";}

int main(){
    Node* head=new Node{10,new Node{20,new Node{30,nullptr}}};
    reverse(head);
    display(head);
    return 0;
}

//Q12. Sort Linked List Ascending
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void sortList(Node* head) {
    for(Node* i=head;i;i=i->next)
        for(Node* j=i->next;j;j=j->next)
            if(i->data>j->data) swap(i->data,j->data);
}

void display(Node* head){while(head){cout<<head->data<<" -> ";head=head->next;}cout<<"NULL\n";}

int main(){
    Node* head=new Node{30,new Node{10,new Node{20,nullptr}}};
    sortList(head);
    display(head);
    return 0;
}

//Q13. Menu-driven (Insertion, Deletion, Search, Display)
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void insertEnd(Node*& head,int val){
    Node* newNode=new Node{val,nullptr};
    if(!head){head=newNode;return;}
    Node* temp=head; while(temp->next) temp=temp->next;
    temp->next=newNode;
}

void deleteBeginning(Node*& head){
    if(!head) return;
    Node* temp=head; head=head->next; delete temp;
}

void deleteEnd(Node*& head){
    if(!head) return;
    if(!head->next){delete head; head=nullptr; return;}
    Node* temp=head; while(temp->next->next) temp=temp->next;
    delete temp->next; temp->next=nullptr;
}

bool search(Node* head,int key){
    while(head){ if(head->data==key) return true; head=head->next; }
    return false;
}

void display(Node* head){
    while(head){ cout<<head->data<<" -> "; head=head->next; }
    cout<<"NULL\n";
}

int main(){
    Node* head=nullptr;
    int choice,val;
    do{
        cout<<"\nMenu:\n1.Insert\n2.Delete Beginning\n3.Delete End\n4.Search\n5.Display\n6.Exit\nChoice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter value: "; cin>>val; insertEnd(head,val); break;
            case 2: deleteBeginning(head); break;
            case 3: deleteEnd(head); break;
            case 4: cout<<"Enter value: "; cin>>val; cout<<(search(head,val)?"Found":"Not Found")<<endl; break;
            case 5: display(head); break;
        }
    }while(choice!=6);
    return 0;
}

// Q14. Doubly Linked List (Insertion & Deletion)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node;   // allocate memory
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!head) { 
        head = newNode; 
        return; 
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from end
void deleteEnd(Node*& head) {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

// Display forward
void display(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    cout << "List after insertion: ";
    display(head);

    deleteEnd(head);
    cout << "List after deletion: ";
    display(head);

    return 0;
}


// Q15. Circular Linked List (Traversal & Insertion)
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void insertEnd(Node*& head,int val){
    Node* newNode=new Node{val,nullptr};
    if(!head){ head=newNode; newNode->next=head; return; }
    Node* temp=head;
    while(temp->next!=head) temp=temp->next;
    temp->next=newNode; newNode->next=head;
}

void traverse(Node* head){
    if(!head) return;
    Node* temp=head;
    do{ cout<<temp->data<<" -> "; temp=temp->next; }while(temp!=head);
    cout<<"(back to head)\n";
}

int main(){
    Node* head=nullptr;
    insertEnd(head,10); insertEnd(head,20); insertEnd(head,30);
    traverse(head);
    return 0;
}
