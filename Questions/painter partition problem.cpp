// https://www.geeksforgeeks.org/painters-partition-problem/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// TC-O(n)    SC-O(1)
bool possibleAns(vector<int>arr, int num, int maxi){
    int n = arr.size();
    int i=0;
    while(i<n && num--){
        int curr = 0;
        while(i<n && curr+arr[i] <= maxi){
            curr +=arr[i];
            i++;
        }
    }

    if(i==n)    // all boards are being painted, doesn't matter all painters are worked or not
        return true;
    else
        return false;
}

// TC-O(nlogn)    SC-O(1)
int painterPartition(vector<int>arr, int num){
    int n = arr.size();

    int s = 0;
    int e = 0;
    e = accumulate(arr.begin(), arr.end(), e);
    int ans = -1;
    
    while(s<=e){
        int mid = s + (e-s)/2;

        if(possibleAns(arr, num, mid)){
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return ans;
}

// TC-O(nlogn)    SC-O(1)
int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int painters;
    cin>>painters;

    int ans = painterPartition(arr, painters);
    cout << ans <<'\n';

    return 0;
}

/*
4
10 20 30 40
2

11
21 17 3 12 21 8 11 4 8 22 24
6
*/