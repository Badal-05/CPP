#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
   int id;
   int state; //status
   int pred; //predecessor
}node;

/*
int res[n][n] = {
   {0, 16, 13, 0, 0, 0},
   {0, 0, 10, 12, 0, 0},
   {0, 4, 0, 0, 14, 0},
   {0, 0, 9, 0, 0, 20},
   {0, 0, 0, 7, 0, 4},
   {0, 0, 0, 0, 0, 0}    //maxflow=23
}; 

int res[n][n]={
{0,3,2,0},{0,0,5,2},{0,0,0,3},{0,0,0,0}
};
*/
vector<vector<int>> res = {
   {0, 10, 0, 10, 0, 0},
   {0, 0, 4, 2, 8, 0},
   {0, 0, 0, 0, 0, 10},
   {0, 0, 0, 0, 9, 0},
   {0, 0, 6, 0, 0, 10},
   {0, 0, 0, 0, 0, 0}  //maxflow=19
};
                  
bool bfs(node vert[], node source, node sink,int n) {
   node u;
   int i, j;
   queue<node> q;

   for(i = 0; i<n; i++) {
      vert[i].state = 0;    
   }

   vert[source.id].state = 1;   //source is visited
   vert[source.id].pred = -1;   //no parent for source
   q.push(source);   //enqueue source node

   while(!q.empty()) {
      u = q.front();
      q.pop();
      for(i = 0; i<n; i++) {
         if(res[u.id][i] > 0 && vert[i].state == 0) {
            q.push(vert[i]);
            vert[i].pred = u.id;
            vert[i].state = 1;
         }
      }
   } // end of while
   return (vert[sink.id].state == 1);
}
int main() {
   int n;
   cout<<"Enter the number of nodes: ";
   cin>>n;
   res.resize(n,vector<int>(n));
    cout<<"Enter the initial capacity values for: \n"<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cout<<"Edge "<<i<<"-"<<j<<": ";
            cin>>res[i][j];
        }
    }
   node vert[n];
   node source, sink;
   for(int i = 0; i<n; i++) {
      vert[i].id = i;
   }

   source.id = 0;
   sink.id = n-1;
   int maxflow = 0;
   int u, v;

   while(bfs(vert, source, sink,n)) {    //find augmented path using bfs 
      int augflow = INT_MAX;
      for(v = sink.id; v != source.id; v=vert[v].pred) {
         u = vert[v].pred;
         augflow = augflow<res[u][v]?augflow:res[u][v];
      }
      for(v = sink.id; v != source.id; v=vert[v].pred) {
         u = vert[v].pred;
         res[u][v] -= augflow;   //update residual capacity of edges
         res[v][u] += augflow;   //update residual capacity of reverse edges
      }
  /* cout<<"residue graph after each iteration\n";
      for(int i = 0; i<n; i++) {
      for(int j = 0; j<n; j++) {
         cout<< res[i][j]<<" ";}
      cout<<"\n";}*/
      maxflow += augflow;
   } //while
   cout << "\nMaximum flow is: " << maxflow << endl;
}