// find the reverse of an integer

// https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/

#include<bits/stdc++.h>
using namespace std;

int getReverse(int n){
    int ans = 0;
    while(n){
        int digit = n % 10;
        n = n / 10;
        ans = ans*10 + digit;
    }
    return ans;
}

int getReverse2(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    int ans = stoi(s);
    return ans;
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