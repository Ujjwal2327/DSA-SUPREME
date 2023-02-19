// https://www.geeksforgeeks.org/find-the-element-that-odd-number-of-times-in-olog-n-time/

#include<iostream>
#include<vector>
using namespace std;

// TC-O(logn)
int oddAppear(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;
    // first of pair should be in even place and second of pair should be in odd place
    // ans always come at even index
    while(s<=e){
        if(mid & 1){
            if(arr[mid] == arr[mid-1])      // mid is odd, so mid-1 will always >= 0
                s = mid + 1;
            else{
                // ans = mid;      // ans will always at even index but mid is odd
                e = mid - 1;
            }
        }
        else{
            if(mid+1<n && arr[mid]==arr[mid+1])
                s = mid + 1;
            else{       // mid is even and last, so its pair dont exist  OR  arr[mid]!=arr[mid+1], so its pair dont exist
                ans = mid;      // mid is possible ans
                e = mid - 1;
            }
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

// TC-O(n)
// using xor
int oddAppear2(vector<int>arr){
    int n = arr.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }

    return ans;
}

// TC-O(logn)
int oddAppear3(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(s==e)        // also when mid is end
            return mid;
        
        if(mid&1){
            if(arr[mid-1] == arr[mid])      // arr[even] = arr[odd]     we are at left  goto right
                s = mid + 1;
            else
                e = mid - 1;    // mid cant be ans and goto left
        }
        else{
            if(arr[mid]==arr[mid+1])        // arr[even] = arr[odd]     we are at left  goto right
                s = mid + 2;
            else
                e = mid;        // mid can be ans and goto left
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

    int ans = oddAppear(arr);
    cout<<ans<<'\n';

    int ans2 = oddAppear2(arr);
    cout<<ans<<'\n';

    int ans3 = oddAppear3(arr);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
15
1 1 2 2 1 1 2 2 13 1 1 4 4 6 6
*/