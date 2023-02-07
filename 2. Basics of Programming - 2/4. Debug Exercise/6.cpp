// Convert given Binary number to Decimal.

#include<iostream>
using namespace std;

int binaryToDecimal(int b){
    int ans=0;
    int c=0;
    while(b){
        ans += (b % 10) * (1 << c++);
        b/=10;
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    cout << binaryToDecimal(n) << '\n';

    return 0;
}
