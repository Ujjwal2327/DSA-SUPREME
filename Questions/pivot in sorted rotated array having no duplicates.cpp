// highest

#include<iostream>
#include<vector>
using namespace std;

int pivot(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    if(arr[n-1]>=arr[0])     // array having no rotation    = for single element in an array
        return n-1;

    while(s<=e){
        if(arr[mid]>=arr[0]){       // mid lies in left subarray including pivot
            if(s==mid)
                return mid;
            else
                s = mid;
        }
        else        // mid lies in right subarray
            e = mid - 1;

        mid = s + (e-s)/2;
    }

    return -1;
}

int pivot2(vector<int>arr){
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

int pivot3(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(mid+1<n && arr[mid]>arr[mid+1])
            return mid;
        if(mid-1>=0 && arr[mid-1]>arr[mid])
            return mid-1;
        if(s==e)
            return mid;
        
        if(arr[mid]>arr[s])
            s = mid + 1;
        else
            e = mid - 1;
        mid = s + (e-s)/2;
    }
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

    int ans3 = pivot3(arr);
    cout << ans2 << '\n';

    return 0;
}

/*INPUTS
7
3 4 5 6 7 1 2

6
2 4 6 8 9 10

6
10 2 4 6 8 9
*/