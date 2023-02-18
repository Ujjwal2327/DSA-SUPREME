#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC- O(logn)
int binarySearch(vector<int>arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        int element = arr[mid];
        if(target==element)
            return mid;
        else if(target < element){
            e = mid - 1;
        }
        else
            s = mid + 1;

        mid = s + (e-s)/2;
    }

    return -1;
}

int main(){

    /*// binary search
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int target;
        cin>>target;

        int ans = binarySearch(arr, target);

        if(ans==-1){
            cout<<"target not found\n";
        }
        else{
            cout<<"target found at index "<<ans<<'\n';
        }
    */

    /*// binary search using STL
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int target;
        cin>>target;

        bool ans = binary_search(arr.begin(), arr.end(), target);
        cout<<ans<<'\n';
        if(ans)
            cout << "target found\n";
        else
            cout << "target not found\n";
    */

    return 0;
}

/*INPUTS
8
1 2 4 5 6 10 12 15
4
*/