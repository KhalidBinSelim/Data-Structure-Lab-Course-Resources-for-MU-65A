#include <iostream>
#define sz 40000
using namespace std;

int tree[sz];

void update(int,int,int,int,int);
int query(int,int,int,int,int);

void update(int ind, int lb, int ub, int pos, int val){
    if(lb==ub){
        if(lb == pos) tree[ind] = val;
        return;
    }
    int mid = ((lb+ub)>>1);
    if(pos<=mid) update((ind<<1),lb,mid,pos,val);
    else update((ind<<1)+1,mid+1,ub,pos,val);
    tree[ind] = tree[(ind<<1)] + tree[(ind<<1)+1];
}

int query(int ind, int lb, int ub, int qlb, int qub){
    if(qlb<=lb && ub<=qub) return tree[ind];
    if(qub<lb || ub<qlb) return 0;

    int ret = 0;
    int mid = ((lb+ub)>>1);
    ret += query((ind<<1),lb,mid,qlb,qub);
    ret += query((ind<<1)+1,mid+1,ub,qlb,qub);
    return ret;
}

int main()
{
    int n, q, x, y, k;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> x;
        update(1,0,n-1,i,x);
    }

    cin >> q;
    for (int i = 0; i<q; i++)
    {
        cin >> k >> x >> y;
        if(k==1)
            cout << query(1,0,n-1,x,y) << "\n";
        else
            update(1,0,n-1,x,y);
    }
    return 0;
}
/**
5
6 8 12 -9 2
8
1 0 4
2 2 4
1 0 4
1 1 4
1 0 3
2 0 17
1 0 0
1 0 4
*/

















