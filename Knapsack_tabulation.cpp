#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Getting the inputs
    int n,cap;
    cout<<"Enter the number of items:"<<endl;
    cin>>n;
    cout<<"Enter the capacity:"<<endl;
    cin>>cap;
    int wt[n+1],val[n+1],dp[n+1][cap+1];
    cout<<"Enter for val array \n";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>val[i];
    }
    cout<<"Enter for weight array \n";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>wt[i];
    }
    
    // main logic
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < cap + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < cap + 1; j++)
        {
            int arr_index = i - 1; 
            int notinclude = 0 + dp[i - 1][j];
            int include = INT_MIN;
            if (wt[arr_index] <= j)
                include = val[arr_index] + dp[i - 1][cap - wt[arr_index]];
            dp[i][j] = include > notinclude ? include : notinclude;
        }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
            cout << dp[i][j] << "  ";
        cout << "\n";
    }

    cout << "The Maximum value of items is " << dp[n][cap] << "\n";
    cout << "included items are \n";
    int row = n, col = cap;
    while (row > 0 || col > 0)
    {
        if (dp[row][col] != dp[row - 1][col]) 
        {
            int arr_index = row - 1;
            cout << "item " << row << " with weight " << wt[arr_index] << "\n";
            col -= wt[arr_index];
        }
        row--; 
    }
}