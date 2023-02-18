#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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

    // using binary search
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int ans = lastOccurence(arr, target);
    cout << ans << '\n';

    // using STL
    auto upperBound = upper_bound(arr.begin(), arr.end(), target);
    bool binarySearch = binary_search(arr.begin(), arr.end(), target);
    int ans2 = upperBound - arr.begin() -1;
    if(binarySearch)
        cout << ans2 << '\n';
    else
        cout << -1 << '\n';

    return 0;
}

/*INPUTS
8
1 2 4 4 4 4 4 6
4
*/