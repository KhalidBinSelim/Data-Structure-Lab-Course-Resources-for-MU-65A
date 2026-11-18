# Lab 9: Graph Representation

This document explains the topics of Lab 9. Read it before, during and after the lab session, then move on to `Basic Lab Exercises.md`.

**Compile and run:**

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

---

## Table of Contents

1. [Introduction to Graphs](#1-introduction-to-graphs)
2. [Adjacency Matrix](#2-adjacency-matrix)
3. [Adjacency List](#3-adjacency-list)
4. [Basic Graph Concepts](#4-basic-graph-concepts)
5. [Quick Summary](#5-quick-summary)

---

## 1. Introduction to Graphs

### 1.1 What is a Graph?

A **graph** is a set of **vertices** (also called nodes) connected by **edges**. Graphs model real things: cities connected by roads, people connected by friendships, web pages connected by links.

```
    1
   / \
  2---3
  |   |
  4---5
```

This graph has 5 vertices (1 to 5) and 6 edges: `1-2`, `1-3`, `2-3`, `2-4`, `3-5`, `4-5`.

### 1.2 Basic Terms

| Term | Meaning |
| --- | --- |
| Undirected graph | An edge works both ways: `1-2` means 1 to 2 **and** 2 to 1 |
| Directed graph | An edge has a direction: `1 -> 2` means only 1 to 2 |
| Weighted graph | Every edge has a number (cost, distance, time) |
| Neighbors | Two vertices joined by an edge are neighbors (adjacent) |
| Degree | Number of edges touching a vertex |
| Path | A sequence of vertices where each consecutive pair is joined by an edge |

### 1.3 Input Format Used in This Lab

We use the same format as most online judges: the first line has `n` (vertices) and `m` (edges), then `m` lines follow, one edge per line. Vertices are numbered `1` to `n`, so our arrays have size `n + 1` and index `0` is unused.

```
5 6
1 2
1 3
2 3
2 4
3 5
4 5
```

A graph can be stored in two main ways: an **adjacency matrix** or an **adjacency list**.

---

## 2. Adjacency Matrix

### 2.1 What is an Adjacency Matrix?

An **adjacency matrix** is an `n x n` table. The cell `mat[i][j]` is `1` if there is an edge from `i` to `j`, and `0` if there is not.

For the graph in Section 1.1:

```
    1  2  3  4  5
1 [ 0  1  1  0  0 ]
2 [ 1  0  1  1  0 ]
3 [ 1  1  0  0  1 ]
4 [ 0  1  0  0  1 ]
5 [ 0  0  1  1  0 ]
```

For an **undirected** graph the matrix is symmetric (`mat[i][j] == mat[j][i]`), so every edge is stored twice.

### 2.2 Building It (Undirected)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));   // all 0 = no edges yet

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;       // undirected: set both directions
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
```

### 2.3 Directed and Weighted Versions

Only the line(s) that store the edge change.

**Directed:** store only one direction.

```cpp
mat[u][v] = 1;          // edge u -> v only
```

**Weighted:** read the weight `w` and store it instead of `1`. Here `0` means "no edge", so this works when all weights are positive.

```cpp
int u, v, w;
cin >> u >> v >> w;
mat[u][v] = w;
mat[v][u] = w;          // remove this line for a directed graph
```

### 2.4 Checking an Edge

Looking up one cell is **O(1)**.

```cpp
if (mat[u][v] != 0) cout << "Edge exists\n";
else cout << "No edge\n";
```

The matrix uses **O(n^2)** memory, even if the graph has very few edges.

---

## 3. Adjacency List

### 3.1 What is an Adjacency List?

An **adjacency list** stores, for every vertex, a list of only its neighbors. We use an array of `vector`s: `adj[u]` holds all neighbors of `u`.

```
1: 2 3
2: 1 3 4
3: 1 2 5
4: 2 5
5: 3 4
```

### 3.2 Building It (Undirected)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);     // adj[0] is unused

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);            // undirected: add both directions
    }

    for (int u = 1; u <= n; u++) {
        cout << u << ":";
        for (int v : adj[u]) cout << " " << v;
        cout << "\n";
    }
    return 0;
}
```

For a **directed** graph, keep only `adj[u].push_back(v);`.

### 3.3 Weighted Adjacency List

Store a `pair<int,int>` of `(neighbor, weight)` for each edge.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});       // remove for a directed graph
    }

    for (int u = 1; u <= n; u++) {
        cout << u << ":";
        for (auto [v, w] : adj[u]) cout << " (" << v << "," << w << ")";
        cout << "\n";
    }
    return 0;
}
```

For the input `4 4` with edges `1 2 5`, `1 3 3`, `2 4 2`, `3 4 7`, the output is:

```
1: (2,5) (3,3)
2: (1,5) (4,2)
3: (1,3) (4,7)
4: (2,2) (3,7)
```

### 3.4 Checking an Edge

The list has no direct lookup, so we search the neighbors of `u`: **O(degree of u)**.

```cpp
bool hasEdge(const vector<vector<int>>& adj, int u, int v) {
    for (int x : adj[u]) {
        if (x == v) return true;
    }
    return false;
}
```

The list uses only **O(n + m)** memory, because it stores just the edges that exist.

---

## 4. Basic Graph Concepts

### 4.1 Degree (Undirected)

The degree of a vertex is the number of its neighbors, which is simply the size of its list. A vertex with degree 0 is **isolated**.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int sum = 0;
    for (int u = 1; u <= n; u++) {
        cout << "Degree of " << u << ": " << adj[u].size() << "\n";
        sum += adj[u].size();
    }
    cout << "Sum of degrees = " << sum << ", 2 * edges = " << 2 * m << "\n";
    return 0;
}
```

For the graph in Section 1.1 this prints degrees `2 3 3 2 2`, and the sum is `12 = 2 * 6`. This always holds for undirected graphs, because every edge adds 1 to the degree of **both** its ends. It is a quick way to check your graph was built correctly.

### 4.2 In-degree and Out-degree (Directed)

In a directed graph, edge `u -> v` counts as **out-degree** for `u` and **in-degree** for `v`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);      // directed: one direction only
        indeg[v]++;               // v receives one incoming edge
    }

    for (int u = 1; u <= n; u++) {
        cout << "Vertex " << u << ": in = " << indeg[u]
             << ", out = " << adj[u].size() << "\n";
    }
    return 0;
}
```

For `4 4` with edges `1 2`, `1 3`, `2 4`, `3 4`:

```
Vertex 1: in = 0, out = 2
Vertex 2: in = 1, out = 1
Vertex 3: in = 1, out = 1
Vertex 4: in = 2, out = 0
```

### 4.3 Matrix vs List

| | Adjacency Matrix | Adjacency List |
| --- | --- | --- |
| Memory | O(n^2) | O(n + m) |
| Check if edge `u-v` exists | O(1) | O(degree of u) |
| Go through all neighbors of `u` | O(n) | O(degree of u) |
| Best for | Small or dense graphs | Large or sparse graphs (most real graphs) |

With `n = 100000` vertices a matrix needs about 10 billion cells, which is far too much memory, while a list with a few hundred thousand edges is tiny. In practice, the **adjacency list is the default choice**.

---

## 5. Quick Summary

| Topic | Key Idea | Cost |
| --- | --- | --- |
| Graph | Vertices connected by edges (directed, undirected, or weighted) | : |
| Adjacency matrix | `n x n` table, `mat[u][v]` = edge or weight | Memory O(n^2), edge check O(1) |
| Adjacency list | `adj[u]` holds the neighbors of `u` | Memory O(n + m), edge check O(degree) |
| Undirected edge | Store it in both directions | : |
| Degree | `adj[u].size()`; sum of all degrees = 2 * edges | O(1) per vertex |
| In/out-degree | Count `indeg[v]++` while reading; out-degree is `adj[u].size()` | O(m) |

**Common mistakes**

- Making arrays of size `n` when vertices are numbered `1` to `n` (use `n + 1`).
- Forgetting the second direction (`mat[v][u]` or `adj[v].push_back(u)`) for an undirected graph.
- Adding both directions for a directed graph.
- Using `0` to mean "no edge" in a weighted matrix when `0` can be a real weight.
- Choosing a matrix for a huge graph and running out of memory.
