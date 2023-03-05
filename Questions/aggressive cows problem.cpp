// https://www.geeksforgeeks.org/assign-stalls-to-k-cows-to-maximize-the-minimum-distance-between-them/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC-O(n)    SC-O(1)
bool isPossibleAns(vector<int>arr, int cows, int mini){
    int n = arr.size();
    int curr = 0;
    int count = 1;      // 1st cow will be at index 0

    // // 1st method 
    // int next = 1;
    // while(next<n){
    //     while(next<n && arr[next]-arr[curr] < mini){
    //         next++;
    //     }
    //     if(next<n){
    //         count++;
    //         curr = next;
    //         next++;
    //     }
    //     if(count==cows)
    //         return true;
    // }

    // 2nd method
    for(int i=1; i<n; i++){
        if(arr[i] - arr[curr] >= mini){
            curr = i;
            count++;
        }
        if(count == cows)
            return true;
    }

    return false;
}

// TC-O(nlogn)    SC-O(1)
int aggressiveCows(vector<int>arr, int cows){
    sort(arr.begin(), arr.end());
    int n = arr.size();

    int s = 0;
    int e = arr[n-1] - arr[0];
    int ans = -1;

    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossibleAns(arr, cows, mid)){
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
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int cows;
    cin>>cows;

    int ans = aggressiveCows(arr, cows);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
5
1 2 4 8 9 
3

5
10 1 2 7 5
3
*/