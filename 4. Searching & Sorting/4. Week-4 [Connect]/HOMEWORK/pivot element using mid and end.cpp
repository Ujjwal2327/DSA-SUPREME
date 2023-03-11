// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

int pivot(vector<int>arr){
    int n = arr.size();

    int s = 0;
    int e = n-1;
    int ans = e;

    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] > arr[n-1]){
        // if(arr[mid] > arr[e]){       // not work for array {5,1,3}
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }

    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = pivot(arr);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
3
5 1 3

4
1 3 5 7

6
3 5 7 8 1 2
*/