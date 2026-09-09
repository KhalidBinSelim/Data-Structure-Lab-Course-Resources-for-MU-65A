#include<iostream>
#define SZ 5
using namespace std;

struct node{
    int val;
    node *next;
    node(int x){
        val = x;
        next = NULL;
    }
};

struct Queue{
    node *front, *rear;
    Queue();
    void push(int x);
    int pop();
    int Front();
    bool empty();
};

Queue::Queue(){
    front = rear = NULL;
}

void Queue::push(int x){
    node *cur = new node(x);
    if(rear == NULL){
        front = rear = cur;
        return;
    }
    rear->next = cur;
    rear = cur;
}

int Queue::pop(){
    if(empty()){
        cout << "Underflow! Pop operation failed!\n";
        return -1;
    }
    node *temp = front;
    int x = temp->val;
    front = front->next;
    if(front==NULL) rear = NULL;
    delete temp;
    return x;
}

int Queue::Front(){
    if(empty()){
        cout << "No Front! Queue Empty!\n";
        return -1;
    }
    return front->val;
}

bool Queue::empty(){
    return front==NULL;
}

int main()
{
    Queue q;
    q.push(54);
    q.push(85);
    q.push(16);
    q.push(18);
    q.push(6);

    cout << q.Front() << "\n";
    cout << q.pop() << "\n";
    cout << q.empty() << "\n";
    cout << q.Front() << "\n";
    cout << q.pop() << "\n";
    cout << q.empty() << "\n";
    cout << q.pop() << "\n";
    cout << q.empty() << "\n";
    cout << q.pop() << "\n";
    cout << q.empty() << "\n";
    cout << q.pop() << "\n";
    cout << q.empty() << "\n";
    cout << q.pop() << "\n";
    cout << q.empty() << "\n";
    q.push(96);
    cout << q.empty() << "\n";
    cout << q.Front() << "\n";
    cout << q.pop() << "\n";
    cout << q.empty() << "\n";
    cout << q.Front() << "\n";
    return 0;
}
