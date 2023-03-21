// https://leetcode.com/problems/number-of-digit-one/

#include<iostream>
using namespace std;

int solve(int n){
    if(n==0)
        return 0;
    
    if(n%10==1){
        return 1 + solve(n/10);
    }
    else
        return solve(n/10);
}

int countDigitOne(int n) {
    if(n==0)
        return 0;
    
    return solve(n) + countDigitOne(n-1);
}

int main(){

    int n = 13;
    int ans = countDigitOne(n);
    cout << ans << '\n';

    return 0;
}