#include<iostream>
#include<vector>
using namespace std;

// not work when right subarray also contains element = arr[0] 
// not work on 7 7 9 7 7 7 7 7 7
int pivot(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid]>=arr[0]){   // mid lies in left subarray including pivot
            if(s==mid)
                break;
            s = mid;
        }
        else        // mid lies in right subarray
            e = mid - 1;

        mid = s + (e-s)/2;   
    }

    return mid;
}

// not work in 7 7 7 7 1 2
// not work on 7 7 9 7 7 7 7 7 7
int pivot2(vector<int>arr){
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

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = pivot(arr);
    cout << ans << '\n';

    int ans2 = pivot2(arr);
    cout << ans2 << '\n';

    return 0;
}

/*INPUTS
9
7 7 9 7 7 7 7 7 7

6
7 7 7 7 1 2

7
3 4 5 6 7 1 2
*/