// Convert given Binary number to Decimal.

// https://www.geeksforgeeks.org/program-binary-decimal-conversion/

#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int b){
    int ans=0;
    int i=0;
    while(b){
        // rightmost bit
        int bit = b%10;
        ans += bit * pow(2,i++);        // pow(2,i++) is placeValue
        b/=10;
    }
    return ans;
}

int binaryToDecimal2(int b){
    int ans=0;
    int i=0;
    while(b){
        int placeValue = 1 << (i++);
        // if rightmost bit is 1
        if(b%10)
            ans += placeValue;
        b/=10;
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    cout << binaryToDecimal(n) << '\n';
    cout << binaryToDecimal2(n) << '\n';

    return 0;
}

/*INPUTS
101101
*/