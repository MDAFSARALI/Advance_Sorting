#include <iostream>
using namespace std;
int Partition(int arr[], int si, int ei)
{
    int pivotElement = arr[(si+ei)/2];
    int count = 0;
    for (int i = si; i <= ei; i++)
    {
        if(i==(si+ei)/2)continue;
        if (arr[i]<= pivotElement  )
            count++;
    }
    int pivotIdx = si + count;
    swap(arr[(si+ei)/2],arr[pivotIdx]);
    int i = si, j = ei;
    while (i < pivotIdx && j > pivotIdx)
    {
        if (arr[i] <= pivotElement)
            i++;
        if (arr[j] > pivotElement)
            j--;
        else if (arr[i] > pivotElement && arr[j] <= pivotElement)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}
int KthSmallest(int arr[], int si, int ei,int k)
{
    int pi = Partition(arr, si, ei);
    if (pi+1 == k) return arr[pi];
    else if (pi+1  < k ) KthSmallest(arr, pi + 1, ei,k);
    else return KthSmallest(arr, si, pi - 1,k);
}
int main()
{
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the values in the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout<<"Enter the value of k :"<<endl;
    cin>>k;
    cout << "Printing the kth smallest element  " << KthSmallest(arr, 0, n,k)<< endl;
    
}