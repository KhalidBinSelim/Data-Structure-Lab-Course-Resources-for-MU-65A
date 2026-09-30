# Lab 4: Linked List

This document explains the topics of Lab 4. Read it before, during and after the lab session, then move on to `Basic Lab Exercises.md`.

**Compile and run:**

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

---

## Table of Contents

1. [Introduction to Linked List](#1-introduction-to-linked-list)
2. [Singly Linked List Operations](#2-singly-linked-list-operations)
3. [Doubly Linked List](#3-doubly-linked-list)
4. [Quick Summary](#4-quick-summary)

---

## 1. Introduction to Linked List

### 1.1 What is a Linked List?

A **linked list** is a linear data structure where elements (called **nodes**) are stored in separate memory blocks, and each node points to the next one. Unlike an array, the elements are **not** stored in contiguous memory.

```
[10 | next] -> [20 | next] -> [30 | next] -> NULL
```

### 1.2 Node Structure

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node();   // create one node manually
    head->data = 10;
    head->next = nullptr;

    cout << head->data << "\n";   // 10
    return 0;
}
```

`head` is a pointer to the first node of the list. If the list is empty, `head` is `nullptr`.

### 1.3 Array vs Linked List

| | Array | Linked List |
| --- | --- | --- |
| Memory | Contiguous | Scattered (linked by pointers) |
| Size | Fixed (or must be resized) | Grows/shrinks easily |
| Access | O(1) by index | O(n), must traverse |
| Insert/Delete at front | O(n), shifting needed | O(1), just relink pointers |

---

## 2. Singly Linked List Operations

All operations below build on this same `Node` structure and a global `head` pointer.

```cpp
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;
```

### 2.1 Traversing

Visit every node from `head` to the end (`nullptr`), one link at a time.

```cpp
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
```

### 2.2 Searching

Walk the list and compare each node's data with the target value.

```cpp
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}
```

### 2.3 Insertion

**Insert at the beginning** : O(1):

```cpp
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;      // new node points to old head
    return newNode;            // new node becomes the head
}
```

**Insert at the end** : O(n), must walk to the last node:

```cpp
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) return newNode;   // list was empty

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
```

**Insert at a given position** (0-indexed):

```cpp
Node* insertAtPosition(Node* head, int value, int pos) {
    if (pos == 0) return insertAtBeginning(head, value);

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) return head;   // position out of range

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
```

### 2.4 Deletion

**Delete from the beginning:**

```cpp
Node* deleteAtBeginning(Node* head) {
    if (head == nullptr) return nullptr;   // nothing to delete

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
```

**Delete by value:**

```cpp
Node* deleteByValue(Node* head, int value) {
    if (head == nullptr) return nullptr;

    if (head->data == value) {             // deleting the head itself
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return head;      // value not found

    prev->next = curr->next;
    delete curr;
    return head;
}
```

Always `delete` a node once it is unlinked, or the program leaks memory. Always check for `nullptr` before dereferencing, exactly as covered in Lab 1's pointer section.

---

## 3. Doubly Linked List

### 3.1 What is a Doubly Linked List?

A **doubly linked list** (two-way linked list) is a linked list where every node stores a pointer to **both** the next node and the previous node. This allows traversal in both directions.

```
NULL <- [prev|10|next] <-> [prev|20|next] <-> [prev|30|next] -> NULL
```

### 3.2 Node Structure

```cpp
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* head = nullptr;
```

### 3.3 Insertion

**Insert at the front:**

```cpp
DNode* insertFront(DNode* head, int value) {
    DNode* newNode = new DNode();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) head->prev = newNode;
    return newNode;
}
```

**Insert at the back:**

```cpp
DNode* insertBack(DNode* head, int value) {
    DNode* newNode = new DNode();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        return newNode;
    }

    DNode* temp = head;
    while (temp->next != nullptr) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
```

### 3.4 Deletion

**Delete from the front:**

```cpp
DNode* deleteFront(DNode* head) {
    if (head == nullptr) return nullptr;

    DNode* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;

    delete temp;
    return head;
}
```

**Delete from the back:**

```cpp
DNode* deleteBack(DNode* head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {   // only one node
        delete head;
        return nullptr;
    }

    DNode* temp = head;
    while (temp->next != nullptr) temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;
    return head;
}
```

### 3.5 Forward and Backward Traversal

```cpp
void traverseForward(DNode* head) {
    DNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void traverseBackward(DNode* head) {
    if (head == nullptr) return;

    DNode* temp = head;
    while (temp->next != nullptr) temp = temp->next;   // go to the last node

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}
```

**Full working example:**

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

int main() {
    DNode* head = nullptr;
    head = insertBack(insertBack(insertBack(head, 10), 20), 30);  // 10 20 30

    traverseForward(head);    // 10 20 30
    traverseBackward(head);   // 30 20 10
    return 0;
}
```

The extra `prev` pointer is what makes backward traversal and O(1) deletion from either end possible : this is the main advantage a doubly linked list has over a singly linked list.

---

## 4. Quick Summary

| Topic | Key Idea | Time |
| --- | --- | --- |
| Singly linked list | Each node points only to the next node | Traverse/search O(n), insert/delete at front O(1) |
| Insert at end / by position | Must walk the list to reach the spot | O(n) |
| Delete by value | Find the node, then relink the previous node's `next` | O(n) |
| Doubly linked list | Each node points to both `next` and `prev` | Insert/delete at either end O(1) |
| Backward traversal | Only possible with a `prev` pointer | O(n) |

**Common mistakes**

- Forgetting to update `head` after inserting/deleting the first node.
- Dereferencing a `nullptr` (e.g. calling `->next` on an empty list) without checking first.
- Forgetting to `delete` a removed node (memory leak).
- In a doubly linked list, updating `next` but forgetting to update the matching `prev` pointer (or vice versa).
