// https://leetcode.com/problems/longest-palindromic-substring/

#include<iostream>
using namespace std;

string expand(string s, int i, int j){
    int n = s.length();
    if(i<0 || j>=n)
        return "";
        
    while(i>=0 && j<n){
        if(s[i]==s[j]){
            i--;
            j++;
        }
        else
            break;
    }

    string ans;
    for(int k=i+1; k<j; k++)
        ans.push_back(s[k]);
    
    return ans;
}

string longestPalindrome(string s) {
    int n = s.length();
    string ans;

    for(int i=0; i<n; i++){
        string temp1 = expand(s,i,i);
        string temp2 = expand(s,i,i+1);
        if(temp1.length() > ans.length())
            ans = temp1;
        if(temp2.length() > ans.length())
            ans = temp2;
    }

    return ans;
}

int main(){

    string s;
    cin>>s;

    string ans = longestPalindrome(s);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
babad
*/