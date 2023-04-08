#include<bits/stdc++.h>
using namespace std;

struct point{
	int x,y;
};

int direction(point p, point q, point r){
	int res = ((r.x - p.x)*(q.y - p.y)) - ((r.y-p.y)*(q.x-p.x));
	if(res==0)
	{
		return 0;
	}
	return res>0?1:2;
}

void convex(point p[],int n)
{
	if(n<3)
	{
		return;
	}
	bool included[n];
	for(int i = 0 ; i<n; i++)
	{
		included[i] = false;
	}
	int left = 0;
	for(int i = 1; i<n; i++)
	{
		if(p[i].x < p[left].x)
		{
			left = i;
		}
	}
	int curr,prev = left;
	
	do{
		curr = (prev+1)%n;
		for(int i = 0 ; i < n; i++)
		{
			if(direction(p[prev],p[curr],p[i])==2)
			{
				curr = i;
			}
		}
		included[prev] = true;
		prev = curr;
	}while(prev!=left);
	cout<<"The included points in convex hull are: "<<endl;
	for(int i = 0 ; i< n; i++)
	{
		if(included[i]==true)
		{
			cout<<"("<<p[i].x <<","<<p[i].y<<")"<<endl;
		}
	}
}

int main()
{
	struct point p[20];
	int n;
    cout<<"Enter the number of points: ";
	cin>>n;
    cout<<endl<<"Enter the coordinates (x,y)"<<endl;
	for(int i = 0; i<n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	convex(p,n);
}