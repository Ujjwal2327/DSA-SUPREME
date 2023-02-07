// set ith bit of a number starting from 0 from right to left

// https://www.geeksforgeeks.org/set-k-th-bit-given-number/

#include<iostream>
using namespace std;

int setIthBit(int n, int i){
    // 1 left shift i times
    int num = 1 << i;
    // do or of given number and num
    int ans = n | num;
    return ans;
}

int main(){

    int n, i;
    cin >> n >> i;
    int ans = setIthBit(n, i);
    cout << ans << '\n';


    return 0;
}