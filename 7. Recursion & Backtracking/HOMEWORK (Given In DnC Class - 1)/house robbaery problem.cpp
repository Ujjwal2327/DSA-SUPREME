// https://leetcode.com/problems/house-robber/

#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums, int i){
    if(i>=nums.size())
        return 0;
    
    int ans1 = rob(nums, i+1);
    int ans2 = nums[i] + rob(nums, i+2);

    return max(ans1, ans2);
}

int main(){

    vector<int>arr{1,2,3,1};
    int i=0;
    int ans = rob(arr, i);

    return 0;
}
