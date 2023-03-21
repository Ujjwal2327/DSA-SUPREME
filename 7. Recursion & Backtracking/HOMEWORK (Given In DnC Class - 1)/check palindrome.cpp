#include<iostream>
using namespace std;

bool checkPalindrome(string &s, int i){
    if(i>=s.length()/2)
        return true;
    
    if(s[i] == s[s.length()-1-i])
        return checkPalindrome(s, i+1);
    else
        return false;
}

int main(){

    string s = "racecar";
    int i=0;
    bool ans = checkPalindrome(s, i);
    cout << ans << '\n';

    return 0;
}