// count setbits in a number

// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

#include<iostream>
using namespace std;

int countSetBit(int n){
    int ans = 0;
    while(n){
        if(n&1){
            ans++;
            cout<<ans<<' ';
        }
        n = n>>1;
    }
    cout<<'\n';
    return ans;
}

int main(){

    // For signed numbers, the sign bit is used to fill the vacated bit positions. In other words, if the number is positive, 0 is used, and if the number is negative, 1 is used.
    int n;
    cin>>n;
    int ans = countSetBit(n);
    cout << ans << '\n';

    return 0;
}