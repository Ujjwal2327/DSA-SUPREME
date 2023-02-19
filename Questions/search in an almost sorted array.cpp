// https://www.geeksforgeeks.org/search-almost-sorted-array/

// every element in ith position in sorted array will found in i, i+1 or i-1 position in nearly sorted array

#include<iostream>
#include<vector>
using namespace std;

// TC-O(logn)
int searchInNearlySortedArray(vector<int>arr, int target){
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

// TC-O(logn)
int searchInNearlySortedArray2(vector<int>arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(target == arr[mid])
            return mid;
        else if(mid+1<n && target == arr[mid+1])
            return mid+1;
        // else if(mid-1>s && target == arr[mid-1])     // this will also work
        else if(mid-1>=0 && target == arr[mid-1])
            return mid-1;
        
        if(target < arr[mid])
            e = mid - 2;
            // e = mid - 1;     // this will also work
        else
            s = mid + 2;
            // s = mid + 1;     // this will also work
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
    
    int ans = searchInNearlySortedArray(arr, target);
    cout<<ans<<'\n';

    int ans2 = searchInNearlySortedArray2(arr, target);
    cout<<ans2<<'\n';

    return 0;
}

/*INPUTS
7
10 3 40 20 50 80 40
40
*/