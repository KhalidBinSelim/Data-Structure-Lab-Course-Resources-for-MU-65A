This folder is where **you** submit your solutions to the Lab 1 practice problems from `Lab1_Practice_Problems.md`. Follow the steps below exactly : submissions that don't follow this structure may not be graded.

---

## Step 1: Fork the Repository

Click the **Fork** button at the top of the main repository page. This creates your own copy of the repo under your GitHub account.

## Step 2: Clone Your Fork

```bash
git clone https://github.com/<your-username>/<repo-name>.git
cd <repo-name>
```

## Step 3: Create Your Own Folder

Inside `Lab1/Solved Problems (For students)/`, create a folder named with your **Student ID**. Do not use your name alone : use your ID so submissions can be matched to the class roster.

```
Lab1/Solved Problems (For students)/261-115-001/
```

Do **not** edit, rename, or delete any other student's folder.

## Step 4: Add Your Solution Files

Inside your folder, add one `.cpp` file per problem you solve. Name each file using the problem number and name exactly as listed in `Lab1_Practice_Problems.md`, like this:

```
Lab1/Solved Problems (For students)/261-115-001/
├── 01_Watermelon.cpp
├── 02_TheatreSquare.cpp
├── 03_SimpleArraySum.cpp
├── ...
```

Every file must:

- Start with a comment containing the problem name and the direct judge link, for example:
  ```cpp
  // Problem: Watermelon
  // Link: https://codeforces.com/problemset/problem/4/A
  ```
- Compile and run on its own with `g++ -std=c++17`.
- Actually be **Accepted** on the judge before you submit it here : do not upload code that fails or that you have not tested.

You do not have to solve all problems before submitting. Add files as you solve more; your folder will simply keep growing.

## Step 5: Commit and Push

```bash
git add .
git commit -m "Add solutions for Lab 1 practice problems"
git push origin main
```

## Step 6: Open a Pull Request

Go to your fork on GitHub and click **Compare & pull request** to open a PR back to the original class repository. Use a clear title, for example:

```
Lab 1 Submissions - 261-115-001
```

I will review the PR to check and mark your work. If you solve more problems later, push new commits to the same branch : they will automatically appear in the same PR.

---

## Rules

- **One folder per student**, named with your Student ID.
- **One file per problem**, named with the problem number and name.
- Only add or edit files inside **your own** folder.
- Code must be your own work and must be Accepted on the actual judge before submission. Copied or unverified code will not be counted.
- If you are unsure whether your submission is structured correctly, check an existing example folder in this directory before opening your PR.
