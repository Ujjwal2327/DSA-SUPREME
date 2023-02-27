// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr, int target, int s, int e){
    int mid = s + (e-s)/2;

    while(s<=e){
        if(target == arr[mid])
            return mid;
        else if(target < arr[mid])
            e = mid -1;
        else
            s = mid + 1;

        mid = s + (e-s)/2;
    }
    return -1;
}

int pivot(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    if(arr[n-1]>=arr[0])     // array having no rotation    = for single element in an array
        return n-1;

    // s always lies in left subarray
    // e always lies in right subarray

    while(s<e){
        // handle middle 2 cases independently where sorted order breaks
        if(mid+1<n && arr[mid]>arr[mid+1])
            return mid;
        if(mid-1>=0 && arr[mid-1]>arr[mid])
            return mid-1;
        

        if(arr[s]>arr[mid])         // mid present in right subarray and rotation present in left of mid
            e = mid - 1;
        else if(arr[s]<arr[mid])    // mid present in left subarray and rotation present in right of mid
            s = mid + 1;

        mid = s + (e-s)/2;
    }

    return -1;
}

int searchInRotatedSortedArray(vector<int>arr, int target){
    int n = arr.size();
    int pivotIndex = pivot(arr);
    if(target>=arr[0] && target<=arr[pivotIndex]){
        return binarySearch(arr, target, 0, pivotIndex);
    }
    else
        return binarySearch(arr, target, pivotIndex+1, n-1);
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
    int ans = searchInRotatedSortedArray(arr, target);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
7
3 4 5 6 7 1 2
*/