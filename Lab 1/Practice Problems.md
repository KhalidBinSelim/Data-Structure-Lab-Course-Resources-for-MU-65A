# Lab 1: Practice Problems

These problems reinforce everything covered in Lab1: basic I/O, arrays, strings, whitespace/input handling, file-style reading patterns, integer overflow, and pointers/references. Work through them in order: **Easy** first, then **Medium**, then **Hard**, and try to solve each one without looking at editorials first. Solving these on the actual judge (not just reading them) is what builds real fluency.

Each problem links directly to its statement on the judge. Create an account on each site if you do not already have one: most of them (Codeforces, CSES, HackerRank, LeetCode) are free.

---

## Easy (Basic I/O, Arrays, Strings)

1. **Watermelon** : Codeforces 4A <br>
   Basic conditional logic with a single integer input. Good first "cin, then decide" problem.
   Link: https://codeforces.com/problemset/problem/4/A

2. **Theatre Square** : Codeforces 1A <br>
   Reads three integers and computes a formula. Tests careful use of `long long` to avoid overflow.
   Link: https://codeforces.com/problemset/problem/1/A

3. **Simple Array Sum** : HackerRank<br>
   Read `n`, then `n` integers into an array, and print their sum. Directly matches the "sum of array" section of Lab 1.
   Link: https://www.hackerrank.com/challenges/simple-array-sum/problem

4. **Weird Algorithm** : CSES 1068<br>
   Read a single integer and simulate a loop, printing values as you go. Good practice for basic loops and `cin >> int`.
   Link: https://cses.fi/problemset/task/1068

5. **Way Too Long Words** : Codeforces 71A<br>
   Read `n` strings with `cin >> s` (whitespace-delimited token reading) and transform each one based on its length.
   Link: https://codeforces.com/problemset/problem/71/A

6. **String Task** : Codeforces 118A<br>
   Read a single string and process it character by character. Reinforces string indexing and character checks.
   Link: https://codeforces.com/problemset/problem/118/A

7. **Chat Room** : Codeforces 58A<br>
   Check whether a string contains the letters of "hello" as a subsequence. Practice with string traversal.
   Link: https://codeforces.com/problemset/problem/58/A

8. **Bit++** : Codeforces 282A<br>
   Read `n` lines of text input (mixing whitespace and tokens) and track a running counter. Reinforces careful input parsing.
   Link: https://codeforces.com/problemset/problem/282/A

---

## Medium (Arrays, Strings, Input Handling, References)

9. **Missing Number** : CSES 1083<br>
   Read `n` distinct integers from `1` to `n` with one missing, and find it. Practice with arrays/sums and possible overflow if summed incorrectly.
   Link: https://cses.fi/problemset/task/1083

10. **Repetitions** : CSES 1069<br>
    Read a single long DNA string and find the longest run of the same repeated character. Good string-traversal and edge-case practice (empty input, single character).
    Link: https://cses.fi/problemset/task/1069

11. **Increasing Array** : CSES 1094<br>
    Read an array and compute the minimum number of increments needed to make it non-decreasing. Good array-traversal problem with a `long long` answer (classic overflow trap, similar to Section 15 of Lab 1).
    Link: https://cses.fi/problemset/task/1094

12. **Stones on the Table** : Codeforces 266A<br>
    Read an integer `n` followed by a string of length `n` and compare adjacent characters. Reinforces safe array/string bounds checking.
    Link: https://codeforces.com/problemset/problem/266/A

13. **Team** : Codeforces 231A<br>
    Read multiple lines, each with three integers, and count how many satisfy a condition. Good repeated-input-in-a-loop practice.
    Link: https://codeforces.com/problemset/problem/231/A

14. **2D Array - DS (Hourglass Sum)** : HackerRank<br>
    Read a fixed-size 2D array and compute a sliding-window sum over it. Directly matches the N-dimensional array section of Lab 1.
    Link: https://www.hackerrank.com/challenges/2d-array/problem

15. **Arrays: Left Rotation** : HackerRank<br>
    Rotate an array left by `d` positions and print the result. Reinforces array indexing, and can be done cleanly with pointer-style index arithmetic.
    Link: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem

16. **Reverse String** : LeetCode 344<br>
    Reverse a character array in place using two pointers moving toward each other. Directly matches the two-pointer array-reversal technique from Lab 1.
    Link: https://leetcode.com/problems/reverse-string/

---

## Hard (Combining Concepts, Careful Input Parsing, Overflow Awareness)

17. **Two Sum** : LeetCode 1<br>
    Given an array and a target, find two indices whose values sum to the target. Naive array traversal works first; think about why a brute-force double loop is slow, and what a smarter approach (still array-based) would look like.
    Link: https://leetcode.com/problems/two-sum/

18. **Reverse Integer** : LeetCode 7<br>
    Reverse the digits of a signed 32-bit integer and handle the case where the reversed number overflows a 32-bit `int`. This is a direct, practical application of the integer-overflow concept from Section 15 of Lab 1 : you must detect overflow using `long long` before casting back to `int`.
    Link: https://leetcode.com/problems/reverse-integer/

19. **Insomnia Cure** : Codeforces 148A<br>
    Read several integers on one line with careful whitespace-separated parsing, and apply a multi-condition filter. Combines careful `cin >>` usage with array-free counting logic.
    Link: https://codeforces.com/problemset/problem/148/A

20. **Word Capitalization** : Codeforces 281A<br>
    Read a string, modify a single character using indexing/pointer-like access, then print the result. Combines string indexing, in-place modification, and careful output formatting.
    Link: https://codeforces.com/problemset/problem/281/A


