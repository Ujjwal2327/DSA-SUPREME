#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// best
void coinChange(vector<int>&arr, int &ans, int currAns, int &target, int remainValue){
    if(remainValue==0){
        ans = min(ans, currAns);
        return;
    }

    if(remainValue<0)
        return;

    for(int i=0; i<arr.size(); i++)
        coinChange(arr, ans, currAns+1, target, remainValue-arr[i]);

}

int coinChange2(vector<int>&arr, int remainValue){
    if(remainValue==0)
        return 0;

    if(remainValue<0)
        return INT_MAX;

    // find minimum ans from whole array
    int minAns = INT_MAX;

    for(int i=0; i<arr.size(); i++)
        minAns = min(minAns, coinChange2(arr, remainValue-arr[i]));

    if(minAns==INT_MAX)         // ans cannot be found in the whole array
        return minAns;
    else                        // ans found, so increase count with 1
        return minAns+1;
}

int cutIntoSegments(int target, int x, int y, int z){
    if(target==0)
        return 0;
    
    int ans = -1;      // start from invalid, so it can result -1 if all are invalid

    if(target-x>=0)
        ans = max(ans, cutIntoSegments(target-x, x, y, z));
    if(target-y>=0)
        ans = max(ans, cutIntoSegments(target-y, x, y, z));
    if(target-z>=0)
        ans = max(ans, cutIntoSegments(target-z, x, y, z));

    if(ans==-1)
        return -1;      // if it is not possible to cut into segments in any length from x, y, z
    else
        return ans+1;
}

// best
int cutIntoSegments2(int target, int x, int y, int z){
    if(target==0)
        return 0;

    if(target<0)
        return INT_MIN;      // return INT_MIN for invalid segment

    int ans1 = cutIntoSegments2(target-x, x, y, z);
    int ans2 = cutIntoSegments2(target-y, x, y, z);
    int ans3 = cutIntoSegments2(target-z, x, y, z);

    int ans = max(ans1, max(ans2, ans3));

    return ans+1;
}

void maxNonAdjSum(vector<int>&arr, int i, int &ans, int currAns){
    int n = arr.size();

    if(i>=n){
        ans = max(ans, currAns);
        return;
    }

    maxNonAdjSum(arr, i+1, ans, currAns);               // not including ith element
    maxNonAdjSum(arr, i+2, ans, currAns+arr[i]);        // including ith element, so cant include (i+1)th element

}

int maxNonAdjSum2(vector<int>arr){
    int n = arr.size();

    if(n==1)
        return arr[0];
    
    arr[n-2] = max(arr[n-2], arr[n-1]);

    for(int i=n-3; i>=0; i--)
        arr[i] = max(arr[i+1], arr[i]+arr[i+2]);    // after this, arr[i] stores the max alternate sum from ith to last index

    return arr[0];
}

int main(){

    /*// coin change problem
        vector<int>arr{2,1,3};
        int ans = INT_MAX;
        int target = 10;
        int currAns = 0;
        int remainValue = target;
        coinChange(arr, ans, currAns, target, remainValue);
        cout << ans << '\n';

        int ans2 = coinChange2(arr, remainValue);
        cout << ans2 << '\n';
    */

    /*// cut into segments
        int x = 5;
        int y = 3;
        int z = 2;
        int target = 7;
        int ans = cutIntoSegments(target, x, y, z);
        if(ans==-1)
            cout << 0 << '\n';
        else
        cout << ans << '\n';

        int ans2 = cutIntoSegments2(target, x, y, z);
        if(ans2<0)
            cout << 0 << '\n';
        else
            cout << ans2 << '\n';
    */

    /*// maximum sum of nonadjacent elements in an array
        vector<int>arr{2,1,4,9,5,6};
        int ans = INT_MIN;
        maxNonAdjSum(arr, 0, ans, 0);
        cout << ans << '\n';

        int ans2 = maxNonAdjSum2(arr);
        cout << ans << '\n';
    */

    return 0;
}

/*INPURS
8
3 3 3
*/