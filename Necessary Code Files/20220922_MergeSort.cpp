#include<iostream>
#include<vector>
#define sz 1000
using namespace std;

/// int arr[2][sz];

void merge(vector<int>&arr, int st, int en, int mid)
{
    vector<int>temp(arr.size()); /// en - st + 1
    int i, j;

    for (i = st; i<=en; i++)
        temp[i] = arr[i];

    int n = mid - st + 1, m = en - mid, k = st; /// m = en - mid
    i = j = 0;
    while(i<n && j<m)
    {
        if(temp[st + i] <= temp[mid+1 + j])
            arr[k++] = temp[st + i++];
        else
            arr[k++] = temp[mid+1 + j++];
    }
    while(i<n)
        arr[k++] = temp[st + i++];
    while(j<m)
        arr[k++] = temp[mid+1 + j++];
}

void mergesort(vector<int>&arr,int st, int en)
{
    if(st >= en) return;
    int mid = ((st+en)>>1);
    mergesort(arr,st,mid);
    mergesort(arr,mid+1,en);

    merge(arr,st,en,mid);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergesort(arr,0,n-1);

    cout << "Sorted Array after implementing Merge Sort:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " \n"[i==n-1];

    return 0;
}
/**
15
45 78 645 -49 0 468 5 41 65 -7 54 21 78 -6 8
*/
