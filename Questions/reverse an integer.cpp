// find the reverse of an integer

// https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/
// https://leetcode.com/problems/reverse-integer/

#include<bits/stdc++.h>
using namespace std;

int getReverse(int n){
    int ans = 0;
    while(n){
        if(ans>INT_MAX/10 || ans<=INT_MIN/10)
            return 0;
        int digit = n % 10;
        ans = ans*10 + digit;
        n = n / 10;
    }
    return ans;
}

int getReverse2(int n){
    bool flag = false;
    if(n<0)
        flag = true;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    int ans = stoi(s);
    return flag ? -ans : ans;
}

int main(){

    int n;
    cin>>n;
    int ans = getReverse(n);
    cout << ans <<'\n';

    int ans2 = getReverse2(n);
    cout << ans2 <<'\n';

    return 0;
}

/*INPUTS
1234567
*/