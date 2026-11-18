# Lab 9: Basic Lab Exercises

**Topics:** Graph Representation (Adjacency Matrix, Adjacency List), Weighted and Directed Graphs, Degree, Edge Check

These exercises are short and self-contained. Read `Lab 9: Graph Representation.md` first, then write each program yourself in C++, compile it, and run it against the sample input to confirm you understood the concept. No online judge, account, or submission is needed.

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

**Rules**

- Every input starts with `n m` (vertices and edges), followed by `m` edge lines. Vertices are numbered `1` to `n`.
- Use arrays/vectors of size `n + 1`; index `0` is unused.
- For an **undirected** graph, store each edge in both directions. For a **directed** graph, store it in one direction only.
- Write each exercise as a separate program.

**Sample graphs used below**

```
Graph A (undirected)    Graph B (directed)    Graph C (weighted, undirected)
5 6                     4 4                   4 4
1 2                     1 2                   1 2 5
1 3                     1 3                   1 3 3
2 3                     2 4                   2 4 2
2 4                     3 4                   3 4 7
3 5
4 5
```

---

## Part A: Adjacency Matrix

### Exercise 1: Undirected Matrix

Read Graph A and store it in an adjacency matrix. Print the matrix.

```
Output:
0 1 1 0 0
1 0 1 1 0
1 1 0 0 1
0 1 0 0 1
0 0 1 1 0
```

*Hint: for each edge `u v`, set both `mat[u][v] = 1;` and `mat[v][u] = 1;`.*

### Exercise 2: Directed Matrix

Read Graph B and store it in an adjacency matrix, setting only `mat[u][v]`. Print the matrix. Notice that it is **not** symmetric.

```
Output:
0 1 1 0
0 0 0 1
0 0 0 1
0 0 0 0
```

### Exercise 3: Weighted Matrix

Read Graph C and store the **weight** in the matrix instead of `1`. Print the matrix (`0` means no edge).

```
Output:
0 5 3 0
5 0 0 2
3 0 0 7
0 2 7 0
```

---

## Part B: Adjacency List

### Exercise 4: Undirected List

Read Graph A and store it in an adjacency list. Print each vertex followed by its neighbors.

```
Output:
1: 2 3
2: 1 3 4
3: 1 2 5
4: 2 5
5: 3 4
```

### Exercise 5: Directed List

Read Graph B and store it in an adjacency list (one direction only). Print the list. A vertex with no outgoing edge prints just its number and a colon.

```
Output:
1: 2 3
2: 4
3: 4
4:
```

### Exercise 6: Weighted List

Read Graph C and store `(neighbor, weight)` pairs using `vector<vector<pair<int,int>>>`. Print each vertex with its pairs.

```
Output:
1: (2,5) (3,3)
2: (1,5) (4,2)
3: (1,3) (4,7)
4: (2,2) (3,7)
```

*Hint: `adj[u].push_back({v, w});` and print with `for (auto [v, w] : adj[u])`.*

---

## Part C: Basic Graph Concepts

### Exercise 7: Degree of Every Vertex

Read Graph A into an adjacency list. Print the degree of each vertex, then print the sum of all degrees and `2 * m` to confirm they match.

```
Output:
Degree of 1: 2
Degree of 2: 3
Degree of 3: 3
Degree of 4: 2
Degree of 5: 2
Sum of degrees = 12, 2 * edges = 12
```

### Exercise 8: In-degree and Out-degree

Read Graph B (directed). Print the in-degree and out-degree of every vertex.

```
Output:
Vertex 1: in = 0, out = 2
Vertex 2: in = 1, out = 1
Vertex 3: in = 1, out = 1
Vertex 4: in = 2, out = 0
```

*Hint: out-degree is `adj[u].size()`. For in-degree, do `indeg[v]++` while reading each edge `u v`.*

### Exercise 9: Edge Check

Read Graph A into an adjacency matrix. After the edges, read two more numbers `u v` and print `Yes` if there is an edge between them, otherwise `No`.

```
Input : Graph A, then: 2 4
Output: Yes

Input : Graph A, then: 1 4
Output: No
```

---

## Challenge (Optional)

### Exercise 10: Matrix to List

Read `n`, then an `n x n` adjacency matrix (no edge count this time). Convert it to an adjacency list and print the list.

```
Input :
4
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

Output:
1: 2 3
2: 1 4
3: 1 4
4: 2 3
```

*Hint: for each cell with `mat[i][j] == 1`, do `adj[i].push_back(j);`.*

### Exercise 11: Vertex with the Highest Degree

Read Graph A and print the vertex with the largest degree and that degree. If there is a tie, print the smallest vertex.

```
Output: Vertex 2 has the highest degree: 3
```

---

## Self-Check

Before moving on, make sure you can answer all of the following without looking anything up:

- What is the difference between a directed and an undirected graph?
- Why do we store an undirected edge twice (once for each direction)?
- Why is the adjacency matrix symmetric for an undirected graph, but usually not for a directed one?
- Which representation checks "is there an edge between `u` and `v`" in O(1), and which uses less memory for a sparse graph?
- Why must arrays be of size `n + 1` when vertices are numbered `1` to `n`?
- What is the relation between the sum of all degrees and the number of edges in an undirected graph?
- How do you find the in-degree of a vertex when you store the graph as an adjacency list?

If any of these feel shaky, redo the matching exercise above before moving on.
