// https://leetcode.com/problems/isomorphic-strings/

#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s1, string s2) {
    unordered_map<char,char>mapping;            // ch1, ch2
    unordered_map<char,bool>isVisited;            // ch2, bool

    int n = s1.length();

    if(n != s2.length())
        return false;

    for(int i=0; i<n; i++){
        char ch1 = s1[i];
        char ch2 = s2[i];

        if(mapping[ch1]){
            if(mapping[ch1] != ch2)
                return false;
        }
        else{
            if(isVisited[ch2])      // it means ch2 is already been mapped with some character 
                return false;
            else{
                mapping[ch1] = ch2;
                isVisited[ch2] = true;
            }
        }
   
        // this and above code are same
        // if(!mapping[ch1] && !isVisited[ch2]){
        //     mapping[ch1] = ch2;
        //     isVisited[ch2] = true;
        // }
        // else if(mapping[ch1]==ch2 && isVisited[ch2])
        //     continue;
        // else
        //     return false;   
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
// ans should be 0
*/