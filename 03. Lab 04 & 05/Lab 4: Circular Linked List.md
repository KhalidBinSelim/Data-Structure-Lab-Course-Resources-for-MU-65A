# Lab 4: Circular Linked List

This document explains the Circular Linked List as an extension of Lab 4. Read the singly and doubly linked list sections first, then read this one.

**Compile and run:**

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

---

## Table of Contents

1. [Introduction to Circular Linked List](#1-introduction-to-circular-linked-list)
2. [Circular Singly Linked List Operations](#2-circular-singly-linked-list-operations)
3. [Circular Doubly Linked List](#3-circular-doubly-linked-list)
4. [Quick Summary](#4-quick-summary)

---

## 1. Introduction to Circular Linked List

### 1.1 What is a Circular Linked List?

A **circular linked list** is a linked list where the last node points back to the **first node** instead of `nullptr`. There is no `NULL` at the end, so the list forms a loop.

```
Singly linked   : [10] -> [20] -> [30] -> NULL
Circular linked : [10] -> [20] -> [30] --+
                   ^                     |
                   +---------------------+
```

### 1.2 Tail Pointer Trick

We keep a pointer to the **last** node, called `tail`. Then:

- `tail` is the last node.
- `tail->next` is the first node (the head).

This makes insertion at both the beginning and the end **O(1)**. An empty list has `tail == nullptr`.

### 1.3 Node Structure

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};
```

### 1.4 Singly vs Circular

| | Singly Linked List | Circular Linked List |
| --- | --- | --- |
| Last node's `next` | `nullptr` | First node |
| End of traversal | `temp != nullptr` | Back at the starting node |
| Insert at end | O(n) (or O(1) with tail) | O(1) with `tail` |
| Can reach every node from any node | No | Yes |

> **Important:** because there is no `nullptr` at the end, a normal `while (temp != nullptr)` loop never stops. Traversal must stop when we return to the start.

---

## 2. Circular Singly Linked List Operations

All functions below take and return `tail`.

### 2.1 Traversing

Start at `tail->next` (the head) and stop when we come back to it. A `do-while` loop is used so the first node is not skipped.

```cpp
void traverse(Node* tail) {
    if (tail == nullptr) { cout << "Empty\n"; return; }

    Node* temp = tail->next;                 // head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);            // stop when back at head
    cout << "\n";
}
```

### 2.2 Searching

```cpp
bool search(Node* tail, int key) {
    if (tail == nullptr) return false;

    Node* temp = tail->next;
    do {
        if (temp->data == key) return true;
        temp = temp->next;
    } while (temp != tail->next);
    return false;
}
```

### 2.3 Insertion

**Insert at the beginning** : O(1):

```cpp
Node* insertAtBeginning(Node* tail, int value) {
    Node* newNode = new Node{value, nullptr};

    if (tail == nullptr) {                   // empty list: node points to itself
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;              // new node -> old head
    tail->next = newNode;                    // tail -> new node (new head)
    return tail;                             // tail does not change
}
```

**Insert at the end** : O(1):

```cpp
Node* insertAtEnd(Node* tail, int value) {
    Node* newNode = new Node{value, nullptr};

    if (tail == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;              // new node -> head
    tail->next = newNode;                    // old tail -> new node
    return newNode;                          // new node becomes the tail
}
```

The only difference between the two: inserting at the end moves `tail` to the new node.

### 2.4 Deletion

**Delete from the beginning** : O(1):

```cpp
Node* deleteAtBeginning(Node* tail) {
    if (tail == nullptr) return nullptr;     // empty list

    Node* head = tail->next;
    if (head == tail) {                      // only one node
        delete head;
        return nullptr;
    }
    tail->next = head->next;                 // skip the old head
    delete head;
    return tail;
}
```

**Delete by value** : O(n):

```cpp
Node* deleteByValue(Node* tail, int value) {
    if (tail == nullptr) return nullptr;

    Node* prev = tail;
    Node* curr = tail->next;                 // head
    do {
        if (curr->data == value) {
            if (curr == prev) {              // only one node in the list
                delete curr;
                return nullptr;
            }
            prev->next = curr->next;         // unlink
            if (curr == tail) tail = prev;   // deleted the tail: move tail back
            delete curr;
            return tail;
        }
        prev = curr;
        curr = curr->next;
    } while (prev != tail);                  // checked every node once

    return tail;                             // value not found
}
```

### 2.5 Full Working Example

```cpp
int main() {
    Node* tail = nullptr;

    tail = insertAtEnd(tail, 20);
    tail = insertAtEnd(tail, 30);
    tail = insertAtBeginning(tail, 10);
    traverse(tail);                          // 10 20 30

    cout << (search(tail, 20) ? "Found" : "Not Found") << "\n";   // Found

    tail = deleteByValue(tail, 20);
    traverse(tail);                          // 10 30

    tail = deleteAtBeginning(tail);
    traverse(tail);                          // 30
    return 0;
}
```

---

## 3. Circular Doubly Linked List

### 3.1 What is it?

A **circular doubly linked list** has both `next` and `prev` pointers, and the list is closed in both directions: the last node's `next` is the head, and the head's `prev` is the last node.

```
        +-----------------------------------+
        v                                   |
      [10] <-> [20] <-> [30] <---------------+
        |                                   ^
        +-----------------------------------+
```

Because `head->prev` is always the last node, we can reach both ends in O(1) using just `head`.

### 3.2 Node Structure

```cpp
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};
```

### 3.3 Insertion at the End

```cpp
DNode* insertAtEnd(DNode* head, int value) {
    DNode* newNode = new DNode{value, nullptr, nullptr};

    if (head == nullptr) {                   // empty list
        newNode->next = newNode->prev = newNode;
        return newNode;
    }

    DNode* last = head->prev;                // last node in O(1)
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return head;
}
```

### 3.4 Deletion at the End

```cpp
DNode* deleteAtEnd(DNode* head) {
    if (head == nullptr) return nullptr;

    DNode* last = head->prev;
    if (last == head) {                      // only one node
        delete head;
        return nullptr;
    }
    last->prev->next = head;
    head->prev = last->prev;
    delete last;
    return head;
}
```

### 3.5 Forward and Backward Traversal

```cpp
void traverseForward(DNode* head) {
    if (head == nullptr) return;
    DNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

void traverseBackward(DNode* head) {
    if (head == nullptr) return;
    DNode* last = head->prev;
    DNode* temp = last;
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != last);
    cout << "\n";
}

int main() {
    DNode* head = nullptr;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    traverseForward(head);                   // 10 20 30
    traverseBackward(head);                  // 30 20 10

    head = deleteAtEnd(head);
    traverseForward(head);                   // 10 20
    return 0;
}
```

---

## 4. Quick Summary

| Topic | Key Idea | Time |
| --- | --- | --- |
| Circular linked list | Last node points back to the first node | - |
| `tail` pointer | `tail->next` is the head, so both ends are reachable | - |
| Traverse / search | Use `do-while`, stop when back at the start | O(n) |
| Insert at beginning / end | Relink `tail->next`; move `tail` only for end insert | O(1) |
| Delete from beginning | `tail->next = head->next` | O(1) |
| Delete by value | Track `prev`, fix `tail` if the tail is deleted | O(n) |
| Circular doubly linked list | `head->prev` is the last node | Both ends O(1) |

**Applications:** round-robin CPU scheduling, multiplayer game turns, the Josephus problem, music/image playlists that repeat, and circular buffers.

**Common mistakes**

- Using `while (temp != nullptr)` for traversal, which creates an **infinite loop**.
- Using `while` instead of `do-while`, which skips the single-node case.
- Forgetting to make a single node point to **itself** (`newNode->next = newNode`).
- Forgetting to update `tail` after deleting the last node or inserting at the end.
- Forgetting to return `nullptr` when the last remaining node is deleted.
