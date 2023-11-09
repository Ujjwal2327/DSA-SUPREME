// https://leetcode.com/problems/reverse-only-letters/

#include<iostream>
using namespace std;

bool isAlphabet(char ch){
    if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
        return true;
    else
        return false;
}

string reverseOnlyLetters(string s) {
    int n = s.length();
    int st = 0;
    int e = n - 1;

    while(st<e){
        if( !isAlphabet(s[st]) )
            st++;
        else if( !isAlphabet(s[e]) )
            e--;
        else
            swap(s[st++], s[e--]);
    }

    return s;
}
string reverseOnlyLetters2(string s) {
    int n = s.length();
    int st = 0;
    int e = n - 1;

    while(st<e){
        if( !isalpha(s[st]) )
            st++;
        else if( !isalpha(s[e]) )
            e--;
        else
            swap(s[st++], s[e--]);
    }

    return s;
}

int main(){

    string s;
    getline(cin, s);
    string ans = reverseOnlyLetters(s);
    cout<<ans<<'\n';

    string ans2 = reverseOnlyLetters2(s);
    cout<<ans2<<'\n';

    return 0;
}

/*INPUTS
a-bC-dEf-ghIj
*/