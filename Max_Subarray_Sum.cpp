#include<iostream>
#include<stdlib.h>
using namespace std;

int max(int a, int b)
{
    return (a>b?a:b);
}

int crossSum(int a[],int lower,int mid, int higher)
{
    // calculating the left sum 
    int s=0;
    int left = INT16_MIN;
    for(int i = mid; i>=lower;i--)
    {
        s+=a[i];
        if(s>left){
            left = s;
        }
    }

    //calculating the right sum
    s=0;
    int right = INT16_MIN;
    for(int i = mid+1; i<=higher ;i++)
    {
        s+=a[i];
        if(s>right){
            right = s;
        }
    }

    return(left+right);
}

int maxSum(int a[],int lower, int higher)
{
    if(lower == higher){
        return a[lower];
    }
    // calculate mid to partision the main array into two parts.
    int mid=(lower+higher)/2;
    int temp = max(maxSum(a,lower,mid),maxSum(a,mid+1,higher));
    //maxSum(a,lower,mid) is the left subarray
    //maxSum(a,mid+1,higher) is the right subarray
    return(max(crossSum(a,lower,mid,higher),temp));
    // we will return the biggest out of :
    //LeftSum (maxSum of left subarray) 
    //RightSum (maxSum of right subarray)
    //CrossSum
}

int main(){
    int n;
    printf("Enter the number of elements you want in the main array\n");
    cin>>n;
    int a[n];
    printf("Enter the elements of the main array\n");
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    int size = (sizeof(a)/sizeof(int)); // or simply use 'n'
    cout<<"The Maximum sum which can be achieved in this array is "<<maxSum(a,0,size-1)<<endl;
    // since sizeof returns size in bytes, we divide it by size of int(ie, 4) to get the size of the array
}