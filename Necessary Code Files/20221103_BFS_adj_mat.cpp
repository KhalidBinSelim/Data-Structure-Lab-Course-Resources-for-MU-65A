#include<iostream>
#include<queue>
#define sz 1000
using namespace std;
int cc[]={1,-1,0,0};
int rr[]={0,0,-1,1};


int adj[sz][sz], col[sz][sz];

int bfs(int x, int y, int n, int m){
    queue < pair<int,int> > q;
    q.push(make_pair(x,y));
    col[x][y] = 1;

    int u, v;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(adj[x][y] == 2){
            cout << "Exit point: (" << x <<"," << y <<")\n";
            return col[x][y] - 1;
        }
        for (int k = 0; k<4; k++){
            u = x+cc[k];
            v = y+rr[k];
            if(u<0||v<0||u>=n||v>=m||col[u][v])
                continue;
            col[u][v] = col[x][y] + 1;
            q.push({u,v});
        }
    }
    cout << "Robot Lost in Eternity!\n";
    return -1;
}

int main()
{
    int n, m, x, y, k, w, z;
    cin >> n >> m;
    cin >> x >> y;
    adj[x][y] = 1;
    cin >> k;
    for (int i = 0; i<k; i++)
    {
        cin >> w >> z;
        adj[w][z] = 2;
    }
    int move = bfs(x,y,n,m);
    cout << "Required Moves to Reach Exit Point = " << move << "\n";
    return 0;
}
/**
6 7
4 1
4
2 0
1 2
0 4
3 5

6 7
4 1
4
0 6
1 2
0 4
3 5
*/
