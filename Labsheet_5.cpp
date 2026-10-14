//Q1. Stack using Array (Push, Pop, Peek, Display)
#include <iostream>
using namespace std;

#define MAX 5
int Stack[MAX], top=-1;

void push(int val){
    if(top==MAX-1) cout<<"Stack Overflow\n";
    else Stack[++top]=val;
}

void pop(){
    if(top==-1) cout<<"Stack Underflow\n";
    else cout<<"Popped: "<<Stack[top--]<<endl;
}

void peek(){
    if(top==-1) cout<<"Stack Empty\n";
    else cout<<"Top element: "<<Stack[top]<<endl;
}

void display(){
    if(top==-1) cout<<"Stack Empty\n";
    else{
        cout<<"Stack: ";
        for(int i=top;i>=0;i--) cout<<Stack[i]<<" ";
        cout<<endl;
    }
}

int main(){
    push(10); push(20); push(30);
    display();
    pop();
    peek();
    display();
    return 0;
}


//Q2. Demonstrate Stack Overflow
#include <iostream>
using namespace std;

#define MAX 3
int Stack[MAX], top=-1;

void push(int val){
    if(top==MAX-1) cout<<"Stack Overflow!\n";
    else Stack[++top]=val;
}

int main(){
    push(1); push(2); push(3); push(4); // 4th push causes overflow
    return 0;
}

//Q3. Demonstrate Stack Underflow
#include <iostream>
using namespace std;

#define MAX 3
int Stack[MAX], top=-1;

void pop(){
    if(top==-1) cout<<"Stack Underflow!\n";
    else cout<<"Popped: "<<Stack[top--]<<endl;
}

int main(){
    pop(); // popping from empty stack
    return 0;
}

//Q4. Display TOP element using Peek
#include <iostream>
using namespace std;

#define MAX 5
int Stack[MAX], top=-1;

void push(int val){ if(top<MAX-1) Stack[++top]=val; }
void peek(){ if(top==-1) cout<<"Empty\n"; else cout<<"Top: "<<Stack[top]<<endl; }

int main(){
    push(10); push(20); push(30);
    peek();
    return 0;
}

//Q5. Menu-driven Stack Program
#include <iostream>
using namespace std;

#define MAX 5
int Stack[MAX], top=-1;

void push(int val){ if(top==MAX-1) cout<<"Overflow\n"; else Stack[++top]=val; }
void pop(){ if(top==-1) cout<<"Underflow\n"; else cout<<"Popped: "<<Stack[top--]<<endl; }
void peek(){ if(top==-1) cout<<"Empty\n"; else cout<<"Top: "<<Stack[top]<<endl; }
void display(){ if(top==-1) cout<<"Empty\n"; else{ for(int i=top;i>=0;i--) cout<<Stack[i]<<" "; cout<<endl; } }

int main(){
    int choice,val;
    do{
        cout<<"\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nChoice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter value: "; cin>>val; push(val); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    }while(choice!=5);
    return 0;
}

//Q6. Stack of Integers using Array
#include <iostream>
using namespace std;

#define MAX 5
int Stack[MAX], top=-1;

int main(){
    Stack[++top]=10;
    Stack[++top]=20;
    Stack[++top]=30;
    cout<<"Stack of integers: ";
    for(int i=top;i>=0;i--) cout<<Stack[i]<<" ";
    return 0;
}

//Q7. Reverse a String using Stack
#include <iostream>
#include <string>
using namespace std;

#define MAX 100
char Stack[MAX]; 
int top = -1;

// Push operation
void push(char c) {
    if(top == MAX-1) cout << "Overflow\n";
    else Stack[++top] = c;
}

// Pop operation
char pop() {
    if(top == -1) {
        cout << "Underflow\n";
        return '\0'; // return null char if empty
    }
    return Stack[top--];
}

int main() {
    string str = "HELLO";
    
    // Push all characters
    for(char c : str) push(c);

    // Pop all characters to reverse
    cout << "Reversed string: ";
    while(top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}

//Q8. Check Balanced Parentheses
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp){
    stack<char> s;
    for(char c:exp){
        if(c=='('||c=='{'||c=='[') s.push(c);
        else if(c==')'||c=='}'||c==']'){
            if(s.empty()) return false;
            char top=s.top(); s.pop();
            if((c==')'&&top!='(')||(c=='}'&&top!='{')||(c==']'&&top!='[')) return false;
        }
    }
    return s.empty();
}

int main(){
    string exp="{[()]}";
    cout<<(isBalanced(exp)?"Balanced":"Not Balanced");
    return 0;
}

//Q9. Infix to Postfix
#include <iostream>
#include <stack>
using namespace std;

int prec(char c){ if(c=='^') return 3; if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return -1; }

string infixToPostfix(string s){
    stack<char> st; string res="";
    for(char c:s){
        if(isalnum(c)) res+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){ while(!st.empty()&&st.top()!='('){ res+=st.top(); st.pop(); } st.pop(); }
        else{ while(!st.empty()&&prec(st.top())>=prec(c)){ res+=st.top(); st.pop(); } st.push(c); }
    }
    while(!st.empty()){ res+=st.top(); st.pop(); }
    return res;
}

int main(){
    string exp="A*(B+C)";
    cout<<"Postfix: "<<infixToPostfix(exp);
    return 0;
}

//Q8. Balanced Parentheses
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp){
    stack<char> s;
    for(char c:exp){
        if(c=='('||c=='{'||c=='[') s.push(c);
        else if(c==')'||c=='}'||c==']'){
            if(s.empty()) return false;
            char top=s.top(); s.pop();
            if((c==')'&&top!='(')||(c=='}'&&top!='{')||(c==']'&&top!='[')) return false;
        }
    }
    return s.empty();
}

int main(){ string exp="{[()]}"; cout<<(isBalanced(exp)?"Balanced":"Not Balanced"); }

//Q9. Infix to Postfix
#include <iostream>
#include <stack>
using namespace std;

int prec(char c){ if(c=='^') return 3; if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return -1; }

string infixToPostfix(string s){
    stack<char> st; string res="";
    for(char c:s){
        if(isalnum(c)) res+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){ while(!st.empty()&&st.top()!='('){ res+=st.top(); st.pop(); } st.pop(); }
        else{ while(!st.empty()&&prec(st.top())>=prec(c)){ res+=st.top(); st.pop(); } st.push(c); }
    }
    while(!st.empty()){ res+=st.top(); st.pop(); }
    return res;
}

int main(){ string exp="A*(B+C)"; cout<<"Postfix: "<<infixToPostfix(exp); }

//Q10. Evaluate Postfix
#include <iostream>
#include <stack>
using namespace std;

int evalPostfix(string exp){
    stack<int> st;
    for(char c:exp){
        if(isdigit(c)) st.push(c-'0');
        else{
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            switch(c){ case '+': st.push(a+b); break; case '-': st.push(a-b); break; case '*': st.push(a*b); break; case '/': st.push(a/b); break; }
        }
    }
    return st.top();
}

int main(){ string exp="23*54*+9-"; cout<<"Result: "<<evalPostfix(exp); }

//Q11. Infix to Prefix
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c){ if(c=='^') return 3; if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return -1; }

string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    for(char &c:s){ if(c=='(') c=')'; else if(c==')') c='('; }
    stack<char> st; string res="";
    for(char c:s){
        if(isalnum(c)) res+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){ while(!st.empty()&&st.top()!='('){ res+=st.top(); st.pop(); } st.pop(); }
        else{ while(!st.empty()&&prec(st.top())>=prec(c)){ res+=st.top(); st.pop(); } st.push(c); }
    }
    while(!st.empty()){ res+=st.top(); st.pop(); }
    reverse(res.begin(),res.end());
    return res;
}

int main(){ string exp="(A-B/C)*(A/K-L)"; cout<<"Prefix: "<<infixToPrefix(exp); }

//Q12. Two Stacks in One Array
#include <iostream>
using namespace std;

#define MAX 10
int Stack[MAX], top1=-1, top2=MAX;

void push1(int val){ if(top1<top2-1) Stack[++top1]=val; else cout<<"Overflow\n"; }
void push2(int val){ if(top1<top2-1) Stack[--top2]=val; else cout<<"Overflow\n"; }
void pop1(){ if(top1>=0) cout<<"Popped from Stack1: "<<Stack[top1--]<<endl; else cout<<"Underflow\n"; }
void pop2(){ if(top2<MAX) cout<<"Popped from Stack2: "<<Stack[top2++]<<endl; else cout<<"Underflow\n"; }

int main(){ push1(10); push2(20); pop1(); pop2(); }

//Q13. Stack using Class
#include <iostream>
using namespace std;

class Stack {
    int arr[5];   // fixed size array
    int top;      // index of top element
public:
    Stack() { top = -1; }   // constructor

    void push(int val) {
        if(top == 4) cout << "Overflow\n";
        else arr[++top] = val;
    }

    void pop() {
        if(top == -1) cout << "Underflow\n";
        else cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if(top == -1) cout << "Empty\n";
        else cout << "Top: " << arr[top] << endl;
    }

    void display() {
        if(top == -1) cout << "Empty\n";
        else {
            cout << "Stack: ";
            for(int i=top; i>=0; i--) cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack s;   // ✅ now recognized as a class object
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.peek();
    return 0;
}

//Q14. Stack use in Recursion
#include <iostream>
using namespace std;

// Factorial using recursion (stack frames are used implicitly)
int factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " = " << factorial(n) << endl;
    cout << "(Recursion uses system stack to store function calls)" << endl;
    return 0;
}

//Q15. Time Complexity of Stack Operation
#include <iostream>
using namespace std;

#define MAX 5
int Stack[MAX], top=-1;

void push(int val){ if(top<MAX-1) Stack[++top]=val; }
void pop(){ if(top>=0) top--; }
int peek(){ return (top==-1)?-1:Stack[top]; }
void display(){ for(int i=top;i>=0;i--) cout<<Stack[i]<<" "; cout<<endl; }

int main(){
    cout << "Push: O(1)\n";
    cout << "Pop: O(1)\n";
    cout << "Peek: O(1)\n";
    cout << "Display: O(n)\n";

    push(10); push(20); push(30);
    display();
    pop();
    cout << "Top element: " << peek() << endl;
    return 0;
}
