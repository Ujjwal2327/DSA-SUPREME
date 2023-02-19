// https://www.geeksforgeeks.org/search-almost-sorted-array/

// every element in ith position in sorted array will found in i, i+1 or i-1 position in nearly sorted array

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(target == arr[mid])
            return mid;
        else if(target < arr[mid]){
            if(target == arr[mid+1])    // in case of order swap in that index and target is there
                return mid + 1;
            else        // search in left
                e = mid - 1;
        }
        else{
            if(target == arr[mid-1])    // in case of order swap in that index and target is there
                return mid - 1;
            else        // search in right
                s = mid + 1;
        }

        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    
    int ans = binarySearch(arr, target);
    if(ans!=-1)
        cout << "target found at index " << ans << '\n';
    else
        cout << "target not found\n";

    return 0;
}

/*INPUTS
7
10 3 40 20 50 80 40
40
*/