#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

// TC-O(n)    SC-O(n)
string removeDuplicates(string str){
    int n = str.length();
    string ans;

    for(int i=0; i<n; i++){
        if( (ans.length()>0) && (ans[ans.length()-1] == str[i]) )
            ans.pop_back();
        else
            ans.push_back(str[i]);
    }

    return ans;
}

// TC-O(n^2)    SC-O(1)
string removeDuplicates2(string str){
    int n = str.length();
    int i=1;

    while(i<n){
        if(i==0)
            i++;
        else{
            if(str[i]==str[i-1]){
                str.erase(i-1, 2);
                i--;
            }
            else
                i++;
        }
    }

    return str;
}

// TC-O(n^2)    SC-O(1)
string removeOccurrences(string s, string part){
    int pos = s.find(part);
    while(pos!=string::npos){
        s.erase(pos, part.length());
        pos = s.find(part);
    }

    return s;
}

// TC-O(n)    SC-O(1)
bool checkPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j])
            return false;
        else{
            i++;
            j--;
        }
    }

    return true;
}

// TC-O(n)    SC-O(1)
bool validPalindromeII(string s) {
    int n = s.length();
    int i=0;
    int j=n-1;

    while(i<j){
        if(s[i]!=s[j]){
            // palindrome after one removal
            return checkPalindrome(s, i, j-1) || checkPalindrome(s, i+1, j);
        }
        else{
            i++;
            j--;
        }
    }

    // palindrome with no removal
    return true;
}

// TC-O(n)    SC-O(n)
int findMinDifference(vector<string> timePoints) {
    int n = timePoints.size();
    vector<int>minutes;

    // convert time (string) to minutes (int)
    for(int i=0; i<n; i++){
        string curr = timePoints[i];
        int hours = stoi( curr.substr(0,2) );
        int mins = stoi( curr.substr(3,2) );
        int totalMinutes = hours*60 + mins;
        minutes.push_back(totalMinutes);
    }

    sort(minutes.begin(), minutes.end());
    
    int mini = INT_MAX;
    for(int i=0; i<n-1; i++){
        int diff = minutes[i+1] - minutes[i];
        mini = min(mini, diff);
    }

    // for ex - 00:00 and 23:59    
    int lastDiff = minutes[0]+1440 - minutes[n-1];      //1440 mins in 24 hours
    mini = min(mini, lastDiff);

    return mini;
}

// TC-O(n)    SC-O(1)
int expandAround(string s, int i, int j){
    int count = 0;
    int n = s.length();
    while(i>=0 && j<n && s[i]==s[j]){
        count ++;
        i--;
        j++;
    }

    return count;
}

// TC-O(n^2)    SC-O(1)
int countSubstrings(string s){
    int n = s.length();
    int cnt = 0;

    for(int i=0; i<n; i++){
        // odd substrings
        int oddAns = expandAround(s,i,i);
        cnt += oddAns;

        // even substrings
        int evenAns = expandAround(s,i,i+1);
        cnt += evenAns;
    }

    return cnt;
}

int main(){

    /*// Remove All Adjacent Duplicates In String
        string str;
        cin>>str;
        string ans = removeDuplicates(str);
        cout << ans << '\n';

        string ans2 = removeDuplicates2(str);
        cout << ans2 << '\n';
    */

    /*// Remove All Occurrences of a Substring
        string s;
        string part;
        cin>>s>>part;
        string ans = removeOccurrences(s, part);
        cout << ans << '\n';
    */
    
    /*// Valid Palindrome II
        string s;
        cin>>s;
        bool ans = validPalindromeII(s);
        cout << ans << '\n';
    */

    /*// Minimum Time Difference
        int n;
        cin>>n;
        vector<string>timePoints(n);
        for(int i=0; i<n; i++){
            cin>>timePoints[i];
        }
        int ans = findMinDifference(timePoints);
        cout << ans << '\n';
    */

    /*// Palindromic Substrings
        string s;
        cin>>s;
        int ans = countSubstrings(s);
        cout << ans << '\n';
    */

    return 0;
}

/*INPUTS
// Remove All Adjacent Duplicates In String
abbaca

// Remove All Occurrences of a Substring
daabcbaabcbc
abc

// Valid Palindrome II
leverl

// Minimum Time Difference
2
23:59 00:00

// Palindromic Substrings
noon
*/