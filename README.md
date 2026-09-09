# Data-Structure-Lab-Course-Resources-for-MU-65A

This repository is the single source for everything used in the lab: class resource notes, example code, practice problems with judge links, and the folder where students submit their solved problems each week. It will grow lab by lab over the course of the semester.

---

## Table of Contents

- [About This Course](#about-this-course)
- [Repository Structure](#repository-structure)
- [How Each Lab Folder Is Organized](#how-each-lab-folder-is-organized)
- [Getting Started](#getting-started)
- [How to Submit Practice Problem Solutions](#how-to-submit-practice-problem-solutions)
- [Compiler and Environment Setup](#compiler-and-environment-setup)
- [Course Policies](#course-policies)
- [License](#license)
- [Contact](#contact)

---

## About This Course

The Data Structure Lab is the practical companion to the Data Structures theory course. Each lab session introduces a topic : starting from C++ fundamentals in Lab 1 and moving through arrays, linked lists, stacks, queues, trees, and other core data structures : with:

1. A **Class Resources** document explaining the concepts with example code.
2. A set of **Practice Problems** from well-known online judges (Codeforces, CSES, HackerRank, LeetCode) to build fluency.
3. Periodic **contests** to test what has been learned under time pressure.

All resources are published here so students always have a single, versioned place to refer back to, regardless of which lab session they were made in.

---

## Repository Structure

```
Data-Structure-Lab-Course-Resources-for-MU-65A/
├── Lab 1/
│   ├── Lab1_README.md                          # Class resources: concepts + example code
│   ├── Lab1_Practice_Problems.md                # Practice problems with judge links
│   └── Solved Problems (For students)/          # Students submit their solutions here
│       ├── README.md                            # Submission instructions
│       ├── <student-id-1>/
│       ├── <student-id-2>/
│       └── ...
├── Lab 2/                                        # Added as the course progresses
├── ...
├── Necessary Code Files/                         # Shared reference code, templates, utilities
├── LICENSE
└── README.md                                     # You are here
```

New `Lab <n>/` folders are added as the semester progresses. Each one is self-contained and follows the same internal structure described below.

---

## How Each Lab Folder Is Organized

Every `Lab <n>/` folder follows the same three-part pattern:

| File / Folder | Purpose |
|---|---|
| `Lab<n>_README.md` | The class resource document: every topic covered in that lab, explained with simple, formal descriptions and runnable C++ example code. Read this before or during the lab session. |
| `Lab<n>_Practice_Problems.md` | A curated list of 10–20 practice problems (Easy → Medium → Hard) from real online judges, each with a direct link to the problem statement. Solve these after the class to build fluency. |
| `Solved Problems (For students)/` | Where students submit their own solved `.cpp` files after forking the repository. See the `README.md` inside this folder for exact instructions. |

This pattern repeats for every lab, so once you understand the workflow for Lab 1, every future lab works the same way.

---

## Getting Started

1. **Read the Class Resources file** (`Lab<n>_README.md`) for the current lab before attempting any problems.
2. **Set up your C++ environment** (see [Compiler and Environment Setup](#compiler-and-environment-setup) below) if you have not already.
3. **Attempt the Practice Problems** listed in `Lab<n>_Practice_Problems.md`, solving them directly on the linked judge.
4. **Submit your solved code** by forking this repository and following the instructions in `Solved Problems (For students)/README.md`.

---

## How to Submit Practice Problem Solutions

Full step-by-step instructions live in [`Lab 1/Solved Problems (For students)/README.md`](<Lab%201/Solved%20Problems%20(For%20students)/README.md>). In short:

1. Fork this repository.
2. Clone your fork locally.
3. Create a folder named with your **Student ID** inside the current lab's `Solved Problems (For students)/` folder.
4. Add one `.cpp` file per problem you solve, named after the problem number and title, with the problem link in a comment at the top.
5. Commit, push to your fork, and open a Pull Request back to this repository.

Only submit code that has actually been **Accepted** on the judge. Untested or copied code will not be counted.

---

## Compiler and Environment Setup

All example code in this repository targets **C++17** and is written to compile with `g++`.

```bash
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

Recommended setup:

- **Compiler:** GCC / G++ (via [MinGW](https://www.mingw-w64.org/) on Windows, or the default `g++` on Linux/macOS)
- **Editor:** Any editor works; [VS Code](https://code.visualstudio.com/) with the C/C++ extension is recommended for a consistent experience across the class
- **Online judges used in this course:** [Codeforces](https://codeforces.com/), [CSES](https://cses.fi/), [HackerRank](https://www.hackerrank.com/), [LeetCode](https://leetcode.com/) : create a free account on each before Lab 1

`#include <bits/stdc++.h>` is used throughout this course's example code and is supported by GCC/G++. It is not part of the official C++ standard and may not compile on non-GCC compilers (such as MSVC); use GCC/G++ for all lab work.

---

## Course Policies

- **Academic integrity:** All submitted code must be your own work. Copying solutions from classmates, the internet, or an AI tool and submitting them as your own is not permitted.
- **One folder per student:** Do not create, edit, or delete files inside another student's submission folder.
- **Pull requests stay open:** As you solve more problems across the semester, keep pushing new commits to your existing branch/PR rather than opening a new one each time, unless instructed otherwise.
- **Deadlines:** Submission deadlines for each lab's practice problems will be announced in class and/or in the relevant lab folder.

---

## License

This repository is released under the [MIT License](LICENSE). You are free to use, copy, and adapt the material with attribution.

---

## Contact

**Khalid Bin Selim** <br>
Lecturer, Department of Computer Science and Engineering <br>
Metropolitan University, Sylhet, Bangladesh <br>
<br>
For questions about course content or submissions, reach out through the class communication channel or open an Issue in this repository.
