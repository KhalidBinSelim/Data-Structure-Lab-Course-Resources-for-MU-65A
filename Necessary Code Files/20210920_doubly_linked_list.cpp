#include <iostream>
using namespace std;

struct node{
    int val;
    node *prev,*next;
    node(){
    }
    node(int k){
        val = k;
        next = prev = NULL;
    }
};

struct DoublyLinkedList{
    node *head,*tail;
    DoublyLinkedList();
    ~DoublyLinkedList();
    /**
     * This function takes an integer parameter
     * and add it to the first of the doubly linked
     * list.
     * @return void - nothing to return
     * @param x - value to be added
     *            in the beginning of the list
     */
    void insertAtHead(int x);
    /**
     * This function takes an integer parameter
     * and add it to the last of the doubly linked
     * list.
     * @return void - nothing to return
     * @param x - value to be added
     *            in the end of the list
     */
    void insertAtTail(int x);
    /**
     * This function removes the first element from
     * the doubly linked list.
     */
    int dequeueFromHead();
    /**
     * This function removes the last element from
     * the doubly linked list.
     */
    int dequeueFromTail();
    /**
     * This function prints the whole doubly linked
     * list starting from the header node.
     */
    void printList();
    /**
     * This function prints the whole doubly linked
     * list starting from the trailer node.
     */
    void printListReversely();
    /**
     * This function insert a provided integer just
     * after the header node. If there is no node
     * exists in the list, it inserts the integer as
     * first element.
     */
    void insertAfterHead(int x);
    void insertBeforeTail(int x);
    void insertBeforeVal(int toFind, int toAdd);
    void insertBeforePos(int pos, int val);
    void insertAfterVal(int toFind, int toAdd);
    void insertAfterPos(int pos, int val);
    void insertAtPos(int pos, int val);
    int deleteAtPos(int x);
    int deleteVal(int x);
    int deleteHead();
    int deleteTail();
    int deleteValAfterHead();
    int deleteValBeforeTail();
};

DoublyLinkedList::DoublyLinkedList(){
        head = tail = NULL;
        cout << "Doubly Linked List initiated\n";
}

DoublyLinkedList::~DoublyLinkedList(){
        cout << "Oh! You killed me!\n";
}

void DoublyLinkedList::insertAtHead(int x){
    node *cur = new node(x);

    if(head==NULL && tail == NULL){
        head = tail = cur;
        return ;
    }
    cur->next = head;
    head->prev = cur;
    head = cur;
}

void DoublyLinkedList::insertAtTail(int x){
    node *cur = new node;
    cur->val = x;
    cur->prev = cur->next = NULL;

    if(head==NULL && tail == NULL){
        head = tail = cur;
        return ;
    }
    cur->prev = tail;
    tail->next = cur;
    tail = cur;
}

int DoublyLinkedList::dequeueFromHead(){
    node *temp = head;
    if(head == NULL){
        cout << "Underflow!" << endl;
        return -1;
    }
    if(head == tail){
        head = tail = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
    }
    int x = temp->val;
    delete temp;
    return x;
}

int DoublyLinkedList::dequeueFromTail(){
    node *temp = tail;
    if(tail == NULL){
        cout << "Underflow!" << endl;
        return -1;
    }
    if(head == tail){
        head = tail = NULL;
    }
    else{
        tail = tail->prev;
        tail->next = NULL;
    }
    int x = temp->val;
    delete temp;
    return x;
}

void DoublyLinkedList::printListReversely(){
    cout << "DoublyLinkedList - Reverse - Start\n";
    node *cur = tail;
    while(cur!=NULL)
    {
        cout << cur->val << endl;
        cur =  cur->prev;
    }
    cout << "DoublyLinkedList - Reverse - End\n";
}

void DoublyLinkedList::printList(){
    cout << "DoublyLinkedList - Start\n";
    node *cur = head;
    while(cur!=NULL)
    {
        cout << cur->val << endl;
        cur =  cur->next;
    }
    cout << "DoublyLinkedList - End\n";
}
int main()
{
    DoublyLinkedList dl;dl.printList();
    dl.insertAtTail(35);dl.printList();
    dl.insertAtHead(46);dl.printList();
    dl.insertAtTail(98);dl.printList();dl.printListReversely();
    dl.dequeueFromHead();dl.printList();
    dl.dequeueFromTail();dl.printList();
    dl.dequeueFromTail();dl.printList();
    dl.dequeueFromTail();dl.printList();
//    dl.dequeueFromHead();dl.printList();
//    dl.dequeueFromHead();dl.printList();
//    dl.dequeueFromHead();dl.printList();
    dl.dequeueFromTail();dl.printList();
//    sl.enqueue(445);sl.printList();
//    sl.dequeue();sl.printList();
//    sl.enqueue(7);sl.printList();
//    sl.enqueue(75);sl.printList();
//    sl.dequeue();sl.printList();
//    sl.dequeue();sl.printList();
//    sl.dequeue();sl.printList();
//    sl.dequeue();sl.printList();
    return 0;
}
