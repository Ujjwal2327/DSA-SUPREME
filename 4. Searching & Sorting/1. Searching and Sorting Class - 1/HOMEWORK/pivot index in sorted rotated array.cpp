#include<iostream>
#include<vector>
using namespace std;

// not work when right subarray also contains element = arr[0] 
// not work on 7 7 9 7 7 7 7 7 7
int pivotIndex(vector<int>arr){
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

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = pivotIndex(arr);
    cout << ans << '\n';

    return 0;
}