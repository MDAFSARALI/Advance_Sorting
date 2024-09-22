/*
Problem : 01 
In quick sort it uses the concept of insertion sort .

Problem : 02
It is always divide the array into two parts not necessarily of equal size  

*/
#include<iostream>
using namespace std;
void Problem3(int arr[],int n){
    int idx1=-1,idx2=-1;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1]){
            if(idx1==-1) {
                idx1=i;
                idx2=i+1;
            }
            else idx2=i+1;
        }
    }
    swap(arr [idx1],arr[idx2]);
}
int main(){
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the values in the array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Problem3(arr,n);
    cout<<"Array after solving  :"<<endl;
    for (int i = 0; i < n; i++)
    {
       cout<<arr[i] <<" ";
    }
    
}