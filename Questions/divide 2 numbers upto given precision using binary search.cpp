#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

// TC-O(logn)
double doubleAbs(double n){
    if(n>=0)
        return n;
    else
        return -n;
}

// TC-O(logn)
int divide(double dividend, double divisor){
    // built-in abs function only works on integer, not on float or double
    double a =  doubleAbs(dividend);
    double b =  doubleAbs(divisor);

    int s = 0;
    int e = a;
    int mid = s + (e-s)/2;
    int ans = 0;

    while(s<=e){
        if(mid*b == a){
            ans = mid;
            break;
        }
        else if(mid*b < a){
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid -1;
        
        mid = s + (e-s)/2;
    }

    return ans;
}

// TC-O(precision*logn)
double divideWithPrecision(double dividend, double divisor, int precision){
    if(divisor == 0)
        return INT_MIN;
    
    double a =  doubleAbs(dividend);
    double b =  doubleAbs(divisor);
    double ans = divide(dividend, divisor);

    for(int i=0; i<precision; i++){
        double remain = a - b*ans;
        remain = remain * pow(10, i+1);
        double remainAns = divide(remain, b) / pow(10, i+1);
        ans += remainAns;
    }

    if( (dividend>=0 && divisor>0) || (dividend<=0 && divisor<0) )
        return ans;
    else
        return -ans;
}

int main(){

    double dividend;
    double divisor;
    cin>>dividend;
    cin>>divisor;

    int precision;
    cin>>precision;

    double ans = divideWithPrecision(dividend, divisor, precision);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
20 7 6
*/