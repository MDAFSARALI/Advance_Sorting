# Advance_Sorting

## Merge Sort 
```C++
#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int> &v1, vector<int> &v2, vector<int> &v)
{
    int i = 0, j = 0, k = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            v[k++] = v1[i++];
        }
        else
        {
            v[k++] = v2[j++];
        }
    }
    if (i == v1.size())
    {
        while (j < v2.size())
        {
            v[k++] = v2[j++];
        }
    }

    if (j == v2.size())
    {
        while (i < v1.size())
        {
            v[k++] = v1[i++];
        }
    }
}
void MergeSort(vector<int> &v)
{
    int n = v.size();
    if (n == 1)
        return;
    int n1 = n / 2, n2 = (n - n / 2);
    vector<int> v1(n1), v2(n2);
    for (int i = 0; i < n1; i++)
    {
        v1[i] = v[i];
    }
    for (int j = 0; j < n2; j++)
    {
        v2[j] = v[j + n1];
    }
    MergeSort(v1);
    MergeSort(v2);
    Merge(v1, v2, v);
    v1.clear();
    v2.clear();
}
int main()
{
    int size;
    cout << "Enter the size vector : " << endl;
    cin >> size;
    vector<int> v(size);
    cout << "Enter the elements in the vectors : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    cout << "Printing the provided vector : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    MergeSort(v);
    cout << "Printing the Sorted vector : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
```

## Quick Sort 
```C++
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
```