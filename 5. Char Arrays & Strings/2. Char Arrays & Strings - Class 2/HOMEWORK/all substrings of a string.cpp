#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<string> arr){
    int n = arr.size();
    for(int i=0; i<n; i++)
        cout<<arr[i]<<'\n';
    cout<<'\n';
}

vector<string> printSubstrings(string s){
    int n = s.length();
    vector<string>ans;

    for(int i=0; i<n; i++){
        string curr;
        for(int j=i; j<n; j++){
            curr.push_back(s[j]);
            ans.push_back(curr);
        }
    }

    return ans;
}

int main(){

    string s;
    getline(cin, s);

    vector<string> ans = printSubstrings(s);
    printVector(ans);

    return 0;
}

/*INPUTS
abcd
*/