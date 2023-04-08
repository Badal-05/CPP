#include<stack>
#include<iostream>
using namespace std;
stack<int> stck;
bool found=false;
void print()
{
	stack<int> temp;
	while(!stck.empty())
	{
		temp.push(stck.top());
		stck.pop();
	}
	while(!temp.empty())
	{
		cout<<temp.top()<<" ";
		stck.push(temp.top());
		temp.pop();
	}
	
}

void solve(int curr,int ind,int a[],int tar,int n)
{
	if(curr>tar)
	  return;
	if(curr==tar)
	{
		found=true;
        cout<<"The combinations are: \n";
		print();
        cout<<endl;
		return;
	}
	for(int i=ind;i<n;i++)
	{
		stck.push(a[i]);
		solve(curr+a[i],i+1,a,tar,n);
		stck.pop();
	}
}

main()
{
	// int a[]={1,3,5,2};
    // int n=4,tar=6;
    int n,target;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the target sum: ";
    cin>>target;
    int a[n];
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Enter the number: ";
        cin>>a[i];
    }
    solve(0,0,a,target,n);
	if(found==false)
	  cout<<"no solution";
	return 0;
}