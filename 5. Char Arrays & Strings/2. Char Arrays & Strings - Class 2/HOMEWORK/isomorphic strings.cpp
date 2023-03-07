// https://leetcode.com/problems/isomorphic-strings/

#include<iostream>
#include<string.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    int n = s.length();
    int m = t.length();
    char ch[256];
    char flag[256] = {0};
    memset(ch, -1, 256);

    if(m!=n)
        return false;
    
    for(int i=0; i<n; i++){
        if(ch[s[i]]==-1){
            if( flag[t[i]] )
                return false;
            else{
                flag[t[i]] = true;
                ch[s[i]] = t[i];
            }
        }
        else{
            if(ch[s[i]] != t[i])
                return false;
        }
    }

    return true;
}

int main(){

    string s;
    cin>>s;
    string t;
    cin>>t;
    bool ans = isIsomorphic(s,t);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
badc
baba
*/