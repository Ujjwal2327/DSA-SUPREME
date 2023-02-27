// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include<iostream>
#include<vector>
using namespace std;

// TC- O(logn)
int peakElement(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<e){
        int element = arr[mid];
        if(mid+1<n && element > arr[mid+1])    // peak element or right decreasing sorted array
            e = mid;
        else    // left increasing sorted array excluding peak element
            s = mid + 1;

        mid = s + (e-s)/2;
    }

    // if peak element is at n-1    it gives right ans with mid=n-1 so that e=s=n-1 and loops end

    // loop ends when s=e so, all gives same ans
    // return mid;
    // return s;
    return e;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = peakElement(arr);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
8
6 8 10 7 5 3 2 1

3
6 8 10

3
10 8 4
*/