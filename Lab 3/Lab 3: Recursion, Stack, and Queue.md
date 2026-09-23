# Lab 3: Recursion, Stack and Queue

This document explains the three topics of Lab 3 with simple, formal descriptions and runnable C++ code. Read it before, during and after the lab session, then move on to `Basic Lab Exercises.md`.

**Compile and run:**

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

---

## Table of Contents

1. [Recursion](#1-recursion)
2. [Stack](#2-stack)
3. [Queue](#3-queue)
4. [Quick Summary](#4-quick-summary)

---

## 1. Recursion

### 1.1 What is Recursion?

**Recursion** is a technique where a function calls **itself** to solve a smaller version of the same problem. Every recursive function needs two parts:

| Part | Meaning |
| --- | --- |
| **Base case** | The simplest input, answered directly. It stops the recursion. |
| **Recursive case** | The function calls itself with a smaller input, moving toward the base case. |

> Without a base case, the function calls itself forever and the program crashes with a **stack overflow**.

### 1.2 Example: Factorial

`n! = n × (n-1)!` and `0! = 1`.

```cpp
#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    if (n == 0) return 1;          // base case
    return n * factorial(n - 1);   // recursive case
}

int main() {
    cout << factorial(5) << "\n";  // 120
    return 0;
}
```

**Trace of `factorial(3)`:**

```
factorial(3) = 3 * factorial(2)
                   factorial(2) = 2 * factorial(1)
                                      factorial(1) = 1 * factorial(0)
                                                         factorial(0) = 1
factorial(1) = 1 * 1 = 1
factorial(2) = 2 * 1 = 2
factorial(3) = 3 * 2 = 6
```

### 1.3 How the Call Stack Works

Each function call is stored in the **call stack**. A call is pushed when the function starts and popped when it returns. The code below shows both phases: going **down** (calls) and coming **back** (returns).

```cpp
#include <bits/stdc++.h>
using namespace std;

void demo(int n) {
    if (n == 0) return;                         // base case
    cout << "Going down : " << n << "\n";       // runs BEFORE the recursive call
    demo(n - 1);
    cout << "Coming back: " << n << "\n";       // runs AFTER the recursive call
}

int main() {
    demo(3);
    return 0;
}
```

**Output:**

```
Going down : 3
Going down : 2
Going down : 1
Coming back: 1
Coming back: 2
Coming back: 3
```

### 1.4 Example: Fibonacci

`F(0) = 0`, `F(1) = 1`, `F(n) = F(n-1) + F(n-2)`.

```cpp
#include <bits/stdc++.h>
using namespace std;

// Plain recursion: simple, but slow (repeats the same work). Time: O(2^n)
int fib(int n) {
    if (n <= 1) return n;                       // base cases
    return fib(n - 1) + fib(n - 2);
}

// Recursion + memoization: each value is computed once. Time: O(n)
long long memo[100];
long long fibMemo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];          // already computed
    return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

int main() {
    memset(memo, -1, sizeof(memo));
    cout << fib(10) << "\n";        // 55
    cout << fibMemo(50) << "\n";    // 12586269025
    return 0;
}
```

### 1.5 Example: Fast Power

Halve the exponent each time: `x^n = (x^(n/2))^2`, times `x` when `n` is odd. Time: **O(log n)**.

```cpp
#include <bits/stdc++.h>
using namespace std;

long long power(long long x, int n) {
    if (n == 0) return 1;                       // base case
    long long half = power(x, n / 2);
    if (n % 2 == 0) return half * half;
    return half * half * x;
}

int main() {
    cout << power(2, 10) << "\n";   // 1024
    return 0;
}
```

### 1.6 Example: Tower of Hanoi

Move `n` disks from rod `A` to rod `C` using rod `B`. Only one disk moves at a time, and a larger disk never sits on a smaller one. Total moves: `2^n - 1`.

```cpp
#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char to, char via) {
    if (n == 0) return;                                     // base case
    hanoi(n - 1, from, via, to);                            // 1. move n-1 disks out of the way
    cout << "Move disk " << n << " from " << from << " to " << to << "\n";
    hanoi(n - 1, via, to, from);                            // 2. move n-1 disks onto the big one
}

int main() {
    hanoi(3, 'A', 'C', 'B');        // prints 7 moves
    return 0;
}
```

### 1.7 Recursion vs Iteration

| | Recursion | Iteration (loops) |
| --- | --- | --- |
| Code | Short, close to the problem definition | Longer, more explicit |
| Memory | Uses call stack (`O(depth)`) | Usually `O(1)` |
| Risk | Stack overflow if too deep or no base case | Infinite loop if the condition is wrong |
| Best for | Trees, divide and conquer, backtracking | Simple repetition |

---

## 2. Stack

### 2.1 What is a Stack?

A **stack** is a linear data structure that follows **LIFO** (Last In, First Out): the element added last is removed first. Think of a pile of plates. All operations happen at one end, called the **top**.

```
      push(30)          top -> | 30 |
      push(20)                 | 20 |
      push(10)                 | 10 |
                               ------
```

| Operation | Description | Time |
| --- | --- | --- |
| `push(x)` | Insert `x` on top | O(1) |
| `pop()` | Remove the top element | O(1) |
| `top()` | Read the top element | O(1) |
| `isEmpty()` | Check whether the stack is empty | O(1) |
| `isFull()` | Check whether the stack is full (array version) | O(1) |

> **Overflow** = push on a full stack. **Underflow** = pop on an empty stack.

### 2.2 Stack Using an Array

```cpp
#include <bits/stdc++.h>
using namespace std;

class Stack {
    static const int MAX = 100;
    int arr[MAX];
    int topIdx;                                   // index of the top element

public:
    Stack() : topIdx(-1) {}                       // -1 means empty

    bool isEmpty() const { return topIdx == -1; }
    bool isFull()  const { return topIdx == MAX - 1; }
    int  size()    const { return topIdx + 1; }

    void push(int x) {
        if (isFull()) { cout << "Stack Overflow\n"; return; }
        arr[++topIdx] = x;
    }

    void pop() {
        if (isEmpty()) { cout << "Stack Underflow\n"; return; }
        topIdx--;
    }

    int top() const {
        if (isEmpty()) { cout << "Stack is empty\n"; return -1; }
        return arr[topIdx];
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << "\n";       // 30
    s.pop();
    cout << "Top: " << s.top() << "\n";       // 20
    cout << "Size: " << s.size() << "\n";     // 2
    return 0;
}
```

### 2.3 Stack Using STL

In practice, use `std::stack` from `<stack>`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << "\n";                  // 30
    s.pop();
    cout << s.top() << "\n";                  // 20
    cout << s.size() << "\n";                 // 2
    cout << (s.empty() ? "Empty" : "Not empty") << "\n";

    // Print all elements (this empties the stack)
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";                             // 20 10
    return 0;
}
```

> Calling `top()` or `pop()` on an empty `std::stack` is undefined behavior. Always check `empty()` first.

### 2.4 Application: Balanced Parentheses

A string like `{[()]}` is balanced if every opening bracket is closed by the correct type in the correct order. Push openers; on a closer, the top must be its matching opener.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string &str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;                 // nothing to match
            char open = st.top();
            st.pop();
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) return false;  // wrong type
        }
    }
    return st.empty();                                    // leftovers = unbalanced
}

int main() {
    cout << (isBalanced("{[()]}") ? "Balanced" : "Not Balanced") << "\n";   // Balanced
    cout << (isBalanced("{[(])}") ? "Balanced" : "Not Balanced") << "\n";   // Not Balanced
    return 0;
}
```

**Other applications:** undo/redo, browser back button, reversing data, postfix expression evaluation, and the function call stack itself (Section 1.3).

---

## 3. Queue

### 3.1 What is a Queue?

A **queue** is a linear data structure that follows **FIFO** (First In, First Out): the element added first is removed first. Think of a line at a ticket counter. Insertion happens at the **rear** and removal at the **front**.

```
   dequeue <- [ 10 | 20 | 30 | 40 ] <- enqueue
              front            rear
```

| Operation | Description | Time |
| --- | --- | --- |
| `enqueue(x)` | Insert `x` at the rear | O(1) |
| `dequeue()` | Remove the front element | O(1) |
| `front()` | Read the front element | O(1) |
| `isEmpty()` | Check whether the queue is empty | O(1) |
| `isFull()` | Check whether the queue is full (array version) | O(1) |

### 3.2 Circular Queue Using an Array

With a plain array queue, the `front` index only moves forward, so freed slots at the start are wasted. A **circular queue** fixes this by wrapping the indexes around using `% MAX`.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Queue {
    static const int MAX = 5;
    int arr[MAX];
    int frontIdx, rearIdx, count;

public:
    Queue() : frontIdx(0), rearIdx(-1), count(0) {}

    bool isEmpty() const { return count == 0; }
    bool isFull()  const { return count == MAX; }
    int  size()    const { return count; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow\n"; return; }
        rearIdx = (rearIdx + 1) % MAX;            // wrap around
        arr[rearIdx] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return; }
        frontIdx = (frontIdx + 1) % MAX;          // wrap around
        count--;
    }

    int front() const {
        if (isEmpty()) { cout << "Queue is empty\n"; return -1; }
        return arr[frontIdx];
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 5; i++) q.enqueue(i * 10);   // 10 20 30 40 50
    q.enqueue(60);                                    // Queue Overflow
    q.dequeue();                                      // removes 10
    q.enqueue(60);                                    // reuses the freed slot
    cout << "Front: " << q.front() << "\n";           // 20
    cout << "Size : " << q.size() << "\n";            // 5
    return 0;
}
```

### 3.3 Queue Using STL

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << "\n";                // 10
    cout << q.back()  << "\n";                // 30
    q.pop();
    cout << q.front() << "\n";                // 20
    cout << q.size()  << "\n";                // 2

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";                             // 20 30
    return 0;
}
```

> As with `std::stack`, calling `front()` or `pop()` on an empty `std::queue` is undefined behavior.

### 3.4 Deque (Double-Ended Queue)

A **deque** allows insertion and removal at **both** ends in O(1). It can work as a stack, a queue, or both.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(10);                        // 10 20 30

    cout << dq.front() << " " << dq.back() << "\n";   // 10 30
    dq.pop_front();                                   // 20 30
    dq.pop_back();                                    // 20
    cout << dq.size() << "\n";                        // 1
    return 0;
}
```

### 3.5 Application: Generate Binary Numbers from 1 to N

Start with `"1"`. Repeatedly take the front string `s`, print it, and enqueue `s + "0"` and `s + "1"`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    queue<string> q;
    q.push("1");

    for (int i = 0; i < n; i++) {
        string s = q.front();
        q.pop();
        cout << s << " ";
        q.push(s + "0");
        q.push(s + "1");
    }
    cout << "\n";                             // 1 10 11 100 101
    return 0;
}
```

**Other applications:** CPU and printer scheduling, BFS in graphs and trees, buffering data streams.

---

## 4. Quick Summary

| Topic | Key Idea | Order | Main Operations |
| --- | --- | --- | --- |
| Recursion | Function calls itself on a smaller input | Uses the call stack | Base case + recursive case |
| Stack | One open end (top) | **LIFO** | `push`, `pop`, `top` |
| Queue | Two open ends (front, rear) | **FIFO** | `enqueue`, `dequeue`, `front` |

**Common mistakes**

- Forgetting the base case, or not moving toward it (stack overflow).
- Using `top()` / `front()` / `pop()` on an empty container.
- Forgetting `% MAX` in a circular queue, so the indexes never wrap.
- Using naive recursive Fibonacci for large `n` (exponential time).
