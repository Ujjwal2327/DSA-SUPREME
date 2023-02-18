#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    /*// binary search in array
        int arr[] = {10,20,30,40,50,50,50,50,50,50,60,70,80,90,100};
        int size = 15;

        // if present
        int target = 50;
        bool binarySearch = binary_search(arr, arr+size, target);
        cout << binarySearch << '\n';
        
        // if absent
        int target2 = 150;
        bool binarySearch2 = binary_search(arr, arr+size, target2);
        cout << binarySearch2 << '\n';
    */

    /*// lower_bound and upper_bound of an element in sorted array
        int arr[] = {10,20,30,40,50,50,50,50,50,50,60,70,80,90,100};
        int size = 15;

        // if present
        int target = 50;
        auto lowerBoundIterator = lower_bound(arr, arr+size, target);
        int lowerBound = lowerBoundIterator - arr;
        cout << lowerBound << '\n';
        
        auto upperBoundIterator = upper_bound(arr, arr+size, target);
        int upperBound = upperBoundIterator - arr;
        cout << upperBound << '\n';     // next index after last coourence of an element if present

        int noOfOcc = upperBound - lowerBound;
        cout << noOfOcc << '\n';
        cout<<'\n';


        // if absent
        int target2 = 35;
        auto lowerBoundIterator2 = lower_bound(arr, arr+size, target2);
        int lowerBound2 = lowerBoundIterator2 - arr;
        cout << lowerBound2 << '\n';

        auto upperBoundIterator2 = upper_bound(arr, arr+size, target2);
        int upperBound2 = upperBoundIterator2 - arr;
        cout << upperBound2 << '\n';

        int noOfOcc2 = upperBound2 - lowerBound2;
        cout << noOfOcc2 << '\n';
    */
    
    /*// binary search in vector
        vector<int>arr{10,20,30,40,50,50,50,50,50,50,60,70,80,90,100};

        // if present
        int target = 50;
        bool binarySearch = binary_search(arr.begin(), arr.end(), target);
        cout << binarySearch << '\n';
        
        // if absent
        int target2 = 150;
        bool binarySearch2 = binary_search(arr.begin(), arr.end(), target2);
        cout << binarySearch2 << '\n';
    */

    /*// lower_bound and upper_bound of an element in sorted array
        vector<int>arr{10,20,30,40,50,50,50,50,50,50,60,70,80,90,100};

        // if present
        int target = 50;
        auto lowerBoundIterator = lower_bound(arr.begin(), arr.end(), target);
        int lowerBound = lowerBoundIterator - arr.begin();
        cout << lowerBound << '\n';
        
        auto upperBoundIterator = upper_bound(arr.begin(), arr.end(), target);
        int upperBound = upperBoundIterator - arr.begin();
        cout << upperBound << '\n';     // next index after last coourence of an element if present

        int noOfOcc = upperBound - lowerBound;
        cout << noOfOcc << '\n';
        cout<<'\n';


        // if absent
        int target2 = 35;
        auto lowerBoundIterator2 = lower_bound(arr.begin(), arr.end(), target2);
        int lowerBound2 = lowerBoundIterator2 - arr.begin();
        cout << lowerBound2 << '\n';

        auto upperBoundIterator2 = upper_bound(arr.begin(), arr.end(), target2);
        int upperBound2 = upperBoundIterator2 - arr.begin();
        cout << upperBound2 << '\n';

        int noOfOcc2 = upperBound2 - lowerBound2;
        cout << noOfOcc2 << '\n';
    */

    return 0;
}