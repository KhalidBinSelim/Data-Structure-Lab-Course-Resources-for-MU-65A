# Lab 4: Basic Lab Exercises

**Topics:** Linked List (Traversing, Searching, Insertion, Deletion), Doubly Linked List, Circular Linked List

These exercises are short and self-contained. Read `Lab 4: Linked List.md` and `Lab 4: Circular Linked List.md` first, then write each program yourself in C++, compile it, and run it against the sample input to confirm you understood the concept. No online judge, account, or submission is needed.

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

**Rules**

- Exercises 1 to 8 use a **singly linked list** with `struct Node { int data; Node* next; };`.
- Exercises 9 to 12 use a **doubly linked list** with `struct DNode { int data; DNode* next; DNode* prev; };`.
- Exercises 13 to 18 use a **circular linked list**. Exercises 13 to 17 use `Node` with a **`tail`** pointer (`tail->next` is the head). Exercise 18 uses a circular `DNode` list with a `head` pointer.
- Write each part as a separate program, because the singly, doubly and circular versions use the same function names.
- Always check for `nullptr` before dereferencing a pointer.
- Always `delete` a node once it is removed from the list.
- In a circular list, never traverse with `while (temp != nullptr)`; use `do-while` and stop when you return to the start.

---

## Part A: Introduction and Traversal

### Exercise 1: Build and Print a List

Manually create three nodes with values `10`, `20`, `30`, link them together, and print the list using a `traverse` function.

```
Output: 10 20 30
```

*Hint: create each `Node` with `new`, then set `node1->next = node2;` and so on.*

### Exercise 2: Count the Nodes

Write a function `int countNodes(Node* head)` that returns how many nodes are in the list, using traversal (no built-in size tracking).

```
Input : 10 20 30 40
Output: 4
```

### Exercise 3: Sum of All Values

Write a function `int sumList(Node* head)` that returns the sum of all node values.

```
Input : 10 20 30
Output: 60
```

---

## Part B: Searching

### Exercise 4: Search by Value

Write `bool search(Node* head, int key)` exactly as shown in the class resources. Test it with a key that exists and a key that does not.

```
Input : list = 5 10 15 20, key = 15
Output: Found

Input : list = 5 10 15 20, key = 99
Output: Not Found
```

### Exercise 5: Find the Maximum

Write a function `int findMax(Node* head)` that returns the largest value in the list, using a single traversal.

```
Input : 3 7 2 9 4
Output: 9
```

---

## Part C: Insertion

### Exercise 6: Insert at Beginning and End

Start with an empty list (`head = nullptr`). Insert `30` at the end, then `20` at the end, then `10` at the beginning. Print the final list.

```
Output: 10 30 20
```

### Exercise 7: Insert at a Given Position

Read a list, a value, and a position, then insert the value at that position (0-indexed) using `insertAtPosition` from the class resources.

```
Input : list = 1 2 4 5, value = 3, position = 2
Output: 1 2 3 4 5
```

### Exercise 8: Build a List from User Input

Read an integer `n`, then read `n` values one at a time, inserting each one at the **end** of the list as it is read. Print the final list.

```
Input :
5
1 2 3 4 5

Output: 1 2 3 4 5
```

---

## Part D: Deletion

### Exercise 9: Delete from the Beginning

Build the list `10 20 30`, delete the first node, and print the result.

```
Output: 20 30
```

### Exercise 10: Delete by Value

Build the list `5 10 15 20`, delete the node with value `15`, and print the result. Then try deleting a value that does not exist and confirm the list is unchanged.

```
Input : list = 5 10 15 20, delete 15
Output: 5 10 20
```

---

## Part E: Doubly Linked List

### Exercise 11: Build, Insert, and Traverse Both Ways

Using `DNode`, build the list `10 20 30` with `insertBack`, then print it with `traverseForward` and `traverseBackward`.

```
Output:
Forward : 10 20 30
Backward: 30 20 10
```

### Exercise 12: Insert at Front and Delete from Back

Start with the doubly linked list `20 30` (built with `insertBack`). Insert `10` at the front using `insertFront`, then delete the back node using `deleteBack`. Print the list after each step.

```
After insertFront(10): 10 20 30
After deleteBack():    10 20
```

---

## Part F: Circular Linked List

### Exercise 13: Build and Traverse a Circular List

Start with `tail = nullptr`. Insert `10`, `20`, `30` at the end using `insertAtEnd`, then print the list using `traverse`.

```
Output: 10 20 30
```

*Hint: use a `do-while` loop that starts at `tail->next` and stops when it comes back to `tail->next`.*

### Exercise 14: Insert at Beginning and End

Start with an empty circular list. Insert `20` at the end, `30` at the end, then `10` at the beginning. Print the list, then print the head value (`tail->next->data`) and the tail value (`tail->data`).

```
Output:
10 20 30
Head: 10
Tail: 30
```

### Exercise 15: Search in a Circular List

Write `bool search(Node* tail, int key)` and test it on the list `5 10 15 20` with a key that exists and a key that does not. Also test it on an empty list (`tail = nullptr`) to confirm it does not crash.

```
Input : list = 5 10 15 20, key = 15
Output: Found

Input : list = 5 10 15 20, key = 99
Output: Not Found
```

### Exercise 16: Delete and Check the Tail

Build the list `10 20 30 40`. Delete the value `40` (the tail) using `deleteByValue`, print the list, then insert `50` at the end and print again. This confirms `tail` was moved back correctly after the deletion.

```
After deleting 40: 10 20 30
After inserting 50: 10 20 30 50
```

### Exercise 17: Delete Until Empty

Build the list `10 20`. Call `deleteAtBeginning` three times, printing the list after each call. The third call must not crash.

```
Output:
20
Empty
Empty
```

### Exercise 18: Circular Doubly Linked List

Using the circular `DNode` list, build `10 20 30` with `insertAtEnd`. Print it forward and backward, then call `deleteAtEnd` and print it forward again.

```
Output:
Forward : 10 20 30
Backward: 30 20 10
After deleteAtEnd: 10 20
```

### Exercise 19: Round-Robin Turns (Application)

Build a circular list of `1 2 3` (three players). Starting from the head, print the player number for `7` turns by moving one node forward each turn. Do not stop at the end of the list; it should wrap around by itself.

```
Output: 1 2 3 1 2 3 1
```

*Hint: keep a pointer `cur = tail->next`, print `cur->data`, then set `cur = cur->next` inside a `for` loop that runs 7 times.*

---

## Self-Check

Before moving on to `Practice Problems.md`, make sure you can answer all of the following without looking anything up:

- Why does a linked list not need a fixed size the way an array does?
- What has to be updated when you insert or delete the very first node (`head`)?
- Why is `insertAtBeginning` O(1) but `insertAtEnd` O(n) in a plain singly linked list?
- In a doubly linked list, why do both `next` and `prev` need to be updated on every insert or delete?
- What happens if you call `->next` on a pointer that is `nullptr`?
- Why does a normal `while (temp != nullptr)` loop never stop in a circular linked list?
- Why do we use a `tail` pointer in a circular list, and why does it make insertion at both ends O(1)?
- What must a single node's `next` point to in a circular list, and what must you return when the last remaining node is deleted?

If any of these feel shaky, redo the matching exercise above before starting the practice problems.
