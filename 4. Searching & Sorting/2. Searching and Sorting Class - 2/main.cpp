#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// not work in 7 7 7 7 1 2
int pivot(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        // handle middle 2 cases independently where sorted order breaks
        if(arr[mid]>arr[mid+1])
            return mid;
        if(arr[mid-1]>arr[mid])
            return mid-1;
        
        if(arr[s]>=arr[mid])    // mid present in right subarray and rotation present in left of mid
            e = mid - 1;
        else    // mid present in left subarray and rotation present in right of mid
            s = mid;
        mid = s + (e-s)/2;
    }
    return -1;
}

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

int searchInRotatedSortedArray(vector<int>arr, int target){
    int n = arr.size();
    int pivotIndex = pivot(arr);
    if(target>=arr[0] && target<=arr[pivotIndex]){
        return binarySearch(arr, target, 0, pivotIndex);
    }
    else
        return binarySearch(arr, target, pivotIndex+1, n-1);
}

int sqrt(int n){
    int s=0;
    int e=n;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        long long prod = mid*mid;
        if(prod==n)
            return mid;
        else if(prod<n){
            ans = mid;
            s = mid+1;
        }
        else
            e = mid - 1;
        mid = s + (e-s)/2;
    }
    return ans;
}

double sqrt2(double n, int precision){
    int ans = sqrt(n);
    double step = 0.1;
    double finalAns = ans;
    for(int i=0; i<precision; i++){
        for(float j=finalAns; j*j<=n; j+=step){
            finalAns = j;
        }
        step = step/10;
    }
    return finalAns;
}

bool binarySearchInMatrix(vector<vector<int>>arr, int target){
    int rows = arr.size();
    int cols = arr[0].size();
    int total = rows*cols;
    int s = 0;
    int e = total-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        int i = mid / cols;
        int j = mid % cols;
        if(target == arr[i][j]){
            cout << "found at " << i << " row and " << j << " col\n";
            return true;
        }
        else if(target < arr[i][j])
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e-s)/2;
    }
    
    cout << "not found\n";
    return false;
}

int main(){

    /*// find pivot element in an array
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans = pivot(arr);
        cout << ans << '\n';
    */

    /*// search in rotated sorted array
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
    */

    /*// sqrt of an int number
        int n;
        cin>>n;
        int ans = sqrt(n);
        cout<<ans<<'\n';
    */

    /*// sqrt of an double number upto given precision
        double n;
        cin>>n;
        int precision;
        cin>>precision;
        double ans = sqrt2(n, precision);
        cout<<ans<<'\n';
    */

    /*// binary search in matrix
        int rows;
        int cols;
        cin>>rows>>cols;
        vector<vector<int>>arr(rows, vector<int>(cols));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cin>>arr[i][j];
            }
        }
        int target;
        cin>>target;
        int ans = binarySearchInMatrix(arr, target);
        cout<<ans<<'\n';
    */

    return 0;
}

/*INPUTS
// pivot element in sorted rotated array
7
3 4 5 6 7 1 2

// search in rotated sorted array
7
3 4 5 6 7 1 2

// sqrt of an int number
35

// sqrt of an double number upto given precision
35
7

// binary search in matrix
4 3
1 2 3 4
5 6 7 8
9 10 11 12
5
*/