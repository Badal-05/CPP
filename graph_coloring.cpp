#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj = {
        { 0,1,1,0,0 },
        { 1,0,1,0,1 },
        { 1,1,0,1,1 },
        { 0,0,1,0,1,},
		{ 0,1,1,1,0 },
    };


bool isSafe(int v, int c,vector<vector<int>>adj,int color[],int n)  
{
    for (int i = 0; i < n; i++)
        if (adj[v][i] && c == color[i])
            return false;
    return true;
}

bool solve(int v,int color[],vector<vector<int>>adj,int n,int m)
{
      if (v == n)
        return true;
    for (int i = 1; i <= m; i++)  
    {
        if (isSafe(v,i,adj,color,n)) {
            color[v] = i;
            if (solve( v + 1,color,adj,n,m) == true) 
                return true;
            color[v] = 0; 
        }
    }  
    return false;
}
  
void print(int color[],int n)
{
    cout << "assigned colors are \n";
    for (int i = 0; i < n; i++)
        cout << "vertex "<<i <<" -> " <<color[i] << "\n "; 
}
int main()
{
    int n,m;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    int color[n];
    cout<<"How many colors ?: ";
    cin>>m;
    adj.resize(n,vector<int>(n));
    cout<<"Enter the values of adjacency matrix: "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>adj[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        color[i] = 0;
    if (solve(0,color,adj,n,m) == false) 
        cout << "Solution does not exist";
    else
      print(color,n);
    return 0;
}