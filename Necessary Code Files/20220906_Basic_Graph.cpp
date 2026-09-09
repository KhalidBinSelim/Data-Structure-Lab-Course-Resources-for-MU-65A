#include <iostream>
#include <cmath>
#include <vector>
#define SZ 1000
using namespace std;

vector<int>adj[SZ], cost[SZ];

int main()
{
    int n, m, x, y, z;
    cin >> n >> m;
    for (int i = 0; i<m; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(y);
        cost[x].push_back(z);
    }
    for (int i = 0; i<n; i++)
    {
        cout << i <<": ";
        for (int j = 0; j<adj[i].size(); j++)
            cout << adj[i][j] << ",\n"[j==adj[i].size()-1];
        if(adj[i].size()==0)cout << "\n";
    }

    return 0;
}
/**
10 9
1 2 5
1 3 3
6 4 1
6 5 5
4 3 2
5 3 1
7 8 9
8 9 3
10 3 100
*/
