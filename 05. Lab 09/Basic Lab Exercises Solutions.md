# Lab 9: Basic Lab Exercises: Solutions

Solutions for `Basic Lab Exercises.md`. Try each exercise yourself first, then compare. Every solution is a complete program: copy it into `solution.cpp`, compile it, and run it with the sample input.

```
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

---

## Part A: Adjacency Matrix

### Exercise 1: Undirected Matrix

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));   // all 0 at the start

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;          // undirected: both directions
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
```

**Output (Graph A):**

```
0 1 1 0 0
1 0 1 1 0
1 1 0 0 1
0 1 0 0 1
0 0 1 1 0
```

### Exercise 2: Directed Matrix

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;          // directed: only u -> v
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
```

**Output (Graph B):**

```
0 1 1 0
0 0 0 1
0 0 0 1
0 0 0 0
```

The only difference from Exercise 1 is that the line `mat[v][u] = 1;` is removed, so the matrix is not symmetric.

### Exercise 3: Weighted Matrix

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));   // 0 = no edge

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;          // store the weight instead of 1
        mat[v][u] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
```

**Output (Graph C):**

```
0 5 3 0
5 0 0 2
3 0 0 7
0 2 7 0
```

---

## Part B: Adjacency List

### Exercise 4: Undirected List

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);     // adj[u] = list of neighbors of u

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);            // undirected: both directions
    }

    for (int u = 1; u <= n; u++) {
        cout << u << ":";
        for (int v : adj[u]) cout << " " << v;
        cout << "\n";
    }
    return 0;
}
```

**Output (Graph A):**

```
1: 2 3
2: 1 3 4
3: 1 2 5
4: 2 5
5: 3 4
```

### Exercise 5: Directed List

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
        adj[u].push_back(v);            // directed: only u -> v
    }

    for (int u = 1; u <= n; u++) {
        cout << u << ":";
        for (int v : adj[u]) cout << " " << v;
        cout << "\n";
    }
    return 0;
}
```

**Output (Graph B):**

```
1: 2 3
2: 4
3: 4
4:
```

Vertex 4 has no outgoing edge, so its list is empty and only `4:` is printed.

### Exercise 6: Weighted List

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);   // pair = (neighbor, weight)

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int u = 1; u <= n; u++) {
        cout << u << ":";
        for (auto [v, w] : adj[u]) cout << " (" << v << "," << w << ")";
        cout << "\n";
    }
    return 0;
}
```

**Output (Graph C):**

```
1: (2,5) (3,3)
2: (1,5) (4,2)
3: (1,3) (4,7)
4: (2,2) (3,7)
```

---

## Part C: Basic Graph Concepts

### Exercise 7: Degree of Every Vertex

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
        int degree = adj[u].size();     // degree = number of neighbors
        cout << "Degree of " << u << ": " << degree << "\n";
        sum += degree;
    }

    cout << "Sum of degrees = " << sum << ", 2 * edges = " << 2 * m << "\n";
    return 0;
}
```

**Output (Graph A):**

```
Degree of 1: 2
Degree of 2: 3
Degree of 3: 3
Degree of 4: 2
Degree of 5: 2
Sum of degrees = 12, 2 * edges = 12
```

### Exercise 8: In-degree and Out-degree

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);        // indeg[v] = number of edges coming into v

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);            // directed edge u -> v
        indeg[v]++;                     // v receives one incoming edge
    }

    for (int u = 1; u <= n; u++) {
        cout << "Vertex " << u << ": in = " << indeg[u]
             << ", out = " << adj[u].size() << "\n";
    }
    return 0;
}
```

**Output (Graph B):**

```
Vertex 1: in = 0, out = 2
Vertex 2: in = 1, out = 1
Vertex 3: in = 1, out = 1
Vertex 4: in = 2, out = 0
```

### Exercise 9: Edge Check

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    int a, b;
    cin >> a >> b;                      // the pair we want to check

    if (mat[a][b] == 1) cout << "Yes\n";    // one lookup: O(1)
    else cout << "No\n";
    return 0;
}
```

**Output:** Graph A followed by `2 4` prints `Yes`. Graph A followed by `1 4` prints `No`.

---

## Challenge (Optional)

### Exercise 10: Matrix to List

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;                   // read the cell mat[i][j]
            if (x == 1) adj[i].push_back(j);
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << u << ":";
        for (int v : adj[u]) cout << " " << v;
        cout << "\n";
    }
    return 0;
}
```

**Output:**

```
1: 2 3
2: 1 4
3: 1 4
4: 2 3
```

We never need to store the matrix. Each cell is read and used immediately.

### Exercise 11: Vertex with the Highest Degree

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

    int best = 1;                               // best vertex so far
    for (int u = 2; u <= n; u++) {
        if (adj[u].size() > adj[best].size()) best = u;   // ">" keeps the smallest vertex on a tie
    }

    cout << "Vertex " << best << " has the highest degree: " << adj[best].size() << "\n";
    return 0;
}
```

**Output (Graph A):**

```
Vertex 2 has the highest degree: 3
```

Vertices 2 and 3 both have degree 3. Because we use `>` and not `>=`, vertex 2 (the smaller one) stays as the answer.
