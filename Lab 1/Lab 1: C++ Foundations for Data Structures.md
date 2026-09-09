# Lab 1: C++ Foundations for Data Structures

Welcome to Lab 1 of the Data Structure Lab course. Before we start implementing data structures, we need a solid grip on core C++ mechanics: how a program is structured, how headers and namespaces work, how arrays and strings behave in memory, how input/output really works (including the traps that cause silent bugs), and how pointers and references work. This document covers all of that with simple, formal explanations and runnable example code.

---

## Table of Contents

1. [Basic C++ Program Structure](#1-basic-c-program-structure)
2. [Header Files in C++ and the Story of `std::`](#2-header-files-in-c-and-the-story-of-std)
3. [Custom Header Files](#3-custom-header-files)
4. [`using namespace std`](#4-using-namespace-std)
5. [`#include <bits/stdc++.h>`](#5-include-bitsstdch)
6. [Macros](#6-macros)
7. [Arrays in C++](#7-arrays-in-c)
8. [Strings in C++](#8-strings-in-c)
9. [Whitespace and Input Handling](#9-whitespace-and-input-handling)
10. [`cin >> int` vs `cin >> string`](#10-cin--int-vs-cin--string)
11. [`cin >> char` vs `getchar()`](#11-cin--char-vs-getchar)
12. [`getline()`](#12-getline)
13. [`cin.ignore()`](#13-cinignore)
14. [File I/O, EOF, and Garbage Values](#14-file-io-eof-and-garbage-values)
15. [Integer Overflow: A Worked Example](#15-integer-overflow-a-worked-example)
16. [Pointers and References](#16-pointers-and-references)

---

## 1. Basic C++ Program Structure

Every C++ program needs at least one function called `main()`. This is the entry point: execution always starts here.

```cpp
#include <iostream>   // gives us access to cin, cout

int main() {
    std::cout << "Hello, Data Structures!" << std::endl;
    return 0;          // 0 means the program ended successfully
}
```

Key points:

- `#include <iostream>` brings in declarations needed for console input/output.
- `int main()` returns an integer to the operating system. Returning `0` conventionally means "no error."
- Every statement ends with a semicolon `;`.
- Code blocks are grouped with `{ }`.

You will compile this with a command such as:

```bash
g++ -std=c++17 -o program program.cpp
./program
```

---

## 2. Header Files in C++ and the Story of `std::`

A **header file** (ending in `.h` or with no extension, like `<iostream>`) contains *declarations* — function prototypes, class definitions, constants — that tell the compiler "this thing exists and this is its shape," without necessarily containing the full implementation. When you `#include` a header, the preprocessor literally copies its contents into your file before compilation begins.

```cpp
#include <iostream>  // declarations for cin, cout, etc.
#include <vector>    // declarations for std::vector
#include <cmath>     // declarations for math functions like sqrt
```

### Why `std::`?

Almost everything the C++ Standard Library provides (`cout`, `cin`, `vector`, `string`, `sort`, and so on) lives inside a **namespace** called `std` (short for "standard"). A namespace is simply a named box that groups identifiers together so they do not collide with names you define yourself or names from other libraries.

Without qualifying names, this ambiguity could occur:

```cpp
#include <iostream>

int cout = 5; // your own variable named "cout"

int main() {
    // std::cout << cout; // now there are two things called "cout" — chaos avoided only because std::cout is qualified
    std::cout << "value: " << cout << std::endl;
}
```

To use something from the `std` namespace, you either:

1. Fully qualify it every time: `std::cout`, `std::cin`, `std::string`, `std::vector<int>`.
2. Or pull specific names in: `using std::cout;`
3. Or pull the *entire* namespace in: `using namespace std;` (discussed in Section 4).

```cpp
#include <iostream>

int main() {
    std::cout << "Fully qualified, always safe." << std::endl;
    return 0;
}
```

---

## 3. Custom Header Files

As programs grow, you split code into multiple files: a header (`.h`) that declares what exists, and a source file (`.cpp`) that defines how it works. Other `.cpp` files then `#include` the header to use those declarations.

**`mathutils.h`**

```cpp
#ifndef MATHUTILS_H   // include guard: prevents this file being included twice
#define MATHUTILS_H

int add(int a, int b);          // declaration only
int factorial(int n);           // declaration only

#endif
```

**`mathutils.cpp`**

```cpp
#include "mathutils.h"

int add(int a, int b) {
    return a + b;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

**`main.cpp`**

```cpp
#include <iostream>
#include "mathutils.h"   // note: quotes, not angle brackets, for your own files

int main() {
    std::cout << add(3, 4) << std::endl;
    std::cout << factorial(5) << std::endl;
    return 0;
}
```

Compile all files together:

```bash
g++ -std=c++17 main.cpp mathutils.cpp -o program
```

Notes:

- Use `"header.h"` (quotes) for your own headers in the same project folder, and `<header>` (angle brackets) for standard library or system headers.
- The `#ifndef / #define / #endif` block is called an **include guard**. It stops the same header from being copy-pasted into a file twice if it gets included indirectly through multiple paths, which would otherwise cause "redefinition" compiler errors.

---

## 4. `using namespace std`

`using namespace std;` tells the compiler "if you see a name that isn't defined locally, also look inside the `std` namespace without me having to write `std::` every time."

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "No need to write std::cout here." << endl;
    return 0;
}
```

This is convenient in small lab programs and contest code, which is why you will see it constantly in this course. However, in larger, multi-file, professional projects it is generally discouraged, especially inside header files, because it can cause name collisions when two libraries define something with the same name. A safer middle ground used in real projects is bringing in only what you need:

```cpp
using std::cout;
using std::endl;
```

For this lab course, `using namespace std;` is perfectly fine and we will use it throughout to keep code short and readable.

---

## 5. `#include <bits/stdc++.h>`

Normally, you include exactly the headers you need:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
```

`<bits/stdc++.h>` is a single header (provided by the GNU GCC/G++ compiler, not part of the official C++ standard) that internally includes nearly the entire standard library at once:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 3, 1, 4};
    sort(v.begin(), v.end());
    for (int x : v) cout << x << " ";
    cout << endl;
    return 0;
}
```

Trade-offs to understand:

- **Advantage:** fast to write, no need to remember which header a function comes from — very common in competitive programming, which is why we use it in this lab.
- **Disadvantage:** it is not portable (it is a GCC-specific convenience header, so it may fail on compilers like MSVC), and it slows down compilation because it pulls in far more code than necessary.
- **Rule of thumb:** use `<bits/stdc++.h>` for labs, practice, and contests. In production software, include only what you actually use.

---

## 6. Macros

A macro is a text-substitution rule handled by the **preprocessor**, a step that runs before actual compilation. Macros are defined with `#define` and do not know about C++ types — they perform blind text replacement.

### Object-like macros (constants)

```cpp
#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159

int main() {
    double radius = 2.0;
    cout << "Area: " << PI * radius * radius << endl;
    return 0;
}
```

### Function-like macros

```cpp
#include <bits/stdc++.h>
using namespace std;

#define SQUARE(x) ((x) * (x))

int main() {
    cout << SQUARE(5) << endl;   // 25
    int a = 3;
    cout << SQUARE(a + 1) << endl; // careful: expands to ((a + 1) * (a + 1)) = 16, correct here because of the parentheses
    return 0;
}
```

Notice the parentheses around `x` and the whole expression. Without them, `SQUARE(a + 1)` would expand to `a + 1 * a + 1`, which is wrong due to text substitution rather than proper function evaluation. This is a classic macro pitfall.

### Common competitive programming macros

```cpp
#define ll long long
#define pb push_back
#define endl '\n'

int main() {
    ll bigNumber = 10000000000LL;
    vector<int> v;
    v.pb(10);
    cout << bigNumber << endl;
    return 0;
}
```

Macros are powerful but should be used carefully: since they are simple text substitution, they do not respect scope or type safety the way real functions and constants do. Modern C++ prefers `const`, `constexpr`, and inline functions where possible, but macros remain extremely common in fast lab/contest code.

---

## 7. Arrays in C++

An array is a fixed-size, contiguous block of memory holding elements of the same type.

### Declaration and Initialization

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5];                       // uninitialized, contains garbage values
    int b[5] = {1, 2, 3, 4, 5};     // fully initialized
    int c[5] = {1, 2};              // partially initialized: remaining elements become 0
    int d[] = {10, 20, 30};         // size deduced automatically as 3
    int e[5] = {0};                 // all elements set to 0

    cout << d[0] << " " << d[1] << " " << d[2] << endl;
    return 0;
}
```

### Accessing Elements

Array indices start at `0`. An array of size `n` has valid indices `0` to `n-1`.

```cpp
int arr[5] = {10, 20, 30, 40, 50};
cout << arr[0] << endl; // 10, the first element
cout << arr[4] << endl; // 50, the last element
```

### Taking Input Into an Array and Printing It

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100]; // assume n <= 100

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
```

### Finding the Sum of Array Elements

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "Sum = " << sum << endl;
    return 0;
}
```

### Do Not Access Nonexistent Elements (Out-of-Bounds Access)

C++ does **not** automatically check whether an index is valid. Accessing `arr[n]` or `arr[-1]` on an array of size `n` reads or writes memory that does not belong to the array. This is called **undefined behavior**: the program might crash, print garbage, silently corrupt other variables, or appear to "work" and fail later.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // WRONG: valid indices are 0 to 4. Index 5 is out of bounds.
    cout << arr[5] << endl; // undefined behavior: may print garbage, may crash

    // WRONG: negative index is also out of bounds.
    cout << arr[-1] << endl; // undefined behavior

    return 0;
}
```

Rule: always loop with a condition like `i < n`, never `i <= n`, when `n` is the array size.

### Reversing an Array

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0, right = n - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```

### N-Dimensional Arrays

A 2D array is essentially an array of arrays, commonly used for grids, matrices, and tables.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows = 3, cols = 4;
    int matrix[3][4]; // 3 rows, 4 columns

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

A 3D array follows the same pattern, adding one more dimension:

```cpp
int cube[2][3][4]; // 2 layers, each with 3 rows and 4 columns

for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 4; k++)
            cube[i][j][k] = i + j + k;
```

Memory grows quickly with dimensions: a `2x3x4` array holds `2*3*4 = 24` elements. Always be mindful of how much memory a multi-dimensional array actually uses.

---

## 8. Strings in C++

C++ has two notions of "string": the low-level C-style `char` array, and the modern `std::string` class. In this course we mainly use `std::string` since it manages its own memory and is far easier to work with safely.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = s1 + ", World!"; // concatenation with +
    cout << s2 << endl;
    return 0;
}
```

### Taking String Input (No Spaces)

`cin >> s` reads a single "token": characters up to the next whitespace (space, tab, or newline). It stops at the first space.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string name;
    cin >> name; // if you type "John Smith", only "John" is read here
    cout << "Hello, " << name << endl;
    return 0;
}
```

### Taking String Input With Spaces

To read a full line, including spaces, use `getline` (covered in detail in Section 12).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string fullName;
    getline(cin, fullName); // reads the entire line, e.g. "John Smith"
    cout << "Hello, " << fullName << endl;
    return 0;
}
```

### Length of a String

```cpp
string s = "Data Structures";
cout << s.length() << endl; // or s.size(), both give 16
```

### Reversing a String

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Structures";
    reverse(s.begin(), s.end()); // built-in algorithm, modifies s in place
    cout << s << endl; // "serutcurtS"
    return 0;
}
```

You can also reverse manually, the same way as an array, since `std::string` supports indexing with `[]`:

```cpp
string s = "Structures";
int left = 0, right = s.length() - 1;
while (left < right) {
    swap(s[left], s[right]);
    left++;
    right--;
}
```

### Accessing Individual Characters

```cpp
string s = "Hello";
cout << s[0] << endl; // 'H'
cout << s[4] << endl; // 'o'
// s[5] would be out of bounds, same danger as with arrays
```

---

## 9. Whitespace and Input Handling

"Whitespace" refers to space characters, tab characters (`\t`), and newline characters (`\n`). Understanding how `cin` treats whitespace is essential for avoiding some of the most common beginner bugs in C++.

By default, the `>>` operator (used with `cin`):

1. Skips over any leading whitespace before the value it is reading.
2. Reads characters until it hits the *next* whitespace character.
3. Leaves that trailing whitespace character **still sitting in the input buffer**, unread.

That leftover whitespace character (very often the `\n` from pressing Enter) is the root cause of a huge number of bugs when mixing `cin >>` with `getline`. We will see exactly this problem in Section 13.

---

## 10. `cin >> int` vs `cin >> string`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int age;
    string name;

    cin >> age;   // reads digits, stops at whitespace, converts to an integer
    cin >> name;  // reads characters, stops at whitespace, stores as text

    cout << "Age: " << age << ", Name: " << name << endl;
    return 0;
}
```

- `cin >> int_variable` expects a sequence of digits (optionally with a leading `+` or `-`). If the next token in the input is not a valid number (for example, letters), the read fails, `cin` enters a "fail state," and the variable is left at `0` (or unchanged, depending on the C++ standard version), and every subsequent `cin >>` call will also silently fail until the error state is cleared.
- `cin >> string_variable` simply reads one whitespace-delimited token of characters, no conversion needed.

Both behave identically in one respect: they skip leading whitespace and stop at the next whitespace, leaving that whitespace character unread.

---

## 11. `cin >> char` vs `getchar()`

Both read a single character, but they treat whitespace differently.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cin >> c; // SKIPS leading whitespace, then reads exactly one non-whitespace character
    cout << "You entered: " << c << endl;
    return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    char c = getchar(); // reads the VERY NEXT character in the buffer, whitespace included
    cout << "You entered: " << c << endl;
    return 0;
}
```

If the input stream currently holds `" A"` (a space followed by `A`):

- `cin >> c` skips the space and gives you `'A'`.
- `getchar()` gives you the space character `' '` itself, without skipping anything.

This distinction matters a lot when parsing input character by character, such as when reading grids of characters or checking for specific whitespace patterns.

---

## 12. `getline()`

`getline(cin, str)` reads an entire line of text, from the current position up to (and discarding) the next newline character `\n`. Unlike `cin >> str`, it does **not** stop at spaces.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "You typed: " << sentence << endl;
    return 0;
}
```

Input `"I love data structures"` is captured completely, including all internal spaces, as one string.

---

## 13. `cin.ignore()`

This is one of the most common sources of confusion for beginners: mixing `cin >>` with `getline`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int age;
    string name;

    cout << "Enter age: ";
    cin >> age;             // user types "20" and presses Enter
                             // cin >> age reads "20", but leaves the '\n' from Enter in the buffer

    cout << "Enter full name: ";
    getline(cin, name);     // BUG: getline immediately sees the leftover '\n'
                             // and reads it as an "empty line", so name becomes ""

    cout << "Age: " << age << ", Name: [" << name << "]" << endl;
    return 0;
}
```

The fix is to discard that leftover newline before calling `getline`, using `cin.ignore()`:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int age;
    string name;

    cout << "Enter age: ";
    cin >> age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard everything up to and including the next '\n'

    cout << "Enter full name: ";
    getline(cin, name); // now works correctly

    cout << "Age: " << age << ", Name: [" << name << "]" << endl;
    return 0;
}
```

`cin.ignore(n, delim)` means: "skip up to `n` characters, or stop earlier if you hit the character `delim`." Passing `numeric_limits<streamsize>::max()` for `n` effectively means "skip as many characters as necessary" so that it reliably discards everything up through the next newline.

**Rule of thumb:** whenever a `cin >>` is immediately followed by a `getline`, insert `cin.ignore(numeric_limits<streamsize>::max(), '\n');` between them.

---

## 14. File I/O, EOF, and Garbage Values

### Basic File Input/Output

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream outFile("data.txt"); // open a file for writing (creates it if missing)
    outFile << "10 20 30" << endl;
    outFile.close();

    ifstream inFile("data.txt");  // open the file for reading
    int a, b, c;
    inFile >> a >> b >> c;
    cout << a + b + c << endl;    // 60
    inFile.close();

    return 0;
}
```

- `ofstream` (output file stream) is used to write to a file.
- `ifstream` (input file stream) is used to read from a file.
- Always close a file stream (or let it go out of scope) once you are done with it.

### Reading Until End of File (EOF)

When you do not know how many numbers a file contains in advance, you read in a loop until the stream fails, which happens at end-of-file:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inFile("data.txt");
    int x, sum = 0;

    while (inFile >> x) {   // loop continues as long as a read succeeds
        sum += x;
    }
    // when there is nothing left to read, "inFile >> x" fails and the loop stops

    cout << "Sum = " << sum << endl;
    return 0;
}
```

`inFile >> x` returns the stream itself, and a stream converts to `true` in a boolean context (like a `while` condition) if the last operation succeeded, and to `false` if it failed (including on hitting EOF). This is why `while (inFile >> x)` is the idiomatic way to read "until the end of the file."

A common mistake is checking `while (!inFile.eof())` before reading. This is wrong because `eof()` only becomes true *after* a failed read attempt, so this pattern typically processes the last value twice (once correctly, once as leftover garbage). Prefer `while (inFile >> x)`.

### Garbage Values

A "garbage value" is whatever leftover, unpredictable data happens to already be sitting in a variable's memory location before you explicitly assign it something. Local variables in C++ are **not automatically initialized** unless you initialize them yourself.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;              // NOT initialized
    cout << x << endl;  // undefined / unpredictable value: this is a "garbage value"

    int y = 0;           // explicitly initialized
    cout << y << endl;   // reliably 0

    return 0;
}
```

Garbage values also show up when reading fails: if `cin >> x` fails to parse a number, `x` may be left holding whatever it had before (or `0`, depending on context), and continuing to use it without checking for the failure is a common source of subtle bugs.

**Rule of thumb:** always initialize variables when you declare them, and always check whether a read operation actually succeeded before trusting the value.

---

## 15. Integer Overflow: A Worked Example

Consider the following code:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1000000000;
    int b = 1000000000;

    int product1 = a * b;
    long long product2 = 1LL * a * b;

    cout << "product1 = " << product1 << '\n'; // product1 = -1486618624
    cout << "product2 = " << product2 << '\n'; // product2 = 1000000000000000000

    cout << (bitset<64>(product2)) << '\n'; // prints the 64-bit binary representation of product2
    cout << (bitset<32>(product1)) << '\n'; // prints the 32-bit binary representation of product1

    return 0;
}
```

### Explanation

- `a` and `b` are both `int`, and on virtually all modern systems `int` is stored in **32 bits**. A signed 32-bit integer can represent values only from about `-2,147,483,648` to `2,147,483,647`.
- The true mathematical result of `1,000,000,000 * 1,000,000,000` is `1,000,000,000,000,000,000` (10^18), which needs far more than 32 bits to represent.
- `int product1 = a * b;` computes the multiplication **using 32-bit integer arithmetic**, because both operands are `int`. The true result does not fit in 32 bits, so the high-order bits that do not fit are silently discarded. What remains is interpreted as a (in this case, negative) 32-bit signed number: `-1486618624`. This is called **integer overflow**, and in C++, signed integer overflow is technically undefined behavior, though in practice compilers on common platforms produce this kind of wraparound result.
- `long long product2 = 1LL * a * b;` fixes this. The literal `1LL` is a `long long` (typically 64 bits). When you multiply `1LL * a`, the `int` value of `a` is first **promoted** to `long long` before the multiplication happens, so the entire computation `1LL * a * b` is carried out using 64-bit arithmetic, which is large enough to hold the true result: `1000000000000000000`.
- Simply writing `long long product2 = a * b;` (without the `1LL *` trick) would **not** fix the bug: `a * b` is still computed in 32-bit `int` arithmetic first (because both `a` and `b` are `int`), producing the wrong, overflowed value, which is only afterward converted to `long long`. The overflow already happened before the assignment. The multiplication itself must involve at least one 64-bit operand.
- `bitset<64>(product2)` and `bitset<32>(product1)` convert those integers into their raw binary bit patterns, letting you visually see exactly which bits are set. Printing `bitset<32>(product1)` reveals the classic pattern of a 32-bit signed number that has wrapped around past the maximum positive value into negative territory (the leading bit becomes `1`, which is the sign bit in two's complement representation).

**Lesson:** whenever a computation might exceed the range of `int` (roughly ±2.1 billion), use `long long`, and make sure the multiplication itself is done in 64-bit arithmetic (for example, by casting or multiplying by a `1LL` first), not just the variable you are storing the result into.

---

## 16. Pointers and References

### Pointer Basics

A pointer is a variable that stores a memory address rather than a value directly.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;   // p stores the address of x ("&" means "address of")

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value stored in p: " << p << endl;   // same address as &x
    cout << "Value pointed to by p: " << *p << endl; // "*" means "dereference": get the value at that address

    *p = 20; // modifies x through the pointer
    cout << "x is now: " << x << endl;

    return 0;
}
```

- `&x` gives the memory address of `x`.
- `int* p` declares `p` as a pointer to an `int`.
- `*p` (dereferencing) accesses or modifies the value stored at the address `p` holds.

### Common Pointer Mistakes

```cpp
int* p;         // WRONG in practice: p is uninitialized, points to a garbage address
// cout << *p;  // undefined behavior: dereferencing an uninitialized pointer can crash the program

int* q = nullptr; // safer: explicitly points to "nothing"
if (q != nullptr) {
    cout << *q; // only dereference after checking it is not null
}
```

### Null Pointers

A null pointer is a pointer that deliberately points to nothing. In modern C++, use `nullptr` (rather than the older `NULL` or plain `0`) to represent this.

```cpp
int* p = nullptr;

if (p == nullptr) {
    cout << "p does not point to anything yet." << endl;
}

// Dereferencing a null pointer is undefined behavior and commonly crashes the program:
// cout << *p; // DO NOT DO THIS
```

Always check a pointer against `nullptr` before dereferencing it if there is any chance it might not point to valid memory.

### Pointer to Array and Pointer Arithmetic

An array's name, when used in most expressions, decays into a pointer to its first element.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr; // arr decays to a pointer to arr[0]

    cout << *p << endl;       // 10, same as arr[0]
    cout << *(p + 1) << endl; // 20, same as arr[1]
    cout << *(p + 2) << endl; // 30, same as arr[2]

    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " "; // pointer arithmetic: p + i moves i elements forward, not i bytes
    }
    cout << endl;

    return 0;
}
```

`p + 1` does not add 1 byte to the address; it adds `1 * sizeof(int)` bytes, moving to the next `int`-sized slot. This is why pointer arithmetic is type-aware: the compiler knows how big each element is.

### References

A reference is an alias, another name for an already-existing variable. Unlike a pointer, a reference cannot be null and cannot be reassigned to refer to something else after it is created.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 10;
    int& ref = x; // ref is now another name for x

    ref = 20;      // this changes x as well
    cout << x << endl; // 20

    x = 30;
    cout << ref << endl; // 30, since ref and x are the same variable

    return 0;
}
```

### Call by Value vs Call by Reference

**Call by value:** the function receives a *copy* of the argument. Changes inside the function do not affect the original variable.

```cpp
#include <bits/stdc++.h>
using namespace std;

void addOneByValue(int n) {
    n = n + 1; // modifies only the local copy
}

int main() {
    int x = 5;
    addOneByValue(x);
    cout << x << endl; // still 5, unchanged
    return 0;
}
```

**Call by reference:** the function receives a reference to the original variable. Changes inside the function directly affect the caller's variable.

```cpp
#include <bits/stdc++.h>
using namespace std;

void addOneByReference(int& n) {
    n = n + 1; // modifies the original variable
}

int main() {
    int x = 5;
    addOneByReference(x);
    cout << x << endl; // 6, changed
    return 0;
}
```

Call by reference is also commonly used to avoid the performance cost of copying large objects, even when you do not intend to modify them, by combining it with `const`:

```cpp
void printVector(const vector<int>& v) { // reference avoids copying; const prevents modification
    for (int x : v) cout << x << " ";
    cout << endl;
}
```

### Passing Arrays to Functions

Arrays are always passed to functions "by pointer" in effect: the function receives the address of the first element, not a copy of the whole array. This means array modifications inside a function are visible to the caller, and the function has no built-in way to know the array's size, so the size is usually passed as a separate parameter.

```cpp
#include <bits/stdc++.h>
using namespace std;

void doubleAllElements(int arr[], int n) { // arr here is really a pointer, int arr[] and int* arr mean the same thing as a parameter
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * 2;
    }
}

int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    doubleAllElements(nums, 5);

    for (int i = 0; i < 5; i++) {
        cout << nums[i] << " "; // 2 4 6 8 10, original array was modified
    }
    cout << endl;

    return 0;
}
```

Contrast this with passing a `std::string` or `std::vector`, which are objects, not raw arrays: by default they are passed by value (a full copy is made) unless you explicitly declare the parameter as a reference (`string&` or `vector<int>&`).

---

## Summary

| Topic | Key Idea |
|---|---|
| Header files | Declarations live in `.h`/`<...>` files; `#include` copies them in before compiling |
| `std::` | Standard library identifiers live inside the `std` namespace |
| Custom headers | Split declarations (`.h`) from definitions (`.cpp`); use include guards |
| `using namespace std` | Convenient in labs/contests; avoid in large multi-file production headers |
| `bits/stdc++.h` | One header, everything included; GCC-specific, fine for labs/contests |
| Macros | Preprocessor text substitution; powerful but type-unsafe, parenthesize carefully |
| Arrays | Fixed-size, zero-indexed, no automatic bounds checking |
| Strings | Prefer `std::string`; `cin >>` stops at whitespace, `getline` reads the whole line |
| `cin.ignore()` | Needed to discard a leftover `\n` before calling `getline` after `cin >>` |
| File I/O | `ifstream`/`ofstream`; read-until-fail (`while (inFile >> x)`) handles EOF correctly |
| Garbage values | Uninitialized variables hold unpredictable data; always initialize |
| Integer overflow | `int` (32-bit) overflows silently; use `long long` and 64-bit arithmetic for large products |
| Pointers | Store addresses; dereference with `*`; check for `nullptr` before use |
| References | Aliases for existing variables; cannot be null or reassigned |
| Call by value/reference | Value copies; reference lets a function modify the caller's variable |
| Arrays as parameters | Always passed effectively by pointer; pass the size separately |
