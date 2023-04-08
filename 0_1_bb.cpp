#include<bits/stdc++.h>
#define n 4
int cap = 15;
using namespace std;
struct node
{
	int level;
	float UB,LB;
	bool included[n];
    bool islive;
	node()
	{
	}
	node(int nodelevel,bool parent[],bool incstatus)
	{   islive=true;
		level=nodelevel;
		for(int i=0;i<n;i++)
		 included[i]=parent[i];
		if(nodelevel>=0)
		included[nodelevel]=incstatus;
	}
};
queue<node> q;
struct item
{
	float w,v,ratio;
	item()
	{
		w=0;v=0;
	}
	item(float ww,float vv)
	{
		w=ww; v=vv; ratio=v/w;
	}
}items[n];

bool compare(item a, item b)
{
	return a.ratio>b.ratio;
}
node calcfirstnodebound(node curr)
{
	curr.UB=0;
	curr.LB=0;
	float totwt=0,totval=0;
	for(int i=0;i<n;i++)
	{
		if(totwt>=cap)
		  break;
		if(totwt+items[i].w<=cap)
		{
	    	totwt+=items[i].w;
	    	totval+=items[i].v;
	    	curr.UB=totval;
	    	curr.LB=totval;
	    }
	    else
	    {
	     totval+=(cap-totwt)*items[i].v/items[i].w;
	     curr.LB=totval;
	     break;
		}
	    }
	curr.UB*=(-1);
	curr.LB*=(-1);
	return curr;
}
node calcbound(node curr)
{
    curr.UB=0;
	curr.LB=0;
	float totwt=0,totval=0;
	for(int i=0;i<n;i++)
	{
		if(totwt>=cap)
		  break;
		if(curr.included[i])
		{
		if(totwt+items[i].w<=cap)
		{
	    	totwt+=items[i].w;
	    	totval+=items[i].v;
	    	curr.UB=totval;
	    	curr.LB=totval;
	    	if(i<=curr.level)
	    	  continue;
	    }
	    else
	    {
	     totval+=(cap-totwt)*items[i].v/items[i].w;
	     curr.LB=totval;
	     break;     
		}
	    }
	    
	}
	curr.UB*=(-1);
	curr.LB*=(-1);
	return curr;
	
}
int main()
{
	float w[]={2,4,6,9}; //{2,3,4,5}; //{24,10,10,7};
	float v[]={10,10,12,18}; //{3,4,5,6}; //{24,18,18,10};
	for(int i=0;i<n;i++)
	  items[i]=item(w[i],v[i]);
	sort(items,items+n,compare);
	cout<<"Ratio of items ";
	for(int i=0;i<n;i++)
	  cout<<items[i].ratio<<" ,";
	cout<<"\n";
	int firstnodelevel=-1;
    bool firstnode_inc[n];
	for(int i=0;i<n;i++) firstnode_inc[i]=true;
	node currnode(firstnodelevel,firstnode_inc,true);
	currnode=calcfirstnodebound(currnode);
	q.push(currnode);
	float globalUB=currnode.UB;
	node e_node,lastnode;
    do
	{
	  e_node=q.front();
	  q.pop();
	  e_node=calcbound(e_node);
	  if(e_node.UB<globalUB)
	    globalUB=e_node.UB;  
	  if(e_node.LB<=globalUB && e_node.level<n)
	  {
	    node left(e_node.level+1,e_node.included,true);
	    node right(e_node.level+1,e_node.included,false);
	    int wtsum=0;
	    for(int i=0;i<=left.level;i++)
	    if(left.included[i])
	      wtsum+=items[i].w;
	    if(wtsum<=cap)
	    q.push(left);
	    wtsum=0;
	    for(int i=0;i<=right.level;i++)
	    if(right.included[i])
	      wtsum+=items[i].w;
	    if(wtsum<=cap)
	      q.push(right);
	  }
	  else
	    e_node.islive=false;
	  if (e_node.islive)  
	    lastnode=e_node;
    }  while(!q.empty());	
    cout<<"Weights of the included items are\n";
	 for(int i=0;i<n;i++)
	   if(lastnode.included[i])
	    cout<<items[i].w <<" ";
	  cout<<"\n";
	  cout<<"UB= "<<lastnode.UB<<" LB= "<<lastnode.LB<<"\n";
	  cout<<"maximum profit is "<<lastnode.UB*-1;  
	return 0;
}