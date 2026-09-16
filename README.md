# Data-Structure-Lab-Course-Resources-for-MU-65A

This repository is the single source for everything used in the lab: class resource notes, hands-on exercises, practice problems with judge links, and periodic marathon contests. It will grow lab by lab over the course of the semester. This is a reference repository : there is nothing to fork, clone, or submit here, you simply open the files and read.

---

## Table of Contents

- [About This Course](#about-this-course)
- [How Each Lab Folder Is Organized](#how-each-lab-folder-is-organized)
- [Getting Started](#getting-started)
- [Compiler and Environment Setup](#compiler-and-environment-setup)
- [Course Policies](#course-policies)
- [License](#license)
- [Contact](#contact)

---

## About This Course

The Data Structure Lab is the practical companion to the Data Structures theory course. Each lab session introduces a topic : starting from C++ fundamentals in Lab 1 and moving through arrays, linked lists, stacks, queues, trees, and other core data structures : with:

1. A **Class Resources** document explaining the concepts with example code.
2. A set of **Basic Lab Exercises** to build hands-on comfort with each concept before tackling real problems.
3. A set of **Practice Problems** from well-known online judges (Codeforces, CSES, HackerRank, LeetCode, AtCoder, CodeChef, LightOJ, UVA) to build fluency.
4. A periodic **Practice Marathon** on VJudge to test what has been learned under a longer, low-pressure contest format.

All resources are published here so students always have a single, versioned place to refer back to, regardless of which lab session they were made in.

---

## How Each Lab Folder Is Organized

Every `Lab <n>/` folder follows the same four-part pattern:

| File | Purpose |
|---|---|
| `Lab <n>: <Topic>.md` | The class resource document: every topic covered in that lab, explained with simple, formal descriptions and runnable C++ example code. Read this before or during the lab session. |
| `Basic Lab Exercises.md` | Short, self-contained exercises : one or more per concept : meant to be done right after reading the class resources. No online judge, no account, no submission: just write the code, compile it, and run it yourself to confirm you understood the concept. |
| `Practice Problems.md` | A curated list of practice problems, arranged Easy → Medium → Hard, from real online judges, each with a direct link to the problem statement. Solve these on the judge itself once the Basic Lab Exercises feel comfortable. |
| `Practice Marathon Contest Link.md` | A link to that lab's practice marathon, hosted on VJudge, mixing problems from several judges into one longer-format contest. Open for several days rather than timed, so students can work through it at their own pace. |

This pattern repeats for every lab, so once you understand the workflow for Lab 1, every future lab works the same way.

---

## Getting Started

1. **Read the Class Resources file** for the current lab before or during the lab session.
2. **Set up your C++ environment** (see [Compiler and Environment Setup](#compiler-and-environment-setup) below) if you have not already.
3. **Work through `Basic Lab Exercises.md`** on your own machine : no judge or account needed for this step.
4. **Solve the Practice Problems** in `Practice Problems.md` directly on the linked judge, using an account on that judge.
5. **Join the Practice Marathon**, for extra practice, using the link in `Practice Marathon Contest Link.md`.

There is nothing to fork, clone, or submit back to this repository. You only need accounts on the judges themselves (Codeforces, CSES, HackerRank, LeetCode, AtCoder, CodeChef, LightOJ, and VJudge) to solve and track your own problems there.

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
- **Online judges used in this course:** [Codeforces](https://codeforces.com/), [CSES](https://cses.fi/), [HackerRank](https://www.hackerrank.com/), [LeetCode](https://leetcode.com/), [AtCoder](https://atcoder.jp/), [CodeChef](https://www.codechef.com/), [LightOJ](https://lightoj.com/), and [VJudge](https://vjudge.net/) for the marathons : create a free account on each before Lab 1

`#include <bits/stdc++.h>` is used throughout this course's example code and is supported by GCC/G++. It is not part of the official C++ standard and may not compile on non-GCC compilers (such as MSVC); use GCC/G++ for all lab work.

---

## Course Policies

- **Academic integrity:** Solve every practice problem and marathon problem yourself. Copying solutions from classmates, the internet, or an AI tool and passing them off as your own defeats the purpose of the practice.
- **No repository submissions:** This repository is reference material only. Your problem-solving activity is tracked on the judges themselves (Codeforces, HackerRank, LeetCode, VJudge, etc.), not through this GitHub repository.
- **Pacing:** Work through each lab's Basic Lab Exercises before attempting its Practice Problems, and attempt the Practice Problems before the Practice Marathon : the difficulty is designed to build in that order.
- **Deadlines:** Any deadlines for a lab's practice problems or marathon will be announced in class.

---

## License

This repository is released under the [MIT License](LICENSE). You are free to use, copy, and adapt the material with attribution.

---

## Contact

**Khalid Bin Selim** <br>
Lecturer, Department of Computer Science and Engineering <br>
Metropolitan University, Sylhet, Bangladesh. <br>
<br>
For questions about course content, reach out through the class communication channel or open an Issue in this repository.
