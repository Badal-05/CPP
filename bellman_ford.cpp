// will run only n-1 times. We will check one more time to check for negative weight cycles.
#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int source,dest; float wt;
};

int main()
{
    int v,e;
    cout<<"Enter number of vertices ";
    cin>>v;
    cout<<"Enter number of edges ";
    cin>>e;
    struct edge edges[e];
    int d[v],start;
    cout<<"Enter the source vertex ";
    cin>>start;
    cout<<"Enter the source, destination and weight of each edge\n";
    for(int i=0;i<e;i++)
    {
        cin>>edges[i].source>>edges[i].dest>>edges[i].wt;
    }
    for(int i=0;i<v;i++)
    {
        d[i]=INT_MAX;
    }
    d[start-1]=0;
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u=edges[j].source;
            int v=edges[j].dest;
            float w=edges[j].wt;
            if(d[v-1]>d[u-1]+w)
            {
                d[v-1]=d[u-1]+w;
            }
        }
    }
    int flag=0;        
    for(int j=0;j<e;j++)
    {
        int u=edges[j].source;
        int v=edges[j].dest;
        float w=edges[j].wt;
        if(d[v-1]>d[u-1]+w)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        for(int i=0;i<v;i++)
        {
            if(d[i]<100000)
            {
                cout<<start<<" -> "<<i+1<<" shortest path is "<<d[i]<<"\n";
            }
            else
            {
                cout<<start<<" -> "<<i+1<<" shortest path is infinity\n";
            }
        }
    }
    else
    {
        cout<<"No solution -ve weight cycle";
    }
    return 0;
}