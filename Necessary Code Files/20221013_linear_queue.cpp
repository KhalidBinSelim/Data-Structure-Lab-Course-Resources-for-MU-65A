#include<iostream>
#define SZ 100
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
//    cerr << "rear = " << rear << "\n";
}

void Queue::push(int x){
//    cerr << "rear = " << rear << "\n";
    if(rear+1==SZ){
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
    cout << q.Front() << "\n";
    cout << q.pop() << "\n";
    cout << q.empty() << "\n";
    cout << q.Front() << "\n";
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
