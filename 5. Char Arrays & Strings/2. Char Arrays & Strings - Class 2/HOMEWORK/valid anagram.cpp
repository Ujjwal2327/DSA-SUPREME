// https://leetcode.com/problems/valid-anagram/

#include<iostream>
#include<algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    int n = s.length();
    int m = t.length();

    if(n!=m)
        return false;
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s==t;
}

bool isAnagram2(string s, string t) {
    int n = s.length();
    int m = t.length();

    if(n!=m)
        return false;
    
    int sCnt[256] = {0};
    int tCnt[256] = {0};

    for(int i=0; i<n; i++){
        sCnt[s[i]]++;
        tCnt[t[i]]++;
    }

    for(int i=0; i<256; i++){
        if(sCnt[i]!=tCnt[i])
            return false;
    }

    return true;
}

bool isAnagram3(string s, string t) {
    int n = s.length();
    int m = t.length();

    if(n!=m)
        return false;
    
    int sCnt[256] = {0};

    for(int i=0; i<n; i++){
        sCnt[s[i]]++;
    }

    for(int i=0; i<n; i++){
        sCnt[t[i]]--;
    }

    for(int i=0; i<256; i++){
        if(sCnt[i])
            return false;
    }

    return true;
}

int main(){

    string s;
    getline(cin, s);
    string t;
    getline(cin, t);

    bool ans = isAnagram(s,t);
    cout<<ans<<'\n';

    bool ans2 = isAnagram2(s,t);
    cout<<ans2<<'\n';

    bool ans3 = isAnagram3(s,t);
    cout<<ans3<<'\n';

    return 0;
}

/*INPUTS
anagram
nagaram
*/