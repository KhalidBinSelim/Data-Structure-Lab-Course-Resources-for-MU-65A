#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define sz 10000
using namespace std;

vector<int>adj[sz];
bool vis[sz];
int par[sz];

int bfs(int s, int d, int n){
    queue< pair<int,int> > q; /// node, cost
    q.push({s,0});
    vis[s] = 1;
    memset(par,-1,sizeof(int)*n);

    int x, cost;
    while(!q.empty()){
        x = q.front().first;
        cost = q.front().second;
        q.pop();
        if(x==d) return cost;
        for(auto &now:adj[x]) /// for(int i = 0; i<adj[x].size(); i++)
            if(!vis[now]){
                q.push({now, cost+1});
                vis[now]=1;
                par[now]=x;
            }
    }
    return -1;
}

int main()
{
    int n, m, s, d, x, y;
    cin >> n >> m;
    cin >> s >> d;
    for (int i = 0; i<m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ret = bfs(s,d,n);
    cout << "Min cost from " << s << " to " << d << " = " << ret << "\n";

    vector<int>ans;
    x = d;
    while(~x){
        ans.push_back(x);
        x = par[x];
    }
    reverse(ans.begin(), ans.end());

    cout << "Path: ";
    for (int i = 0; i<ans.size(); i++)
        cout << ans[i] << ",\n"[i==ans.size()-1];
    return 0;
}
/**
7 8
5 6
0 1
0 2
0 4
1 2
1 6
2 3
3 6
4 5

7 8
5 1
0 1
0 2
0 4
1 2
1 6
2 3
3 6
4 5
*/
