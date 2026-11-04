# Lab 7: Basic Lab Exercises

These exercises follow the topics in `Lab 7: Binary Search Tree and Heap.md`. Read that file first. Each task is small: write the code, compile it, run it, and compare your output with the sample. No online judge or submission is needed.

**Compile and run:**

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

**Starter code for Part A** (reuse it in every BST task):

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

Node* insert(Node* root, int value) {
    if (root == nullptr) return newNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}
```

For all BST tasks, use this tree unless told otherwise. Insert the values in this order: `50 30 70 20 40 60 80`

---

## Part A: Binary Search Tree

### Task 1: Build and Traverse

Insert the values into a BST. Write `inorder`, `preorder` and `postorder` functions and print all three.

```
Inorder:   20 30 40 50 60 70 80
Preorder:  50 30 20 40 70 60 80
Postorder: 20 40 30 60 80 70 50
```

Hint: inorder prints a BST in sorted order. If yours is not sorted, check your `insert`.

### Task 2: Search

Write `bool search(Node* root, int key)`. Read an integer `key` and print `Found` or `Not Found`.

```
Input:  60
Output: Found

Input:  65
Output: Not Found
```

### Task 3: Minimum, Maximum and Height

Write `findMin`, `findMax` and `height`. Print all three.

```
Min: 20
Max: 80
Height: 3
```

Hint: the minimum is the leftmost node and the maximum is the rightmost node. An empty tree has height 0.

### Task 4: Count Nodes and Leaves

Write a recursive function `countNodes` and another `countLeaves`. A leaf is a node whose `left` and `right` are both `nullptr`.

```
Total nodes: 7
Leaf nodes: 4
```

### Task 5: Deletion

Add `findMin` and `deleteNode` from the topic file. Delete the values below **one at a time** and print the inorder traversal after each deletion.

| Delete | Case | Expected inorder |
| --- | --- | --- |
| 20 | Leaf | `30 40 50 60 70 80` |
| 30 | One child | `40 50 60 70 80` |
| 50 | Two children (the root) | `40 60 70 80` |

---

## Part B: Heap

**Starter code for Part B** (max-heap stored in a `vector`):

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> heap;   // max-heap, 0-indexed
// parent = (i - 1) / 2, left = 2 * i + 1, right = 2 * i + 2
```

### Task 6: Heap Insertion

Write `insertHeap(int value)` using heapify up. Insert `30 90 50 70 20 80` in this order, then print the array.

```
Heap array: 90 70 80 30 20 50
```

Hint: add the value at the end, then swap with the parent while the parent is smaller.

### Task 7: Extract the Maximum

Add `heapifyDown` and `extractMax` to Task 6. Keep extracting until the heap is empty and print the values.

```
Extracted: 90 80 70 50 30 20
```

The output is in descending order. This is heap sort.

### Task 8: Min-Heap with `priority_queue`

Read `n`, then `n` integers. Store them in a min-heap using `priority_queue<int, vector<int>, greater<int>>` and print them by repeatedly taking `top()` and calling `pop()`.

```
Input:
5
40 10 30 50 20

Output:
10 20 30 40 50
```

---

## Challenge (Optional)

### Task 9: Is It a Max-Heap?

Given an array, check whether it follows the max-heap property. For every index `i` with a left child `2i + 1` (and right child `2i + 2`), the parent must be greater than or equal to the child.

```
Input:  90 70 80 30 20 50
Output: Yes

Input:  10 20 5
Output: No
```

Hint: loop `i` from 1 to `n - 1` and compare `a[i]` with its parent `a[(i - 1) / 2]`.
