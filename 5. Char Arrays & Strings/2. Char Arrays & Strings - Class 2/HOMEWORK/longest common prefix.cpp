// https://leetcode.com/problems/longest-common-prefix/

#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    string ans;

    // store largest string in ans initially
    for(int i=0; i<n; i++){
        if(ans.length() < strs[i].length())
            ans = strs[i];
    }

    for(int i=0; i<n; i++){
        string curr = strs[i];
        int j=0;

        while(j<ans.length() && j<curr.length()){
            if(curr[j] == ans[j])
                j++;
            else
                break;
        }

        // keep only match prefix only in ans
        while(ans.length()>j)
            ans.pop_back();
    }

    return ans;
}

string longestCommonPrefix2(vector<string>& strs) {
    int n = strs.size();
    string ans = strs[0];

    for(int i=0; i<n; i++){
        string curr = strs[i];
        int j=0;

        while(j<ans.length() && j<curr.length()){
            if(curr[j] == ans[j])
                j++;
            else
                break;
        }

        // keep only match prefix only in ans
        while(ans.length()>j)
            ans.pop_back();
    }

    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    string ans = longestCommonPrefix(arr);
    cout<<ans<<'\n';
    
    string ans2 = longestCommonPrefix2(arr);
    cout<<ans2<<'\n';

    return 0;
}

/*INPUTS
3
flower flow flight
*/