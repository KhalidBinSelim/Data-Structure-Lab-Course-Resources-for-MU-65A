#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define sz 1000
using namespace std;


vector<int> adj[sz], cost[sz];
int par[sz];

int find_par(int n){
    if(par[n]==n) return n;
    return par[n] = find_par(par[n]);
}

int mst_prims(int st, int n){
    priority_queue <  pair<int, pair<int,int> >,
    vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > >
    > pq;
    vector< pair<int, pair<int, int> > > ans;
    int p, q;
    for (int i = 0; i < adj[st].size(); i++){
        p = min(st, adj[st][i] );
        q = max(st, adj[st][i] );
        pq.push({cost[st][i], {p, q}});
    }

    int w, u, v, total = 0, pst, z;
    while(!pq.empty()){
        w = pq.top().first;
        p = pq.top().second.first;
        q = pq.top().second.second;
        pq.pop();

        u = find_par(p);
        v = find_par(q);
        pst=find_par(st);

        if(u!=v){
            ans.push_back(pq.top());
            total += w;
            z = pst!=u?p:q;
            par[u] = v;
            for (int i = 0; i < adj[z].size(); i++){
                p = min(st, adj[z][i] );
                q = max(st, adj[z][i] );
                pq.push({cost[z][i], {p, q}});
            }
        }
    }

    if(ans.size()!=n-1){
        cout << "It seems the initial graph is disconnected!\n";
        return -1;
    }

    cout << "Edge List in MST (Prims):\n";

    for (auto &x: ans){
        w = x.first;
        p = x.second.first;
        q = x.second.second;
        cout << "(" << p << "," << q << ") -> " << w << "\n";
    }
    return total;
}


void mst_init(int n){
    for (int i = 1; i<=n; i++)
        par[i]=i;

}

int main()
{
    int n, m, x, y, z;
    cin >> n >> m;
    mst_init(n);

    for (int i = 0; i<m; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
    }
    z = mst_prims(1,n);
    cout << "Total Weight = " << z << endl;
    return 0;
}
/**
6 9
1 2 2
1 5 1
1 4 1
2 3 3
2 5 2
3 5 1
3 6 5
4 6 2
5 6 3

7 10
1 2 2
1 5 1
1 4 1
2 3 3
2 5 2
3 5 1
3 6 5
4 6 2
5 6 3
3 7 10
*/
