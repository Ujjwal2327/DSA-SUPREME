// https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// TC-O(nlogn)
// binary search
int findPairs(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector< pair<int,int> >ans;

    for(int i=0; i<n; i++){
        int first = nums[i];
        int second = nums[i] + k;

        int size = ans.size();
        if( (size==0) || (ans[size-1].first != first)){
            if( binary_search(nums.begin()+i+1, nums.end(), second) )
                ans.push_back( {first,second} );
        }
    }

    return ans.size();
}

// TC-O(nlogn)
// 2 pointer approach and using vector of pairs
int findPairs2(vector<int>& nums, int k){
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int i=0;
    int j=1;
    vector<pair<int,int>>ans;

    while(j<n && i<n){

        if(i==j){
            j++;
            continue;
        }

        int diff = nums[j]-nums[i];

        if(diff == k){
            if(ans.size()==0)
                ans.push_back({nums[i], nums[j]});
            else if(ans.size()-1>=0 && ans[ans.size()-1].first!=nums[i])
                ans.push_back({nums[i], nums[j]});
            i++;
            j++;
        }
        else if(diff > k)
            i++;
        else
            j++;
    }

    return ans.size();
}

// TC-O(nlogn)
// 2 pointer approach and using set
int findPairs3(vector<int>& nums, int k){
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int i=0;
    int j=1;
    set<pair<int,int>>ans;

    while(j<n && i<n){

        if(i==j){
            j++;
            continue;
        }

        int diff = nums[j]-nums[i];

        if(diff == k){
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if(diff > k)
            i++;
        else
            j++;
    }

    return ans.size();
}

int main(){

    int n;
    cin>>n; 
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    int ans = findPairs(arr, k);
    cout << ans << '\n';

    int ans2 = findPairs2(arr, k);
    cout << ans2 << '\n';

    int ans3 = findPairs3(arr, k);
    cout << ans2 << '\n';

    return 0;
}

/*
5
3 1 4 1 5
2

5
1 1 3 5 4
0
*/