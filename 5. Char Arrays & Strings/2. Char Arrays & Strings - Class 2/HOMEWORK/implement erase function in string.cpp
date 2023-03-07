#include<iostream>
using namespace std;

string erase(string s, int startIndex, int numOfChars){
    int n = s.length();
    string ans;

    if(startIndex>=n)
        return s;
    
    for(int i=0; i<n; i++){
        if(i>=startIndex && i<startIndex+numOfChars)
            continue;
        else
            ans.push_back(s[i]);
    }

    return ans;
}

int main(){

    string s;
    getline(cin, s);

    int startIndex;
    cin>>startIndex;
    int numOfChars;
    cin>>numOfChars;

    string ans = erase(s, startIndex, numOfChars);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
This is my first para
11 5

This is my first para
second
*/