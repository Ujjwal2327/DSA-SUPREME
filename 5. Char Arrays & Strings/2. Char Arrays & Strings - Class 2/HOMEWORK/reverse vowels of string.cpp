// https://leetcode.com/problems/longest-common-prefix/

#include<iostream>
#include<vector>
using namespace std;

bool isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        return true;
    else
        return false;
}

string reverseVowels(string s) {
    int n = s.length();
    int st = 0;
    int e = n - 1;

    while(st<e){
        if(!isVowel(s[st]))
            st++;
        else if(!isVowel(s[e]))
            e--;
        else
            swap(s[st++], s[e--]);
    }

    return s;
}

int main(){

    string s;
    cin>>s;

    string ans = reverseVowels(s);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
LEEtcode
*/