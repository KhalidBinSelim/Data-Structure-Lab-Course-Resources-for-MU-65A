#include <iostream>
using namespace std;

struct node{
    int val;
    node *prev;
    node(int v){
        val = v;
        prev = NULL;
    }
};

struct Stack{
    node *TOP;
    bool push(int x);
    int pop();
    int top();
    Stack();
};

bool Stack::push(int x){
    node *cur = new node(x);
    if(TOP!=NULL){
        cur->prev = TOP;
    }
    TOP = cur;
    return true;
}

Stack::Stack(){
    TOP = NULL;
}


int Stack::top(){
    if(TOP==NULL){
        cout << "Stack Empty!" << "\n";
        return -1;
    }
    return TOP->val;
}

int Stack::pop(){
    if(TOP==NULL){
        cout << "Underflow!" << "\n";
        return -1;
    }
    int ret = TOP->val;
    node *cur = TOP;
    TOP = cur->prev;
    delete cur;
    return ret;
}

int main()
{
    Stack *x = new Stack();

    x->pop();
    x->push(15); cout << x->top() << "\n";
    x->push(-6); cout << x->top() << "\n";
    x->push(85); cout << x->top() << "\n";
    x->push(32); cout << x->top() << "\n";
    x->pop(); cout << x->top() << "\n";
    x->pop();
    x->pop();
    x->pop();
    x->pop();
    x->pop();
//    cout <<  x->cnt << "\n";


    return 0;
}
