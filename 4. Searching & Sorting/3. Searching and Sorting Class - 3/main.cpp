#include<iostream>
#include<vector>
using namespace std;

int searchInNearlySortedArray(vector<int>arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(target == arr[mid])
            return mid;
        else if(mid+1<n && target == arr[mid+1])
            return mid+1;
        // else if(mid-1>s && target == arr[mid-1])     // this will also work
        else if(mid-1>=0 && target == arr[mid-1])
            return mid-1;
        
        if(target < arr[mid])
            e = mid - 2;
            // e = mid - 1;     // this will also work
        else
            s = mid + 2;
            // s = mid + 1;     // this will also work
        mid = s + (e-s)/2;
    }
    
    return -1;
}

int divideAbyB(int dividend, int divisor){
    if(divisor == 0)
        return -1;

    int a = abs(dividend);
    int b = abs(divisor);
    int s = 0;
    int e = a;
    int mid = s + (e-s)/2;
    int ans = 0;

    while(s<=e){
        if(b * mid == a){   
            ans = mid;
            break;
        }
        else if(b * mid < a){
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
        mid = s + (e-s)/2;
    }

    if( (divisor>0 && dividend>0) || (divisor<0 && dividend<0) )
        return ans;
    else
        return -ans;
}

int oddOcc(vector<int>arr){
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

    /*// binary search in nearly sorted array
    // every element in ith position in sorted array will found in i, i+1 or i-1 position in nearly sorted array
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int target;
        cin>>target;
        
        int ans = searchInNearlySortedArray(arr, target);
        if(ans!=-1)
            cout << "target found at index " << ans << '\n';
        else
            cout << "target not found\n";
    */

    /*// divide 2 numbers using binary search
        int dividend;
        int divisor;
        cin>>dividend>>divisor;
        int ans = divideAbyB(dividend, divisor);
        cout<<ans<<'\n';
        // cout<<22/(-7)<<'\n';
        // cout<<(-22)/(-7)<<'\n';
        // cout<<(-22)/7<<'\n';
        // cout<<(int)(-3.94)<<'\n';
    */

    /*// find odd occuring element
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int ans = oddOcc(arr);
        cout<<ans<<'\n';
    */

    return 0;
}

/*INPUTS
// binary search in nearly sorted array
7
10 3 40 20 50 80 40
40

// divide 2 numbers using binary search
-22 7

// find odd occuring element
15
1 1 2 2 1 1 2 2 13 1 1 4 4 6 6
*/