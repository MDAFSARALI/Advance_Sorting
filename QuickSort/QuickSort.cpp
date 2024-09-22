#include <iostream>
using namespace std;
int Partition(int arr[], int si, int ei)
{
    int pivotElement = arr[si];
    int count = 0;
    for (int i = si+1; i <= ei; i++)
    {
        if (arr[i]<= pivotElement  )
            count++;
    }
    int pivotIdx = si + count;
    swap(arr[si],arr[pivotIdx]);
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
void QuickSort(int arr[], int si, int ei)
{
    if (si >= ei)
        return;
    int pi = Partition(arr, si, ei);
    QuickSort(arr, si, pi - 1);
    QuickSort(arr, pi + 1, ei);
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
    QuickSort(arr, 0, n);
    cout << "Printing the Sorted Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}