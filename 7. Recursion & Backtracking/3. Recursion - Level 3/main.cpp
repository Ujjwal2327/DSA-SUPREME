#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>&arr, int i){
    if(i==arr.size()-1)
        return true;
    
    if(arr[i] > arr[i+1])
        return false;
    else
        return isSorted(arr, i+1);
}

int binarySearch(vector<int>&arr, int s, int e, int &target){
    if(s>e)
        return -1;
    
    int mid = s + (e-s)/2;
    if(arr[mid]==target)
        return mid;

    if(target > arr[mid])
        return binarySearch(arr, mid+1, e, target);
    else
        return binarySearch(arr, s, mid-1, target);

    // this will also work      ternary operator
    // return (target > arr[mid]) ? binarySearch(arr, mid+1, e, target) : binarySearch(arr, s, mid-1, target);
}

void ptrintSubSequence(string &s, int i, string output, vector<string>&ans){        // output cannot be pass by reference
    if(i == s.length()){
        cout << output << ' ';
        ans.push_back(output);
        return;
    }

    ptrintSubSequence(s, i+1, output, ans);     // not picking up the current element

    output.push_back(s[i]);     // picking up the current element
    // output += s[i];          // this will also work
    ptrintSubSequence(s, i+1, output, ans);
}

void printStringVector(vector<string>arr){
    for(auto i:arr)
        cout << i << ' ';
    cout << '\n';
}

int main(){

    /*// array is sort or not
        vector<int>arr{1,3,3,5,7,8};
        int i = 0;
        bool ans = isSorted(arr,i);
        cout << ans << '\n';
    */

    /*// binary search in an array
        vector<int>arr{1,3,4,5,7,8};
        int target = 5;
        int ans = binarySearch(arr, 0, arr.size()-1, target);
        cout << ans << '\n';
    */

    /*// subsequences of a string
        string s = "abc";
        vector<string>ans;
        string output;          // empty string
        ptrintSubSequence(s, 0, output, ans); 
        cout << '\n';
        printStringVector(ans);
    */

    /*// arithmatic operations on strings
        // cout << "Ujjwal" + "2327" << '\n';       .. will give error
        string s1 = "Ujjwal";
        string s2 = "2327";
        cout << s1 + s2 << '\n';
        s1 = s1 + s2;
        cout << s1 << '\n';
    */

    return 0;
}