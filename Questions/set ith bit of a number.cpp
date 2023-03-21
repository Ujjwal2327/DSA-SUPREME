// set ith bit of a number starting from 0 from right to left

// https://www.geeksforgeeks.org/set-k-th-bit-given-number/

#include<iostream>
using namespace std;

int setIthBit(int n, int i){
    // 1 left shift i times
    int mask = (1 << i);
    // do OR of given number and val
    int ans = n | mask;
    return ans;
}

int main(){

    int n, i;
    cin >> n >> i;
    int ans = setIthBit(n, i);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
5
3
*/