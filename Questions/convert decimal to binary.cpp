// convert decimal number to binary

#include<bits/stdc++.h>
using namespace std;

int decimalToBinary(int n){
    int ans = 0;
    int i=1;
    while(n){
        int bit = n%2;
        n = n/2;
        ans = bit*i + ans;
        i*=10;
    }
    return ans;
}

// bitwise operator
int decimalToBinary2(int n){
    int ans = 0;
    int i=0;
    while(n){
        // n&1 gives 1st / rightmost bit
        int bit = n&1;
        ans = bit*pow(10,i++) + ans;
        // right shift as we have used right most bit
        n = n>>1;
    }
    return ans;
}

int decimalToBinary3(int n){
    int ans = 0;
    int i=1;
    while(n){
        // if right most bit is 1
        if(n&1)
            ans = i + ans;
        // right shift as we have used right most bit
        n = n>>1;
        i*=10;
    }
    return ans;
}

int main(){

    int n;
    cin>>n; 
    int ans = decimalToBinary(n);
    cout << ans << '\n';
    int ans2 = decimalToBinary2(n);
    cout << ans2 << '\n';
    int ans3 = decimalToBinary3(n);
    cout << ans3 << '\n';

    return 0;
}

/*INPUTS
12
*/