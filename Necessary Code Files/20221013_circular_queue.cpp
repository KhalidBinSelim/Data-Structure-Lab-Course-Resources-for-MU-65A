#include<iostream>
#define SZ 5
using namespace std;

struct Queue{
    int q[SZ], front, rear;
    Queue();
    void push(int x);
    int pop();
    int Front();
    bool empty();
};

Queue::Queue(){
    front = rear = -1;
}

void Queue::push(int x){
    if(rear+1==SZ) rear = -1;
    if(rear+1==front){
        cout << "Overflow! Push operation failed!\n";
        return;
    }
    if(front==-1 && rear ==-1)
        front++;
    q[++rear] = x;
}

int Queue::pop(){
    if(empty()){
        cout << "Underflow! Pop operation failed!\n";
        return -1;
    }
    int x = q[front++];
    if(front==SZ) front = 0;
    if(rear == front-1) front = rear = -1;
    return x;
}

int Queue::Front(){
    if(empty()){
        cout << "No Front! Queue Empty!\n";
        return -1;
    }
    return q[front];
}

bool Queue::empty(){
    return !~front; /// front == -1
}

int main()
{
    Queue q;
    q.push(54);
    q.push(85);
    q.push(16);
    q.push(18);
    q.push(6);
    q.push(14);
    q.push(86);
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
