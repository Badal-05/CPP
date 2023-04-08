#include<iostream>
#include<stdlib.h>
using namespace std;

int max(int a, int b)
{
    return (a>b?a:b);
}

int crossSum(int a[],int high , int mid, int low)
{
    int left = INT8_MIN; int s = 0;
    for(int i = mid ; i >= low; i--)
    {
        s += a[i];
        if(s>left)
        {
            left = s;
        }
    }
    s=0;
    int right = INT8_MIN ;
    for(int i  = mid+1 ; i <= high ; i++)
    {
        s+= a[i];
        if(s > right)
        {
            right = s;
        }
    }
    return left+right;
}

int maxSum(int a[], int low, int high)
{
    
    if(low==high)
    {
        return a[low];
    }
    int mid = (low + high)/2;
    int temp = max(maxSum(a,low,mid),maxSum(a,mid+1,high));
    return max(crossSum(a,high,mid,low),temp);
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the number: ";
	    cin>>arr[i];
    }
    cout<<"The Maximum subarray sum is: "<<maxSum(arr,0,n-1);
}