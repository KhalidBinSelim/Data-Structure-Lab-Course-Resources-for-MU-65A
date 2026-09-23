# Lab 3: Basic Lab Exercises

**Topics:** Recursion, Stack, Queue

These exercises are short and self-contained. Read `Lab 3: Recursion, Stack and Queue.md` first, then write each program yourself in C++, compile it, and run it against the sample input to confirm you understood the concept. No online judge, account, or submission is needed.

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

**Rules**

- Exercises 1 to 6 must use **recursion** (no loops for the main logic).
- Exercises 7 to 10 must use a **stack**; Exercises 11 to 14 must use a **queue**. You may use STL unless the exercise says to implement it yourself.
- Handle empty cases (underflow) safely; never call `top()`, `front()`, or `pop()` on an empty container.

---

## Part A: Recursion

### Exercise 1: Print 1 to N

Read an integer `N` and print the numbers from `1` to `N` using recursion.

```
Input : 5
Output: 1 2 3 4 5
```

*Hint: print after the recursive call.*

### Exercise 2: Sum of First N Natural Numbers

Write a recursive function `sum(n)` that returns `1 + 2 + ... + n`.

```
Input : 10
Output: 55
```

### Exercise 3: Nth Fibonacci Number

Write a recursive function that returns the `n`-th Fibonacci number, where `F(0) = 0` and `F(1) = 1`. Then improve it with memoization and compare the speed for `n = 45`.

```
Input : 7
Output: 13
```

### Exercise 4: Reverse a String

Reverse a string using recursion (do not use `reverse()` or a loop).

```
Input : hello
Output: olleh
```

### Exercise 5: Palindrome Check

Write a recursive function that checks whether a string is a palindrome.

```
Input : madam
Output: Yes

Input : lab
Output: No
```

### Exercise 6: Tower of Hanoi

Read the number of disks `n`. Print every move for rods `A`, `B`, `C` and the total number of moves.

```
Input : 3
Output:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Total moves: 7
```

---

## Part B: Stack

### Exercise 7: Implement a Stack

Implement an array-based stack class with `push`, `pop`, `top`, `isEmpty`, `isFull`, and `size`. In `main`, perform: push 10, 20, 30; print top; pop; print top; print size. Print `Stack Overflow` / `Stack Underflow` when needed.

```
Output:
Top: 30
Top after pop: 20
Size: 2
```

### Exercise 8: Reverse a String Using a Stack

Read a string, push every character onto a stack, then pop them to build the reversed string.

```
Input : DATA
Output: ATAD
```

### Exercise 9: Balanced Parentheses

Read a string containing `(`, `)`, `{`, `}`, `[`, `]` and print whether it is balanced.

```
Input : {[()]}
Output: Balanced

Input : {[(])}
Output: Not Balanced
```

### Exercise 10: Decimal to Binary

Convert a positive decimal number to binary using a stack.

```
Input : 13
Output: 1101
```

*Hint: push each remainder of `n % 2`, then pop them all.*

---

## Part C: Queue

### Exercise 11: Implement a Circular Queue

Implement an array-based circular queue of capacity `3` with `enqueue`, `dequeue`, `front`, `isEmpty`, `isFull`, and `size`. In `main`, perform: enqueue 10, 20, 30; enqueue 40; dequeue; enqueue 40; then print all elements from front to rear.

```
Output:
Queue Overflow
20 30 40
```

### Exercise 12: FIFO Order with STL Queue

Read `N` and then `N` integers. Push them into a `queue<int>`, then dequeue and print them all, followed by the sum.

```
Input :
5
3 1 4 1 5

Output:
3 1 4 1 5
Sum: 14
```

### Exercise 13: Binary Numbers from 1 to N

Print the binary representation of every number from `1` to `N` using a queue of strings.

```
Input : 5
Output: 1 10 11 100 101
```

### Exercise 14: Reverse a Queue

Read `N` and `N` integers into a queue. Reverse the queue using a stack and print it.

```
Input :
5
1 2 3 4 5

Output: 5 4 3 2 1
```

---
