#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC- O(logn)
int firstOccurence(vector<int>arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;   // if not found, return -1

    while(s<=e){
        int element = arr[mid];

        if(target == element){
            ans = mid;      // store in ans
            e = mid - 1;    // check in left
        }
        else if(target < mid)
            e = mid - 1;
        else
            s = mid + 1;
        
        mid = s + (e-s)/2;
    }

    return ans;
}

// TC- O(logn)
int lastOccurence(vector<int>arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        int element = arr[mid];
        if(target == element){
            ans = mid;      // store in ans
            s = mid + 1;    //check in right
        }
        else if(target < element)
            e = mid -1;
        else
            s = mid + 1;
        
        mid = s + (e-s)/2;
    }

    return ans;
}

int main(){

    /*// using binary search
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int target;
        cin>>target;
        int first = firstOccurence(arr, target);
        int last = lastOccurence(arr, target);
        int ans = last - first + 1;
        cout<<ans<<'\n';
    */

    /*// using STL
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int target;
        cin>>target;

        auto lowerBound = lower_bound(arr.begin(), arr.end(), target);
        auto upperBound = upper_bound(arr.begin(), arr.end(), target);
        int ans = upperBound - lowerBound;
        cout << ans << '\n';
    */

    return 0;
}

/*INPUTS
8
1 2 4 4 4 4 4 6
4
*/