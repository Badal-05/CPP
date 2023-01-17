#include<iostream>
#include<string>
#include<math.h>

using namespace std;

double Karatsuba(int a, int b)
{
    if(a < 10 || b < 10)
    {
        return (a*b);
    }
    else{
        int digits = max(to_string(a).length(),to_string(b).length());
        int half = digits/2;
        

        int aL = a / ((int)pow(10,half));
        int aR = a % ((int)pow(10,(half)));
        int bL = b / ((int)pow(10,half));
        int bR = b % ((int)pow(10,(half)));

        double x1 = Karatsuba(aL,bL);
        double x2 = Karatsuba(aR,bR);
        double x3 = Karatsuba((aL+aR),(bL+bR))-x1-x2;

        return(x1*((double)pow(10,half*2)) + x3*((double)pow(10,half)) + x2);

    }
}
int main(){
    int a = 104;
    int b = 204;
    cout<<Karatsuba(a,b);

}