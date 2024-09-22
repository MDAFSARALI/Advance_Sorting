#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int> &a, vector<int> &b, vector<int> &Original)
{
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] >= b[j])
        {
            Original[k++] = a[i++];
        }
        else
        {
            Original[k++] = b[j++];
        }
    }
    if (i == a.size())
    {
        while (j < b.size())
        {
            Original[k++] = b[j++];
        }
    }
    if (j == b.size())
    {
        while (i < a.size())
        {
            Original[k++] = a[i++];
        }
    }
}
void MergeSort(vector<int> &Original)
{
    int n = Original.size();
    if (n == 1)
        return;
    int n1 = n / 2;
    int n2 = n - n / 2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++)
    {
        a[i] = Original[i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = Original[n1 + i];
    }

    MergeSort(a);
    MergeSort(b);
    Merge(a, b, Original);
    a.clear();
    b.clear();
}

int main()
{
    int size;
    cout << "Enter the size of the vector : " << endl;
    cin >> size;
    vector<int> Original(size);
    cout << "Enter the values in the vector : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> Original[i];
    }
    cout << "The original vector is : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Original[i] << " ";
    }
    MergeSort(Original);
    cout << endl;
    cout << "The vector after sorting is : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Original[i] << " ";
    }
    return 0;
}