// https://leetcode.com/problems/missing-number/description/

// https://www.geeksforgeeks.org/find-the-missing-number/

#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ nums[i];
    }
    for(int i=0; i<=n; i++){
        ans = ans ^ i;
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = missingNumber(arr);
    cout << ans << '\n';

    return 0;
}