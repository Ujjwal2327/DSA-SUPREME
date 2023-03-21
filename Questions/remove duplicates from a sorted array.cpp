// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int j=0;
    for(int i=1; i<n; i++){
        if(nums[i]!=nums[j]){
            j++;
            nums[j] = nums[i];
        }
    }
    return j+1;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = removeDuplicates(arr);
    cout << ans << '\n';
    printVector(arr, ans);

    return 0;
}

/*INPUTS
11
3 4 15 15 15 20 20 30 70 80 120
*/