#include <iostream>
using namespace std;

struct node{
    int val;
    node *next;
};

struct Stack{
    int arr[100], cnt;
    bool push(int x){
        if(cnt==3){
            cout << "Overflow!" << "\n";
            return false;
        }
        arr[cnt++] = x;
        return true;
    }
    bool pop();
    int top();
    Stack();
    Stack(int pos);
    ~Stack();
};

Stack::~Stack(){
    cout << "Oh no! I am dying!\n";
}

Stack::Stack(){
    cnt = 0;
    cout << "Value of cnt = " << cnt << "\n";
}

Stack::Stack(int v){
    cnt = v;
    cout << "Value of cnt = " << cnt << "\n";
}

int Stack::top(){
    if(cnt==0){
        cout << "Stack Empty!" << "\n";
        return -1;
    }
    return arr[cnt-1];
}

bool Stack::pop(){
    if(cnt==0){
        cout << "Underflow!" << "\n";
        return false;
    }
    arr[--cnt] = 0;
    return true;
}

int main()
{
    Stack x, *y = new Stack(3);
    int *vals = new int[100];
    x.pop();
    x.push(15); cout << x.top() << "\n";
    x.push(-6); cout << x.top() << "\n";
    delete y;
    y->push(85); cout << y->top() << "\n";
    y->push(32); cout << y->top() << "\n";
    x.pop(); cout << x.top() << "\n";
    y->pop();
    y->pop();
    y->pop();
    x.pop();
    x.pop();
    cout <<  x.cnt << "\n";


    return 0;
}
