#include <bits/stdc++.h> 
using namespace std;
  

void leftRotate(int *a, int d, int n) 
{ 
    d=d%n;
    if(d==n || d==0) return;
    for(int i=0;i<n-d;i++)
    {
        swap(a[i],a[i+d]);
    }
    if(n%d!=0)  leftRotate(&a[n-d],d-n%d,d);
} 

void rightRotate(int *a, int d, int n) 
{ 
    leftRotate(a,n-d%n,n);
} 

void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
        cout<<endl;
} 


int main() 
{   for(int i=0;i<12;i++)//i==no. of left rotation
    {
        int arr[] = { 1, 2, 3, 4, 5 ,6,7,8,9,10}; 
        int n = sizeof(arr) / sizeof(arr[0]); 
 
        rightRotate(arr,i, n); 
        cout<<i<<"  :::  ";
        printArray(arr, n); 
    }
    return 0; 
} 








/*
O/P:


0  :::  1 2 3 4 5 6 7 8 9 10 
1  :::  10 1 2 3 4 5 6 7 8 9 
2  :::  9 10 1 2 3 4 5 6 7 8 
3  :::  8 9 10 1 2 3 4 5 6 7 
4  :::  7 8 9 10 1 2 3 4 5 6 
5  :::  6 7 8 9 10 1 2 3 4 5 
6  :::  5 6 7 8 9 10 1 2 3 4 
7  :::  4 5 6 7 8 9 10 1 2 3 
8  :::  3 4 5 6 7 8 9 10 1 2 
9  :::  2 3 4 5 6 7 8 9 10 1 
10  :::  1 2 3 4 5 6 7 8 9 10 
11  :::  10 1 2 3 4 5 6 7 8 9 

*/
