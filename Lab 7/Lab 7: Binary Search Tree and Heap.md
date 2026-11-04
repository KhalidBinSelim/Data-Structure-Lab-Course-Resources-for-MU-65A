# Lab 7: Binary Search Tree and Heap

This document explains the topics of Lab 7. Read it before, during and after the lab session, then move on to `Basic Lab Exercises.md`.

**Compile and run:**

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

---

## Table of Contents

1. [Introduction to Binary Search Tree](#1-introduction-to-binary-search-tree)
2. [BST Operations](#2-bst-operations)
3. [Heap](#3-heap)
4. [Quick Summary](#4-quick-summary)

---

## 1. Introduction to Binary Search Tree

### 1.1 What is a Binary Tree?

A **binary tree** is a data structure where every node can have **at most two children**: a **left child** and a **right child**. The first node is called the **root**. A node with no children is called a **leaf**.

```
        50          <- root
       /  \
     30    70
    / \   /  \
  20  40 60  80     <- leaves: 20, 40, 60, 80
```

### 1.2 What is a Binary Search Tree (BST)?

A **Binary Search Tree** is a binary tree with one simple rule for every node:

- All values in the **left** subtree are **smaller** than the node.
- All values in the **right** subtree are **larger** than the node.

The tree above is a BST. Because of this rule, we can search quickly: at each node, go left if the key is smaller, go right if it is larger.

### 1.3 Node Structure

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    Node* root = newNode(50);        // create the root manually
    root->left = newNode(30);
    root->right = newNode(70);

    cout << root->left->data << "\n";   // 30
    return 0;
}
```

`root` is a pointer to the top node. If the tree is empty, `root` is `nullptr`.

---

## 2. BST Operations

All operations below use the same `Node` structure and `newNode()` function from Section 1.3. Most of them are **recursive**: each function solves the problem for one node, then calls itself on the left or right child.

### 2.1 Insertion

Go left if the value is smaller, go right if it is larger, and place the new node where you reach `nullptr`. Time: O(h), where h is the height of the tree.

```cpp
Node* insert(Node* root, int value) {
    if (root == nullptr) return newNode(value);   // found the empty spot

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;   // duplicates are ignored
}
```

### 2.2 Searching

Same path as insertion, but we stop when we find the value.

```cpp
bool search(Node* root, int key) {
    if (root == nullptr) return false;       // reached the end, not found
    if (root->data == key) return true;

    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}
```

### 2.3 Traversals

A traversal visits every node once. There are three common orders:

| Traversal | Order | Use |
| --- | --- | --- |
| Inorder | Left, Node, Right | Prints a BST in **sorted order** |
| Preorder | Node, Left, Right | Copying a tree |
| Postorder | Left, Right, Node | Deleting a tree |

```cpp
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```

For the tree in Section 1.1: inorder = `20 30 40 50 60 70 80`, preorder = `50 30 20 40 70 60 80`, postorder = `20 40 30 60 80 70 50`.

### 2.4 Minimum, Maximum and Height

The smallest value is the **leftmost** node. The largest value is the **rightmost** node.

```cpp
Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root != nullptr && root->right != nullptr)
        root = root->right;
    return root;
}

int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

### 2.5 Deletion

There are three cases when deleting a node:

1. **Leaf node:** just remove it.
2. **One child:** replace the node with its child.
3. **Two children:** replace the node's value with its **inorder successor** (the smallest value in the right subtree), then delete that successor.

```cpp
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // found the node to delete
        if (root->left == nullptr) {            // case 1 and case 2 (no left child)
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {           // case 2 (no right child)
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* succ = findMin(root->right);      // case 3: two children
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}
```

**Full working example:**

```cpp
int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = insert(root, v);

    inorder(root);   cout << "\n";          // 20 30 40 50 60 70 80
    cout << search(root, 60) << "\n";       // 1 (found)
    cout << findMin(root)->data << "\n";    // 20
    cout << height(root) << "\n";           // 3

    root = deleteNode(root, 30);            // node with two children
    inorder(root);   cout << "\n";          // 20 40 50 60 70 80
    return 0;
}
```

If values are inserted in sorted order (1, 2, 3, ...), the BST becomes a long chain and operations slow down to O(n). A balanced BST keeps h about log n.

---

## 3. Heap

### 3.1 What is a Heap?

A **heap** is a **complete binary tree** (every level is full except possibly the last, which is filled from left to right) that follows the **heap property**:

- **Max-heap:** every parent is **greater than or equal to** its children, so the largest value is at the root.
- **Min-heap:** every parent is **less than or equal to** its children, so the smallest value is at the root.

```
Max-heap:          90
                  /  \
                70    80
               / \   /
             30  50 20
```

A heap is **not** fully sorted. It only guarantees that the top element is the largest (or smallest). This makes it perfect for a **priority queue**.

### 3.2 Heap in an Array

Because a heap is a complete tree, we store it in a plain array with no pointers. For a node at index `i` (0-indexed):

| Relation | Index |
| --- | --- |
| Parent | `(i - 1) / 2` |
| Left child | `2 * i + 1` |
| Right child | `2 * i + 2` |

The max-heap above is stored as: `[90, 70, 80, 30, 50, 20]`.

### 3.3 Insertion (Heapify Up)

Add the new value at the **end** of the array, then keep swapping it with its parent while it is larger than the parent. Time: O(log n).

```cpp
vector<int> heap;   // max-heap

void insertHeap(int value) {
    heap.push_back(value);
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}
```

### 3.4 Deletion of the Root (Heapify Down)

To remove the maximum: move the **last** element to the root, shrink the array, then keep swapping it with its **larger child** until the heap property holds again. Time: O(log n).

```cpp
void heapifyDown(int i) {
    int n = heap.size();
    while (true) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;           // heap property restored
        swap(heap[i], heap[largest]);
        i = largest;
    }
}

int extractMax() {
    int top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) heapifyDown(0);
    return top;
}
```

Always check `heap.empty()` before calling `extractMax()`.

### 3.5 Heap Sort Idea

Keep calling `extractMax()` and you get the values in **descending order**. Doing this for n elements costs O(n log n). This is the idea behind heap sort.

### 3.6 STL `priority_queue`

C++ already provides a heap. By default it is a **max-heap**.

```cpp
priority_queue<int> maxPQ;                              // max-heap
priority_queue<int, vector<int>, greater<int>> minPQ;   // min-heap

maxPQ.push(30); maxPQ.push(90); maxPQ.push(50);
cout << maxPQ.top() << "\n";   // 90
maxPQ.pop();                   // removes 90
cout << maxPQ.size() << "\n";  // 2
```

**Full working example (our own heap):**

```cpp
int main() {
    int values[] = {30, 90, 50, 70, 20, 80};
    for (int v : values) insertHeap(v);

    cout << heap[0] << "\n";           // 90 (the maximum)

    while (!heap.empty())
        cout << extractMax() << " ";   // 90 80 70 50 30 20
    cout << "\n";
    return 0;
}
```

---

## 4. Quick Summary

| Topic | Key Idea | Time |
| --- | --- | --- |
| BST rule | Left subtree < node < right subtree | : |
| BST insert / search / delete | Follow left or right at each node | O(h) |
| Inorder traversal | Gives sorted output for a BST | O(n) |
| Min / Max in BST | Leftmost / rightmost node | O(h) |
| Heap | Complete binary tree with the heap property, stored in an array | : |
| Heap insert / extract root | Heapify up / heapify down | O(log n) |
| Peek top of heap | Look at index 0 | O(1) |
| `priority_queue` | Built-in max-heap (use `greater<int>` for min-heap) | O(log n) push/pop |

**BST vs Heap:** a BST keeps **everything ordered** (good for search), while a heap only keeps the **top element** easy to reach (good for priority queues).

**Common mistakes**

- Forgetting to return `root` from `insert` / `deleteNode`, or forgetting to assign it back (`root->left = insert(...)`).
- Dereferencing a `nullptr` child (e.g. `root->left->data`) without checking first.
- Forgetting the three deletion cases, especially a node with two children.
- Mixing up the heap index formulas (0-indexed: children are `2i+1` and `2i+2`).
- Calling `extractMax()` or `top()` on an empty heap.
