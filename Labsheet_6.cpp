//Q1. Queue using Array (Enqueue, Dequeue, Peek, Display)
#include <iostream>
using namespace std;

#define MAX 5
int Queue[MAX], front=-1, rear=-1;

void enqueue(int val){
    if(rear==MAX-1) cout<<"Overflow\n";
    else{
        if(front==-1) front=0;
        Queue[++rear]=val;
    }
}

void dequeue(){
    if(front==-1 || front>rear) cout<<"Underflow\n";
    else cout<<"Dequeued: "<<Queue[front++]<<endl;
}

void peek(){
    if(front==-1 || front>rear) cout<<"Empty\n";
    else cout<<"Front: "<<Queue[front]<<endl;
}

void display(){
    if(front==-1 || front>rear) cout<<"Empty\n";
    else{
        cout<<"Queue: ";
        for(int i=front;i<=rear;i++) cout<<Queue[i]<<" ";
        cout<<endl;
    }
}

int main(){
    enqueue(10); enqueue(20); enqueue(30);
    display(); dequeue(); peek(); display();
    return 0;
}

//Q2. Enqueue (Insertion at Rear)
#include <iostream>
using namespace std;

#define MAX 3
int Queue[MAX], front=-1, rear=-1;

void enqueue(int val){
    if(rear==MAX-1) cout<<"Queue Overflow!\n";
    else{
        if(front==-1) front=0;
        Queue[++rear]=val;
        cout<<"Inserted at Rear: "<<val<<endl;
    }
}

int main(){
    enqueue(10); enqueue(20); enqueue(30);
    return 0;
}

//Q3. Dequeue (Deletion from Front)
#include <iostream>
using namespace std;

#define MAX 3
int Queue[MAX], front=-1, rear=-1;

void dequeue(){
    if(front==-1 || front>rear) cout<<"Queue Underflow!\n";
    else cout<<"Deleted from Front: "<<Queue[front++]<<endl;
}

int main(){
    Queue[++rear]=10; Queue[++rear]=20; front=0;
    dequeue(); dequeue(); dequeue();
    return 0;
}

//Q4. Peek (Front element)
#include <iostream>
using namespace std;

#define MAX 5
int Queue[MAX], front=-1, rear=-1;

void peek(){
    if(front==-1 || front>rear) cout<<"Empty\n";
    else cout<<"Front element: "<<Queue[front]<<endl;
}

int main(){
    Queue[++rear]=10; Queue[++rear]=20; front=0;
    peek();
    return 0;
}

//Q5. Display Queue
#include <iostream>
using namespace std;

#define MAX 5
int Queue[MAX], front=0, rear=2;

int main(){
    Queue[0]=10; Queue[1]=20; Queue[2]=30;
    cout<<"Queue: ";
    for(int i=front;i<=rear;i++) cout<<Queue[i]<<" ";
    return 0;
}

//Q6. Queue Overflow
#include <iostream>
using namespace std;

#define MAX 2
int Queue[MAX], front=-1, rear=-1;

void enqueue(int val){
    if(rear==MAX-1) cout<<"Queue Overflow!\n";
    else{
        if(front==-1) front=0;
        Queue[++rear]=val;
    }
}

int main(){
    enqueue(1); enqueue(2); enqueue(3);
    return 0;
}

//Q7. Queue Underflow
#include <iostream>
using namespace std;

#define MAX 3
int Queue[MAX], front=-1, rear=-1;

void dequeue(){
    if(front==-1 || front>rear) cout<<"Queue Underflow!\n";
    else cout<<"Dequeued: "<<Queue[front++]<<endl;
}

int main(){
    dequeue(); // empty queue
    return 0;
}

//Q8. Menu-driven Queue
#include <iostream>
using namespace std;

#define MAX 5
int Queue[MAX], front=-1, rear=-1;

void enqueue(int val){ if(rear==MAX-1) cout<<"Overflow\n"; else{ if(front==-1) front=0; Queue[++rear]=val; } }
void dequeue(){ if(front==-1||front>rear) cout<<"Underflow\n"; else cout<<"Dequeued: "<<Queue[front++]<<endl; }
void peek(){ if(front==-1||front>rear) cout<<"Empty\n"; else cout<<"Front: "<<Queue[front]<<endl; }
void display(){ if(front==-1||front>rear) cout<<"Empty\n"; else{ for(int i=front;i<=rear;i++) cout<<Queue[i]<<" "; cout<<endl; } }

int main(){
    int choice,val;
    do{
        cout<<"\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nChoice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter value: "; cin>>val; enqueue(val); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    }while(choice!=5);
    return 0;
}

//Q9. Count Elements
#include <iostream>
using namespace std;

#define MAX 5
int Queue[MAX], front=0, rear=2;

int main(){
    Queue[0]=10; Queue[1]=20; Queue[2]=30;
    cout<<"Count: "<<(rear-front+1)<<endl;
    return 0;
}

//Q10. Search Element
#include <iostream>
using namespace std;

#define MAX 5
int Queue[MAX], front=0, rear=2;

int main(){
    Queue[0]=10; Queue[1]=20; Queue[2]=30;
    int key=20, found=0;
    for(int i=front;i<=rear;i++) if(Queue[i]==key) found=1;
    cout<<(found?"Found":"Not Found");
    return 0;
}

//Q11. Max & Min in Queue
#include <iostream>
using namespace std;

#define MAX 5
int Queue[MAX], front=0, rear=2;

int main(){
    Queue[0]=10; Queue[1]=5; Queue[2]=30;
    int max=Queue[front], min=Queue[front];
    for(int i=front;i<=rear;i++){ if(Queue[i]>max) max=Queue[i]; if(Queue[i]<min) min=Queue[i]; }
    cout<<"Max="<<max<<" Min="<<min;
    return 0;
}

//Q12. Reverse Queue
#include <iostream>
#include <stack>
using namespace std;

#define MAX 5
int Queue[MAX], front=0, rear=2;

int main(){
    Queue[0]=10; Queue[1]=20; Queue[2]=30;
    stack<int> s;
    for(int i=front;i<=rear;i++) s.push(Queue[i]);
    cout<<"Reversed Queue: ";
    while(!s.empty()){ cout<<s.top()<<" "; s.pop(); }
    return 0;
}

//Q13. Circular Queue
#include <iostream>
using namespace std;

#define MAX 5
int CQ[MAX], front=-1, rear=-1;

void enqueue(int val){
    if((rear+1)%MAX==front) cout<<"Overflow\n";
    else{
        if(front==-1) front=0;
        rear=(rear+1)%MAX;
        CQ[rear]=val;
    }
}

void dequeue(){
    if(front==-1) cout<<"Underflow\n";
    else{
        cout<<"Dequeued: "<<CQ[front]<<endl;
        if(front==rear) front=rear=-1;
        else front=(front+1)%MAX;
    }
}

void display(){
    if(front==-1) cout<<"Empty\n";
    else{
        int i=front;
        cout<<"Circular Queue: ";
        while(true){
            cout<<CQ[i]<<" ";
            if(i==rear) break;
            i=(i+1)%MAX;
        }
        cout<<endl;
    }
}

int main(){
    enqueue(10); enqueue(20); enqueue(30);
    display(); dequeue(); display();
    return 0;
}

//Q14. Queue using Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* Front = nullptr;
Node* Rear = nullptr;

void enqueue(int val) {
    Node* newNode = new Node{val, nullptr};
    if (!Rear) { // empty queue
        Front = Rear = newNode;
    } else {
        Rear->next = newNode;
        Rear = newNode;
    }
}

void dequeue() {
    if (!Front) {
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Dequeued: " << Front->data << endl;
    Node* temp = Front;
    Front = Front->next;
    if (!Front) Rear = nullptr; // queue became empty
    delete temp;
}

void display() {
    if (!Front) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Queue: ";
    Node* temp = Front;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}

//Q15. Compare Linear Queue vs Circular Queue
#include <iostream>
using namespace std;

#define MAX 5

// Linear Queue
int LQ[MAX];
int lfront = -1, lrear = -1;

void linearEnqueue(int val) {
    if (lrear == MAX-1) cout << "Linear Queue Overflow\n";
    else {
        if (lfront == -1) lfront = 0;
        LQ[++lrear] = val;
    }
}

void displayLinear() {
    if (lfront == -1 || lfront > lrear) cout << "Linear Queue Empty\n";
    else {
        cout << "Linear Queue: ";
        for (int i = lfront; i <= lrear; i++) cout << LQ[i] << " ";
        cout << endl;
    }
}

// Circular Queue
int CQ[MAX];
int cfront = -1, crear = -1;

void circularEnqueue(int val) {
    if ((crear+1)%MAX == cfront) cout << "Circular Queue Overflow\n";
    else {
        if (cfront == -1) cfront = 0;
        crear = (crear+1) % MAX;
        CQ[crear] = val;
    }
}

void displayCircular() {
    if (cfront == -1) cout << "Circular Queue Empty\n";
    else {
        cout << "Circular Queue: ";
        int i = cfront;
        while (true) {
            cout << CQ[i] << " ";
            if (i == crear) break;
            i = (i+1) % MAX;
        }
        cout << endl;
    }
}

int main() {
    cout << "--- Linear Queue ---\n";
    linearEnqueue(10); linearEnqueue(20); linearEnqueue(30);
    displayLinear();
    linearEnqueue(40); linearEnqueue(50); linearEnqueue(60); // overflow

    cout << "\n--- Circular Queue ---\n";
    circularEnqueue(10); circularEnqueue(20); circularEnqueue(30);
    circularEnqueue(40); circularEnqueue(50); // fills queue
    displayCircular();
    circularEnqueue(60); // overflow but space reused better

    cout << "\nComparison:\n";
    cout << "Linear Queue wastes space after deletions (front moves forward).\n";
    cout << "Circular Queue reuses freed space efficiently.\n";
    return 0;
}
