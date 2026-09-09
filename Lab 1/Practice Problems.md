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

## Hard (Combining Concepts, Tricky Edge Cases, Real Algorithmic Thinking)

These are a step up from the Medium set on purpose: each one forces students to combine several Lab 1 ideas at once (careful character-by-character parsing, overflow detection, two-pointer array technique) and cannot be solved correctly with the first naive idea that comes to mind : the edge cases are where most submissions fail.

17. **String to Integer (atoi)** : LeetCode 8<br>
    Manually implement what `cin >> int` does internally: skip leading whitespace, handle an optional `+`/`-` sign, read digits until a non-digit appears, and clamp the result to the 32-bit signed integer range instead of overflowing. This ties directly into Sections 9, 10, and 15 of Lab 1, and is notorious for hidden edge cases (empty string, only whitespace, sign with no digits, leading zeros, overflow in both directions).
    Link: https://leetcode.com/problems/string-to-integer-atoi/

18. **Longest Substring Without Repeating Characters** : LeetCode 3<br>
    Given a string, find the length of its longest substring with no repeated characters. A brute-force check of every substring is too slow for the given constraints, so this forces students to maintain a moving window over the string using two indices : a genuine step beyond simple left-to-right traversal.
    Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

19. **3Sum** : LeetCode 15<br>
    Given an array, find all unique triplets that sum to zero. Requires sorting the array first, then using a two-pointer scan for each fixed element, plus careful duplicate-skipping logic : meaningfully harder than the two-pointer array reversal covered in Lab 1.
    Link: https://leetcode.com/problems/3sum/

20. **Trapping Rain Water** : LeetCode 42<br>
    Given an array representing an elevation map, compute how much water it can trap after raining. Solvable with careful array traversal (precomputing left-max and right-max arrays, or a two-pointer approach), but getting the boundary logic right is genuinely difficult; this is one of LeetCode's classic "hard" array problems.
    Link: https://leetcode.com/problems/trapping-rain-water/

