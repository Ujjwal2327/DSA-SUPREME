// https://www.spoj.com/problems/EKO/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC-O(n)    SC-O(1)
int isPossibleAns(vector<int>arr, int req, int curr){
    int n = arr.size();
    long long ans = 0;

    for(int i=0; i<n; i++){
        if(arr[i]>curr)
            ans += arr[i] - curr;
    }

    if(ans>=req)
        return true;
    else
        return false;
}

// TC-O(nlogn)    SC-O(1)
int eko(vector<int>arr, int req){
    int s = 0;
    int e = *max_element(arr.begin(), arr.end());
    int ans = 0;

    while(s<=e){
        int mid = s + (e-s)/2;

        if(isPossibleAns(arr, req, mid)){
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }

    return ans;
}

// TC-O(nlogn)    SC-O(1)
int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int req;
    cin>>req;
    
    int ans = eko(arr, req);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
4
20 15 10 17
7

5
4 42 40 26 46
20
*/