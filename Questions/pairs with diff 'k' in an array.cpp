// https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC-O(n)
void printVector(vector< pair<int, int> >arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout << arr[i].first << ' ' << arr[i].second << "   ";
    }
    cout<<'\n';
}

// TC-O(nlogn)
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

    printVector(ans);

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
    cout << "number of pairs-> " << ans << '\n';

    return 0;
}

/*
5
3 1 4 1 5
2
*/