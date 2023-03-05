// https://www.geeksforgeeks.org/find-k-closest-elements-given-value/
// https://leetcode.com/problems/find-k-closest-elements/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC-O(logn)    SC-O(1)
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

// TC-O(n)    SC-O(1)
void printVector(vector<int>arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    cout<<'\n';
}

// TC-O(logn + k)    SC-O(k)    gfg
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
        int leftDiff = target - arr[left];
        int rightDiff = arr[right] - target;
        
        if(leftDiff <= rightDiff)
            ans.push_back(arr[left--]);
        else
            ans.push_back(arr[right++]);
    }
    
    while(left>=0 && k>0){
        k--;
        ans.push_back(arr[left--]);
    }
    
    while(right<n && k>0){
        k--;
        ans.push_back(arr[right++]);
    }
        cout<<'\n';

    printVector(ans);
}


// TC-O(logn + klogk)    SC-O(k)    leetcode
// 2nd best solution
vector<int> findClosestElements(vector<int>& arr, int k, int target){
    int n = arr.size();
    int index = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    vector<int>ans;

    if(index == n){     // target > arr[n-1]
        for(int i=0; i<n && i<k; i++){
            ans.push_back(arr[n-i-1]);
            reverse(ans.begin(), ans.end());
        }
        printVector(ans);
        return ans;
    }

    int left = index-1;
    int right = index;

    while(left>=0 && right<n && k>0){
        k--;
        int leftDiff = target - arr[left];
        int rightDiff = arr[right] - target;
        
        if(leftDiff <= rightDiff)
            ans.push_back(arr[left--]);
        else
            ans.push_back(arr[right++]);
    }
    
    while(left>=0 && k>0){
        k--;
        ans.push_back(arr[left--]);
    }
    
    while(right<n && k>0){
        k--;
        ans.push_back(arr[right++]);
    }

    sort(ans.begin(), ans.end());
    printVector(ans);

    return ans;
}

// TC-O(nlogn)    SC-O(n)    leetcode
// sort with respect to diff
vector<int> findClosestElements2(vector<int>& arr, int k, int target){
    int n = arr.size();
    
    // diff, element
    vector<pair<int, int>>pairs;

    for(int i=0; i<n; i++){
        pairs.push_back( {abs(arr[i]-target) , arr[i]} );
    }
    
    sort(pairs.begin(), pairs.end());

    vector<int>ans;
    for(int i=0; i<n && i<k; i++){
        ans.push_back(pairs[i].second);
    }

    sort(ans.begin(), ans.end());
    printVector(ans);
    
    return ans;
}

// TC-O(n)    SC-O(k)    leetcode
// best and smallest
vector<int> findClosestElements3(vector<int>& arr, int k, int target) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(e-s+1>k){
        int leftDiff = target - arr[s];
        int rightDiff = arr[e] - target;
        if(leftDiff <= rightDiff)
            e--;
        else
            s++;
    }

    vector<int>ans;
    for(int i=s; i<=e; i++){
        ans.push_back(arr[i]);
    }

    // printVector(ans);
    printVector(vector<int>(arr.begin()+s, arr.begin()+e+1));
    
    // return ans;
    return vector<int>(arr.begin()+s, arr.begin()+e+1);
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
    findClosestElements(arr, k, target);
    findClosestElements2(arr, k, target);
    findClosestElements3(arr, k, target);

    return 0;
}

/*INPUTS
13
12 16 22 30 35 39 42 45 48 50 53 55 56
35  
4

6
1 1 1 10 10 10
9
3

6
1 1 1 10 10 10
-1
3

6
1 1 1 10 10 10
12
3
*/