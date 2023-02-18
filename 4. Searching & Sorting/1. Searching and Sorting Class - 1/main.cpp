#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC- O(logn)
int binarySearch(int arr[], int n, int target){
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

// TC- O(logn)
int firstOccurence(vector<int>arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;   // if not found, return -1

    while(s<=e){
        int element = arr[mid];

        if(target == element){
            ans = mid;      // store in ans
            e = mid - 1;    // check in left
        }
        else if(target < mid)
            e = mid - 1;
        else
            s = mid + 1;
        
        mid = s + (e-s)/2;
    }

    return ans;
}

// TC- O(logn)
int peakElement(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<e){
        int element = arr[mid];
        // we cant apply arr[mid-1] condition as mid-1 can be equal to <0     if mid-1<0 => mid==0 => (s==0 && e==0) || (s==0&&e==1) => 2nd case can come inside loop
        if(element < arr[mid+1])    // left increasing sorted array excluding peak element
                                    // mid+1 cannot be equal to n     if mid+1==n => mid==n-1 => s==e==n-1 => s==e => loop condition fails
            s = mid + 1;
        else    // peak element or right decreasing sorted array
            e = mid;

        mid = s + (e-s)/2;
    }

    // if peak element is at n-1    it gives right ans with mid=n-1 so that e=s=n-1 and loops end

    // loops end when s=e so, all gives same ans
    // return mid;
    // return s;
    return e;
}

int main(){

    /*// binary search
        int arr[] = {2,4,6,8,10,12,16};
        int size = 7;
        int target = 2;

        int ans = binarySearch(arr, size, target);

        if(ans==-1){
            cout<<"target not found\n";
        }
        else{
            cout<<"target found at index "<<ans<<'\n';
        }
    */

    /*// binary search using STL
        vector<int>arr{1,2,3,4,5,6};
        int target = 10;
        int ans = binary_search(arr.begin(), arr.end(), target);
        cout<<ans<<'\n';
        if(ans)
            cout << "target found\n";
        else
            cout << "target not found\n";
        
        int arr2[] = {1,2,3,4,5,6};
        int target2 = 3;
        int size = 6;
        int ans2 = binary_search(arr2, arr2+size, target);
        if(ans2)
            cout << "target found\n";
        else
            cout << "target not found\n";
    */

    /*// find first occurence of an element in sorted array
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int target;
        cin>>target;
        int ans = firstOccurence(arr, target);
        cout << ans << '\n';
    */
    
    /*// first and last occurence of an element in sorted array using STL
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int target;
        cin>>target;
        auto lowerBound = lower_bound(arr.begin(), arr.end(), target);
        int ans = lowerBound - arr.begin();
        cout << ans << '\n';
        auto upperBound = upper_bound(arr.begin(), arr.end(), target);
        int ans2 = upperBound - arr.begin() - 1;
        cout << ans2 << '\n';
    */

    /*// total number of occurences of an element in sorted array using STL
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int target;
        cin>>target;
        int upperBound = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        int lowerBound = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        int ans = upperBound - lowerBound;
        cout<<ans<<'\n';
    */

    /*// find peak element in a mountain array
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans = peakElement(arr);
        cout<<ans<<'\n';
    */

    return 0;
}

/*INPUTS
// find first occurence of an element in an array
8
1 2 4 4 4 4 4 6
4

// first and last occurence using STL
8
1 2 4 4 4 4 4 6
4

// total number of occurences in sorted array using STL
8
1 2 4 4 4 4 4 6
4

// find peak element in a mountain array
8
6 8 10 7 5 3 2 1

3
6 8 10

3
10 8 4
*/