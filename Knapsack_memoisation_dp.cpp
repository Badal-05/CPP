#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> dp(3,vector<int>(5));
float knapsack(int ind,int cap,float val[],int wt[],vector<vector<int>>dp)
{
         
    if(ind == 0){
        if(wt[0] <=cap) 
          return dp[0][cap] =val[0];
        else 
		  return dp[0][cap] =0;
    }
    
    if(dp[ind][cap]!=-1)
        return dp[ind][cap];
        
    int notinclude = 0 + knapsack(ind-1,cap,val,wt,dp);
    int include = INT_MIN;
    if(wt[ind] <= cap)
        include = val[ind] + knapsack(ind-1,cap-wt[ind],val,wt,dp);
    return dp[ind][cap] = include>notinclude?include:notinclude;
}

int main() {
    int n,cap;
    cout<<"Enter the number of observations: "<<endl;
    cin>>n;
    cout<<"Enter the capacity of the knapsack"<<endl;
    cin>>cap;
    float val[n];
    int wt[n];
    dp.resize(n,vector<int>(cap+1));
    for(int i = 0 ; i < n; i++)
    {
        cout<<"Enter the value for item "<<i <<": "<<endl;
        cin>>val[i];
        cout<<"Enter the weight for item "<<i <<": "<<endl;
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<cap+1;j++)
            dp[i][j]=-1;
  
                                 
    cout<<"The Maximum value of items is " <<knapsack(n-1,cap,val,wt,dp);
}

