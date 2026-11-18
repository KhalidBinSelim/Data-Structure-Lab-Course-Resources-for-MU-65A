# Lab 1: Basic Lab Exercises

These exercises are meant to be done **before** you move on to `Practice Problems.md`. They are not judge problems : there are no links, no judges, no submissions. Each one targets a single concept from `Lab 1: C++ Foundations for Data Structures.md` so you can build muscle memory on the fundamentals before combining them into larger problems.

Work through them in order. For each exercise:

1. Write the code yourself first, without looking back at the `Lab 1: C++ Foundations for Data Structures.md`.
2. Compile and run it.
3. Where an exercise asks you to **predict the output**, write down your prediction on paper *before* running the code, then compare.

---

## Table of Contents

1. [Basic Program Structure](#1-basic-program-structure)
2. [Header Files and `std::`](#2-header-files-and-std)
3. [Custom Header Files](#3-custom-header-files)
4. [`using namespace std`](#4-using-namespace-std)
5. [`#include <bits/stdc++.h>`](#5-include-bitsstdch)
6. [Macros](#6-macros)
7. [Arrays](#7-arrays)
8. [Strings](#8-strings)
9. [Whitespace and Input Handling](#9-whitespace-and-input-handling)
10. [`cin >> int` vs `cin >> string`](#10-cin--int-vs-cin--string)
11. [`cin >> char` vs `getchar()`](#11-cin--char-vs-getchar)
12. [`getline()`](#12-getline)
13. [`cin.ignore()`](#13-cinignore)
14. [File I/O, EOF, and Garbage Values](#14-file-io-eof-and-garbage-values)
15. [Integer Overflow](#15-integer-overflow)
16. [Pointers and References](#16-pointers-and-references)

---

## 1. Basic Program Structure

**Exercise 1.1 : Compile and run** <br>
Write a program that prints your name, your student ID, and the current lab number (`Lab 1`) on three separate lines. Compile it with `g++ -std=c++17` from the terminal instead of an IDE's "Run" button, so you get comfortable with the command line.

**Exercise 1.2 : Find the bug** <br>
The following code fails to compile. Identify and fix every mistake without rewriting it from scratch:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, Lab 1!" << std::endl
    return 0
}
```

**Exercise 1.3 : Exit codes** <br>
Modify your Exercise 1.1 program so that it returns `1` instead of `0` from `main()`. Run it, then run `echo $?` (Linux/macOS) or `echo %errorlevel%` (Windows) immediately after to see the exit code your program produced. Explain in one sentence, as a comment at the top of the file, what a non-zero return value conventionally signals.

---

## 2. Header Files and `std::` <br>

**Exercise 2.1 : Fully qualified names** <br>
Write a program that declares a variable named `cin` (yes, shadowing the real one) and still manages to correctly print a message using the real `std::cin` object to read a number from the user. This forces you to use `std::` explicitly rather than relying on `using namespace std;`.

**Exercise 2.2 : Predict the output** <br>
Without running it, write down what you think this program prints, then compile and check:

```cpp
#include <iostream>

int main() {
    int cout = 42;
    std::cout << "cout variable holds: " << cout << std::endl;
    return 0;
}
```

**Exercise 2.3 : Missing header** <br>
Remove the `#include <iostream>` line from any working program that uses `std::cout`. Try to compile it. Copy the compiler error message into a comment above `main()`, and write one sentence explaining, in your own words, why the compiler could not find `cout`.

---

## 3. Custom Header Files

**Exercise 3.1 : Build your own header** <br>
Create a header file `stringutils.h` declaring two functions: `bool isVowel(char c);` and `int countVowels(const std::string& s);`. Implement them in `stringutils.cpp`, then call both from `main.cpp` to count the vowels in a sentence the user types in. Compile all three files together in a single `g++` command.

**Exercise 3.2 : Break and fix an include guard** <br>
Take the header you wrote in Exercise 3.1, remove its include guard (`#ifndef` / `#define` / `#endif`), and then deliberately `#include "stringutils.h"` twice inside `main.cpp`. Record the compiler error, then restore the include guard and confirm the error disappears.

---

## 4. `using namespace std`

**Exercise 4.1 : Rewrite without it** <br>
Take any program you wrote earlier in this lab that uses `using namespace std;`, and rewrite it to use full `std::` qualification everywhere instead, with no `using` declaration at all. Confirm it still compiles and behaves identically.

**Exercise 4.2 : Selective `using`** <br>
Rewrite the same program again, but this time use `using std::cout;` and `using std::endl;` only (no `using namespace std;` and no full `std::` prefix on `cout`/`endl`). Note what happens if you try to use `cin` without qualifying it or bringing it in : does it compile?

---

## 5. `#include <bits/stdc++.h>`

**Exercise 5.1 : Swap it out** <br>
Take a program that uses `#include <bits/stdc++.h>` along with `vector`, `sort`, and `string`. Replace that single include with the exact set of individual standard headers it actually needs (`<iostream>`, `<vector>`, `<algorithm>`, `<string>`, etc.), and confirm it still compiles and runs identically.

**Exercise 5.2 : Compile time comparison** <br>
Using the `time` command (`time g++ -std=c++17 file.cpp -o file`), compare the compilation time of the same program using `<bits/stdc++.h>` versus using only the specific headers it needs. Write the two times down as a comment in your file.

---

## 6. Macros

**Exercise 6.1 : Fix the missing parentheses** <br>
The following macro is broken. Predict what `CUBE(2 + 1)` expands to and prints with the buggy version, then fix the macro so it works correctly for any expression:

```cpp
#define CUBE(x) x * x * x

int main() {
    std::cout << CUBE(2 + 1) << std::endl; // what does this print, and what SHOULD it print?
}
```

**Exercise 6.2 : Write your own macros** <br>
Write function-like macros `MIN(a, b)` and `MAX(a, b)` that correctly return the smaller/larger of two values, with all necessary parentheses. Test each with at least one case involving an expression argument (like `MIN(x + 1, y - 2)`) to confirm your parenthesization is correct.

**Exercise 6.3 : Object-like macro constants** <br>
Define `#define MAX_STUDENTS 60`, declare an array of that size, and write a loop that fills it with roll numbers `1` to `MAX_STUDENTS`. Change only the macro value to `30` and confirm the rest of the program adapts automatically without further edits.

---

## 7. Arrays

**Exercise 7.1 : Input, sum, and average** <br>
Read `n` integers into an array, then print their sum and their average (as a `double`, with two decimal places using `cout << fixed << setprecision(2)`).

**Exercise 7.2 : Find the maximum and its index** <br>
Read `n` integers into an array. Without using any built-in `max_element` function, find and print both the maximum value and the index at which it first occurs.

**Exercise 7.3 : Reverse in place** <br>
Read `n` integers into an array and reverse it in place using the two-pointer technique (no second array allowed). Print the array before and after reversing.

**Exercise 7.4 : Deliberate out-of-bounds (then fix it)** <br>
Write a small program that deliberately reads `arr[n]` from an array of size `n` (one past the end) and prints it. Run it a few times and note whether the printed value changes between runs. Then fix the program so it only ever accesses valid indices.

**Exercise 7.5 : 2D array** <br>
Read a `3x3` grid of integers into a 2D array, then print the sum of each row and the sum of each column, each on its own line.

---

## 8. Strings

**Exercise 8.1 : Length and reverse** <br>
Read a single word (no spaces) with `cin >> s`, print its length, then print it reversed using `reverse()` from `<algorithm>`.

**Exercise 8.2 : Manual reverse** <br>
Repeat Exercise 8.1, but reverse the string manually with the two-pointer technique instead of using `reverse()`.

**Exercise 8.3 : Count vowels and consonants** <br>
Read a full sentence with `getline`, then count and print the number of vowels and the number of consonants in it (ignore spaces and punctuation).

**Exercise 8.4 : Palindrome check** <br>
Read a single word and determine whether it is a palindrome (reads the same forwards and backwards), without using the built-in `reverse()` function.

---

## 9. Whitespace and Input Handling

**Exercise 9.1 : Predict the tokens** <br>
Given the input line `12   hello   world`, predict what three consecutive `cin >> x` calls (into an `int`, then two `string`s) will store in each variable. Write your predictions down, then verify by running the code.

**Exercise 9.2 : Whitespace visualizer** <br>
Write a program that reads characters one at a time with `cin.get(c)` until it hits end of input, and prints `[SPACE]`, `[TAB]`, `[NEWLINE]`, or the character itself for each one read, so you can visually see exactly where the whitespace is in a block of input text.

---

## 10. `cin >> int` vs `cin >> string`

**Exercise 10.1 : Type mismatch** <br>
Write a program that reads an `int` with `cin >> x`. Run it and deliberately type a word like `"hello"` instead of a number. Observe what value `x` ends up holding, and write one sentence explaining what happened to the stream's state.

**Exercise 10.2 : Mixed reads** <br>
Read three values in this order: an `int`, a `string`, and another `int`, from a single line of input like `5 apple 10`. Print all three back out, labeled, to confirm each was read into the correct variable.

---

## 11. `cin >> char` vs `getchar()`

**Exercise 11.1 : Compare side by side** <br>
Write two versions of the same tiny program: one that reads a single character using `cin >> c`, and one that reads it using `getchar()`. Feed both the input `" A"` (a leading space then the letter A) and observe the difference in what each stores.

**Exercise 11.2 : Read a full line character by character** <br>
Using a loop of `getchar()` calls, read and print every character of a line of input (including spaces) until you hit `'\n'`, printing each character surrounded by square brackets, e.g. `[H][e][l][l][o][ ][W]...`.

---

## 12. `getline()`

**Exercise 12.1 : Full name capture** <br>
Prompt the user for their full name and read it with `getline`, so that a name with a space in it (like `John Smith`) is captured completely in one variable. Print it back with a greeting.

**Exercise 12.2 : Line-by-line word count** <br>
Count Characters: Read three lines using getline() and print the number of characters in each line, including spaces.

---

## 13. `cin.ignore()`

**Exercise 13.1 : Reproduce the bug** <br>
Write a program that reads an `int` with `cin >> age`, then immediately calls `getline(cin, name)` with no `cin.ignore()` in between. Run it and confirm `name` comes out empty, exactly as described in the README.

**Exercise 13.2 : Fix it** <br>
Fix your Exercise 13.1 program by inserting the correct `cin.ignore(numeric_limits<streamsize>::max(), '\n');` call in the right place, and confirm `name` is now read correctly.

**Exercise 13.3 : Three-field form** <br>
Write a small "registration form" program that reads, in order: an integer age (`cin >>`), a full name with spaces (`getline`), and a one-word favorite programming language (`cin >>`). Get the ordering and any needed `cin.ignore()` calls right so all three fields come out correct.

---

## 14. File I/O, EOF, and Garbage Values

**Exercise 14.1 : Write then read** <br>
Write a program that writes the numbers `1` to `20` (one per line) to a file called `numbers.txt` using `ofstream`, then write a second program (or a second part of the same program) that reads them back with `ifstream` using `while (inFile >> x)` and prints their sum.

**Exercise 14.2 : The `eof()` trap** <br>
Rewrite your reading loop from Exercise 14.1 to use `while (!inFile.eof())` instead of `while (inFile >> x)`. Compare the sum this version produces to the correct sum from Exercise 14.1, and explain in a comment why they differ.

**Exercise 14.3 : Observe a garbage value** <br>
Declare an uninitialized `int` and print it immediately, before assigning it any value, in a plain program with no other variables declared before it. Run the program two or three times (recompiling in between if needed) and note whether the printed value is consistent or not.

---

## 15. Integer Overflow

**Exercise 15.1 : Reproduce the overflow** <br>
Type in the exact example program from Section 15 of the README (the `a * b` vs `1LL * a * b` example), compile it, and run it. Confirm you see the same overflowed value for `product1` that the README shows.

**Exercise 15.2 : Find your own overflow** <br>
Write a program that reads two integers `a` and `b` from the user and prints `a * b` using a plain `int` for the result. Find and write down two specific input values that cause the printed result to be visibly wrong (negative when it should be positive, or a small number when the true product is huge).

**Exercise 15.3 : Fix it three ways** <br>
Fix your Exercise 15.2 program using three different approaches, one at a time, confirming each works: (1) declare both `a` and `b` as `long long` from the start, (2) keep `a` and `b` as `int` but cast one of them with `(long long)` inside the multiplication, (3) multiply by `1LL` first as shown in the README.

---

## 16. Pointers and References

**Exercise 16.1 : Basic pointer practice** <br>
Declare an `int`, a pointer to it, and print: the variable's value, its address, the pointer's stored value, and the dereferenced value through the pointer. Then change the variable's value *through the pointer* and print the variable again to confirm it changed.

**Exercise 16.2 : Null pointer safety** <br>
Write a function that takes an `int*` parameter. Inside the function, check whether the pointer is `nullptr` before dereferencing it; if it is null, print a message instead of crashing. Call the function twice: once with a valid address, once with `nullptr`.

**Exercise 16.3 : Pointer arithmetic on an array** <br>
Read `n` integers into an array, then print every element using only pointer arithmetic (`*(p + i)`) : no `arr[i]` syntax allowed anywhere in the printing loop.

**Exercise 16.4 : References** <br>
Declare an `int x`, create a reference `int& r = x;`, and demonstrate that changing `r` changes `x` and vice versa, by printing both after each change.

**Exercise 16.5 : Call by value vs call by reference** <br>
Write two functions, `increment(int n)` and `incrementRef(int& n)`. Call each on the same variable and print the variable's value after each call, to directly observe that only the reference version actually changes the caller's variable.

**Exercise 16.6 : Passing an array to a function** <br>
Write a function `void squareAll(int arr[], int n)` that squares every element of the array it receives. Call it from `main()` on an array you filled with input values, and print the array before and after the call to confirm the function modified the original array, not a copy.

---

## Self-Check

Before moving on to `Practice Problems.md`, make sure you can answer all of the following without looking anything up:

- Why does `cin >> x` sometimes leave a `\n` behind, and why does that matter for `getline`?
- Why did `int product1 = a * b;` overflow but `long long product2 = 1LL * a * b;` did not?
- What is the difference between `cin >> c` and `getchar()`?
- Why is `while (inFile >> x)` the correct way to read a file until EOF, instead of `while (!inFile.eof())`?
- What happens if you dereference an uninitialized or null pointer?
- Why does modifying an array inside a function change the original array, while modifying an `int` parameter passed by value does not?

If any of these feel shaky, redo the matching exercise above before starting the practice problems.
