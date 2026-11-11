# Lab 7: Basic Lab Exercises Solutions

Solutions for `Basic Lab Exercises.md`. Try each task yourself first, then compare. There are many correct ways to write these.

**Compile and run:**

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

**Starter code for Tasks 1 to 5.** Put this at the top of the file, above the code shown in each task:

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

---

## Part A: Binary Search Tree

### Task 1: Build and Traverse

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

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = insert(root, v);

    cout << "Inorder:   "; inorder(root);   cout << "\n";
    cout << "Preorder:  "; preorder(root);  cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n";
    return 0;
}
```

**Output:**

```
Inorder:   20 30 40 50 60 70 80 
Preorder:  50 30 20 40 70 60 80 
Postorder: 20 40 30 60 80 70 50 
```

### Task 2: Search

```cpp
bool search(Node* root, int key) {
    if (root == nullptr) return false;       // reached the end, not found
    if (root->data == key) return true;

    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = insert(root, v);

    int key;
    cin >> key;
    if (search(root, key)) cout << "Found\n";
    else cout << "Not Found\n";
    return 0;
}
```

**Output:** input `60` gives `Found`, input `65` gives `Not Found`.

### Task 3: Minimum, Maximum and Height

```cpp
Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr)
        root = root->left;               // keep going left
    return root;
}

Node* findMax(Node* root) {
    while (root != nullptr && root->right != nullptr)
        root = root->right;              // keep going right
    return root;
}

int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = insert(root, v);

    cout << "Min: " << findMin(root)->data << "\n";
    cout << "Max: " << findMax(root)->data << "\n";
    cout << "Height: " << height(root) << "\n";
    return 0;
}
```

**Output:**

```
Min: 20
Max: 80
Height: 3
```

### Task 4: Count Nodes and Leaves

```cpp
int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;   // a leaf
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = insert(root, v);

    cout << "Total nodes: " << countNodes(root) << "\n";
    cout << "Leaf nodes: " << countLeaves(root) << "\n";
    return 0;
}
```

**Output:**

```
Total nodes: 7
Leaf nodes: 4
```

### Task 5: Deletion

```cpp
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {            // leaf, or only a right child
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {           // only a left child
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* succ = findMin(root->right);      // two children: use inorder successor
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = insert(root, v);

    int toDelete[] = {20, 30, 50};
    for (int d : toDelete) {
        root = deleteNode(root, d);
        inorder(root);
        cout << "\n";
    }
    return 0;
}
```

**Output:**

```
30 40 50 60 70 80 
40 50 60 70 80 
40 60 70 80 
```

Why it works: deleting `20` is a leaf. After that, `30` has only the child `40`. Finally `50` is the root with two children, so it is replaced by its inorder successor `60`.

---

## Part B: Heap

### Task 6: Heap Insertion

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> heap;   // max-heap, 0-indexed

void insertHeap(int value) {
    heap.push_back(value);                       // add at the end
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);        // move up while larger than parent
        i = (i - 1) / 2;
    }
}

int main() {
    int values[] = {30, 90, 50, 70, 20, 80};
    for (int v : values) insertHeap(v);

    cout << "Heap array: ";
    for (int x : heap) cout << x << " ";
    cout << "\n";
    return 0;
}
```

**Output:**

```
Heap array: 90 70 80 30 20 50 
```

### Task 7: Extract the Maximum

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> heap;   // max-heap, 0-indexed

void insertHeap(int value) {
    heap.push_back(value);
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int n = heap.size();
    while (true) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;                 // heap property restored
        swap(heap[i], heap[largest]);
        i = largest;
    }
}

int extractMax() {
    int top = heap[0];
    heap[0] = heap.back();                       // move the last element to the root
    heap.pop_back();
    if (!heap.empty()) heapifyDown(0);
    return top;
}

int main() {
    int values[] = {30, 90, 50, 70, 20, 80};
    for (int v : values) insertHeap(v);

    cout << "Extracted: ";
    while (!heap.empty()) cout << extractMax() << " ";
    cout << "\n";
    return 0;
}
```

**Output:**

```
Extracted: 90 80 70 50 30 20 
```

### Task 8: Min-Heap with `priority_queue`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minPQ;   // min-heap
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minPQ.push(x);
    }

    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << "\n";
    return 0;
}
```

**Output:** input `5` then `40 10 30 50 20` gives `10 20 30 40 50`.

---

## Challenge (Optional)

### Task 9: Is It a Max-Heap?

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;
    int x;
    while (cin >> x) a.push_back(x);

    bool ok = true;
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[(i - 1) / 2] < a[i]) {     // parent must be >= child
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << "\n";
    return 0;
}
```

**Output:** input `90 70 80 30 20 50` gives `Yes`, input `10 20 5` gives `No`.

Checking every index from 1 against its parent covers every parent-child pair, because each node except the root has exactly one parent.
