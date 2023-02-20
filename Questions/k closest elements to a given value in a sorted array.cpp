// https://www.geeksforgeeks.org/find-k-closest-elements-given-value/

#include<iostream>
#include<vector>
using namespace std;

// TC-O(logn)
int binarySearch(vector<int>arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(target == arr[mid])
            return mid;
        else if(target < arr[mid])
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e-s)/2;
    }

    return -1;
}

// TC-O(n)
void printVector(vector<int>arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    cout<<'\n';
}

// TC-O(logn + k)
void kClosest(vector<int>arr, int target, int k){
    int n = arr.size();
    int index = binarySearch(arr, target);

    if(index==-1)
        return;
    
    vector<int>ans;
    int left = index-1;
    int right = index+1;

    while(left>=0 && right<n && k>0){
        k--;
        cout<<k<<' ';
        int leftDiff = target - arr[left];
        int rightDiff = arr[right] - target;
        
        if(leftDiff <= rightDiff)
            ans.push_back(arr[left--]);
        else
            ans.push_back(arr[right++]);
    }
    
    while(left>=0 && k>0){
        k--;
        cout<<k<<' ';
        ans.push_back(arr[left--]);
    }
    
    while(right<n && k>0){
        k--;
        cout<<k<<' ';
        ans.push_back(arr[right++]);
    }
        cout<<'\n';

    printVector(ans);
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
    int k;
    cin>>k;

    kClosest(arr, target, k);

    return 0;
}

/*INPUTS
13
12 16 22 30 35 39 42 45 48 50 53 55 56
35  
4
*/