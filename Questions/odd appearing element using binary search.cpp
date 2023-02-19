// https://www.geeksforgeeks.org/find-the-element-that-odd-number-of-times-in-olog-n-time/

#include<iostream>
#include<vector>
using namespace std;

int oddAppear(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;
    // first of pair should be in even place and second of pair should be in odd place
    while(s<=e){
        cout<<s<<' '<<mid<<' '<<e<<'\n';
        if(mid & 1){
            if(arr[mid] == arr[mid-1])      // mid is odd, so mid-1 will always >= 0
                s = mid + 1;
            else{
                ans = mid;      // mid is possible ans
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

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = oddAppear(arr);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
15
1 1 2 2 1 1 2 2 13 1 1 4 4 6 6
*/