#include<iostream>
#include<vector>
using namespace std;

// TC-O(2^n)    SC-O(n)
void printSubsequences(string s, vector<string>&ans){
    int n = s.length();
    ans.push_back("");

    int start = 1;
    for(int i=0; i<n; i++){
        char ch = s[i];
        for(int j=0; j<start; j++){
            string curr = ans[j];
            curr += ch;
            ans.push_back(curr);
        }
        start = start << 1;
    }
}

void printStringVector(vector<string>arr){
    for(auto i:arr)
        cout << i << ' ';
    cout << '\n';
}

int main(){

    string s = "abc";
    vector<string>ans;
    printSubsequences(s, ans);
    printStringVector(ans);

    return 0;
}