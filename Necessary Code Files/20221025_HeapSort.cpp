#include<iostream>
#define SZ 10000
using namespace std;

struct Heap{
    int heap[SZ], cnt;
    Heap(){
        cnt=0;
    }
    void insertIntoHeap(int);
    int deleteRootHeap();
    void printHeap();
};

void Heap::insertIntoHeap(int x){
    heap[++cnt] = x;
    int child = cnt;
    int par = (child>>1);
    while(par>0){
        if(heap[child] > heap[par])
            swap(heap[child], heap[par]);
        else return;
        child = par;
        par>>=1;
    }
}

int Heap::deleteRootHeap(){
    if(cnt==0){
        cout << "Underflow!\n";
        return -1;
    }
    int par = 1;
    swap(heap[par], heap[cnt]);
    int ret = heap[cnt--];
    int lchild=(par<<1), rchild=lchild+1, mxind;

    while(lchild<=cnt){
        if(rchild<=cnt){
            mxind = heap[lchild]>=heap[rchild]?lchild: rchild;
        }
        else mxind = lchild;

        if(heap[mxind]>heap[par])
            swap(heap[mxind],heap[par]);
        else return ret;
        par = mxind;
        lchild=(par<<1);
        rchild=lchild+1;
    }
    return ret;
}

void Heap::printHeap(){
    for (int i = 1; i<=cnt; i++)
        cout << heap[i] << " \n"[i==cnt];
}

void HeapSort(int arr[], int n, int ascending){
    Heap hp;
    for (int i = 0; i<n; i++)
        hp.insertIntoHeap(arr[i]);
    for (int i = 0; i<n; i++)
        arr[ascending?n-i-1:i] = hp.deleteRootHeap();
}

int main()
{
    int n, arr[SZ];
    cin >> n;

    for (int i = 0; i<n; i++)
        cin >> arr[i];

    HeapSort(arr,n,1);

    cout << "Sorted Array with Heap Sort:\n";

    for (int i = 0; i<n; i++)
        cout << arr[i] << " \n"[i==n-1];

    return 0;
}
/**
10
454 545 96 -955 75 85 10 6 0 -84
*/

















