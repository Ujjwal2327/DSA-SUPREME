// count number of setbits in a number

// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

#include<iostream>
using namespace std;

// for +ve numbers
int countSetBitInPositiveNum(int n){
    int ans = 0;
    while(n){
        if(n&1){
            ans++;
        }
        n = n>>1;
    }
    return ans;
}

// for -ve numbers
int countSetBitInNegativeNum(int n){
    int cnt0 = 0;    // cnt0 refers to numbers of zeroes
    while(n!=-1){
        if((n&1)==0){     // count number of 0s
            cnt0++;
        }
        n = n>>1;
    }
    return (32-cnt0);     // as total bits are 32 and total 0 bits are cnt0
}

// works fine in both +ve and -ve
int countSetBit(int n){
    int ans = 0;
    for(int i=0; i<32; i++){
        int placeValue = 1<<i;
        if(n & placeValue){
            ans++;
        }
    }
    return ans;
}

int main(){

    // For signed numbers, the sign bit is used to fill the vacated bit positions. In other words, if the number is positive, 0 is used, and if the number is negative, 1 is used.
    // for +ve number
    int n;
    cin>>n;
    int ans = countSetBitInPositiveNum(n);
    cout << ans << '\n';
    
    // for -ve number
    cin>>n;
    ans = countSetBitInNegativeNum(n);
    cout << ans << '\n';

    // for both +ve and -ve number
    cin>>n;
    ans = countSetBit(n);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
5
-5
-5
*/