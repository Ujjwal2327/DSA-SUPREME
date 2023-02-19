// https://www.geeksforgeeks.org/divide-two-number-using-binary-search-without-using-any-and-operator/

#include<iostream>
using namespace std;

// TC-O(loga)
// for only +ve numbers
int divideAByB(int a, int b){
    int s = 0;
    int e = a;
    int mid = s + (e-s)/2;
    int ans = 0;

    while(s<=e){
        if(b*mid > a)
            e = mid - 1;
        else{
            ans = mid;      // store in ans
            s = mid + 1;    // search in right for possible bigger ans
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

// TC-O(loga)
// for both +ve and -ve numbers
int divideAByB2(int dividend, int divisor){
    if(divisor == 0)
        return -1;

    int a = abs(dividend);
    int b = abs(divisor);
    int s = 0;
    int e = a;
    int mid = s + (e-s)/2;
    int ans = 0;

    while(s<=e){
        if(b * mid == a){   
            ans = mid;
            break;
        }
        else if(b * mid < a){
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
        mid = s + (e-s)/2;
    }

    if( (divisor>0 && dividend>0) || (divisor<0 && dividend<0) )
        return ans;
    else
        return -ans;
}

int main(){

    int a,b;
    cin>>a>>b;
    int ans = divideAByB(a,b);
    cout<<ans<<'\n';

    int ans2 = divideAByB2(a,b);
    cout<<ans2<<'\n';

    return 0;
}

/*INPUTS
15 3

15 -3
*/