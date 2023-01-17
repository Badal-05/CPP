#include<iostream>

using namespace std;


typedef struct node
{
    int weight;
    float val,ratio;
    
} Item;

void init(Item a[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        a[i].ratio = a[i].val / a[i].weight;
    }

    for(int i = 0; i<n ; i++){
        int max = i;
        for(int j = i+1 ; j<n ; j++)
        {
            if(a[j].ratio > a[max].ratio){
                max = j;
            }
        }

        Item temp;
        temp = a[max];
        a[max]=a[i];
        a[i] = temp;
    }
}

void change(Item a[], int n , int cap){
    float amt = 0;
    for(int i = 0 ; i<n ;i++){
        if(a[i].weight <= cap)
        {
            amt+=a[i].val;
            cap-=a[i].weight;
        }
        else{
            amt+=((float)cap/(float)a[i].weight)*a[i].val;
            break;
        }

    }
    cout<<"The final amount using Greedy Method is: "<<amt<<endl;
}

int main(){

    int n,cap;
    cout<<"Enter the number of objects"<<endl; 
    cin>>n;
    Item a[n];
    for(int i = 0; i<3;i++)
    {
        cout<<"Enter the value of weight for"<<" object "<<i+1<<endl;
        
        cin>>a[i].weight;
        cout<<"Enter the value of value for"<<" object "<<i+1<<endl;
        cin>>a[i].val;
    }
    cout<<"Enter the capacity of the knapsack"<<endl;
    cin>>cap;
    init(a,n);
    change(a,n,cap);
}