// https://leetcode.com/problems/majority-element/

// https://www.geeksforgeeks.org/majority-element/

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int ans = nums[0];
    int cnt=1;
    for(int i=1; i<nums.size(); i++){
        if(cnt>0){
            if(nums[i]==ans)
                cnt++;
            else
                cnt--;
        }
        else{
            ans = nums[i];
            cnt = 1;
        }
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = majorityElement(arr);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
7
2 2 9 3 3 2 2
*/