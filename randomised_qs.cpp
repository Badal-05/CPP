#include<bits/stdc++.h>
#include<ctime>

using namespace std;

void quick(int a[],int left, int right);

int main()
{
    int n,i;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"Enter the values: \n";
    int a[n];
    for(i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    quick(a,0,n-1);
    cout<<"The sorted array is \n";
    for(i = 0; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }   
    return 0;
}

void quick(int a[], int left, int right)
{
    int temp;
    if(left >= right)
        return;
    srand(time(NULL));
    int pivot = (rand()%(right - left + 1)) + left;
    int l = left; 
    int r = right;
    while(l<r)
    {
        while(a[r]>a[pivot])
            r--;
        while(a[l]<=a[pivot])
            l++;
        if(l<r)
        {
            temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
    temp = a[pivot];
    a[pivot] = a[r];
    a[r] = temp;
    quick(a,left,r-1);
    quick(a,r+1,right);
}

