#include<iostream>

using namespace std;

int Knapsack(int w[],float v[],int index,int cap){
    if(index==0){
        if(w[index]<=cap){
            return v[index];
        }
        else
            return 0;
    }
    int notinc = Knapsack(w,v,index-1,cap);
    int inc = INT16_MIN;
    if(w[index]<=cap){
        inc = Knapsack(w,v,index-1,cap-w[index]) + v[index];
    }
    return inc>notinc?inc:notinc;
}

int main(){
    int wt[] = {3,2,2};
    float v[]= {1.8,1,1};
    int n = 3;
    int cap = 4;
    cout<<Knapsack(wt,v,n,cap);
}