#include<iostream>
#include<vector>
#include<algorithm>
#define sz 1000
#define inf (1<<28)
using namespace std;

vector<int> adj[sz], w[sz];

int par[sz], cost[sz];

int bellmanford(int st, int en, int n){
    cost[st] = 0;
    for (int k = 1; k<n; k++)
        for (int i = 0; i<n; i++)
            for (int j = 0; j< adj[i].size(); j++)
                if(cost[i] + w[i][j] < cost[ adj[i][j] ]){
                    cost[ adj[i][j] ] = cost[i] + w[i][j];
                    par[ adj[i][j] ] = i;
                }

    for (int i = 0; i<n; i++)
        for (int j = 0; j< adj[i].size(); j++)
            if(cost[i] + w[i][j] < cost[ adj[i][j] ]){
                cout <<"Negative Cycle Detected!\nShortest path could not be determined!\n";
                return -inf;
            }
    return cost[en];
}


void init(int n){
    for (int i = 0; i<n; i++)
        par[i]=-1, cost[i] = inf;
}

int main()
{
    int x, y, z, n, m, st, en;
    cin >> n >> m;
    init(n);

    for (int i = 0; i<m; i++)
    {
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].push_back(y);
//        adj[y].push_back(x);
        w[x].push_back(z);
//        w[y].push_back(z);
    }

    cin >> st >> en;

    x = bellmanford(st-1,en-1,n);
    if(x==-inf){
//        cout << "Way to the eternity!\n";
        return 0;
    }
    cout << "The minimum path cost from " << st << " to " << en << " is " << x << endl;

    x = en-1;
    vector<int>res;

    while(~x){
        res.push_back(x+1);
        x = par[x];
    }
    reverse(res.begin(),res.end());

    cout << "The path: ";
    for (int i = 0; i<res.size(); i++)
        cout << res[i] << ",\n"[i==res.size()-1];



    return 0;
}
/**
7 10
1 3 1
1 4 6
2 6 1
4 2 2
2 7 5
3 6 8
3 4 2
5 4 9
5 6 2
7 5 1
1 7

6 10
1 2 3
1 3 -2
1 5 8
3 4 6
2 3 1
2 6 4
2 5 6
5 6 -5
4 6 -5
4 2 9
1 6

6 10
1 2 3
1 3 -2
1 5 8
3 4 6
2 3 1
2 6 4
2 5 6
5 6 -5
4 6 -5
4 2 -9
1 6

*/
