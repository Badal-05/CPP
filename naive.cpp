#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,p;
    cout<<"Enter the string :";
    cin>>s;
    cout<<"Enter the pattern: ";
    cin>>p;
    // string s = "abaabaabbab";
    // string p = "aab";
    int slen = s.length();
    int plen = p.length();
    int flag = 0;

    for(int i = 0; i <= slen-plen; i++)
    {
        int j = 0; 
        while(j < plen && p.at(j) == s.at(i+j))
        {
            j++;
        }
        if(j == plen)
        {
            cout <<"String found at index: "<< i <<endl;
            flag = 1;
        }
    }

    if(flag == 0)
    {
        cout << "Pattern doesn't exist";
    }
    
    return 0;
}