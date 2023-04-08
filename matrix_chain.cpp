#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of matrices:"<<endl;
    cin>>n;
    int r[n+1]; int dp[n][n]; int b[n][n];
    cout<<"Enter the array of order of matrices \n";
    for(int i=0;i<=n;i++)
    {
        cin>>r[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;
        }
    }

    for(int diff=2;diff<=n;diff++) //iterates over the possible chain lengths, starting with chains of length 2 and ending with chains of length 'n'
    {
        for(int i=0;i<=n-diff;i++) // The inner loop iterates over all possible starting indices i for a chain of length diff, and computes the optimal way to split the chain into two subchains of length k-i+1 and j-k, respectively.
        {
            int j=i+diff-1; int min=INT_MAX;
            for(int k=i;k<=j-1;k++) //iterates over all possible split points k between i and j-1
            {
                int cost=dp[i][k]+dp[k+1][j]+r[i]*r[k+1]*r[j+1];
                if(cost<min)
                {
                    min=cost;
                    b[i][j] = k;
                }
            }
            dp[i][j]=min;
        }
    }
    cout<<"The minimum number of multiplications possible are "<<dp[0][n-1];
   }