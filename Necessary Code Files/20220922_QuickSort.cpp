#include<iostream>
#define sz 1000
using namespace std;


int quicksort_partition(int arr[], int left, int right)
{
    bool r = true;

    while(left<right)
    {
        if(arr[left] > arr[right])
        {
            swap(arr[left], arr[right]);
            r ^= 1; /// if(r==1) r = false; else r = true;
        }
        if(r) right--;
        else left++;
    }
    return right;
}

void quicksort(int arr[], int left, int right)
{
    if(left >= right) return;

    int p = quicksort_partition(arr,left,right);
    quicksort(arr,left,p-1);
    quicksort(arr,p+1,right);
}

int main()
{
    int n, arr[sz];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr,0,n-1);

    cout << "Sorted Array after implementing Quick Sort:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " \n"[i==n-1];

    return 0;
}
/**
15
45 78 645 -49 0 468 5 41 65 -7 54 21 78 -6 8
*/
