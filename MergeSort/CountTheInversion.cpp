#include <iostream>
#include <vector>
using namespace std;
int c = 0;
int Inversion(vector<int> &v1, vector<int> &v2)
{
    int i = 0, j = 0, count = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] > v2[j])
        {
            count += (v1.size() - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return count;
}
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
    c += Inversion(v1, v2);
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
    cout << endl;
    cout << "No of Inversion is : " << endl;
    cout << c << endl;

    return 0;
}