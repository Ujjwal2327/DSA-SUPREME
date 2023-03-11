#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>       // for accumulate function
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout << "\n";
}

// custom comparater in vector
bool intCmp(int first, int second){
    // cout<<first<<' '<<second<<'\n';
    return first < second;      // first parameter will come first if condition is true     first parameter will come first if first < second
        // true means return first
}

bool intCmp2(int first, int second){
    return first > second;      // first parameter will come first if condition is true     first parameter will come first if first > second
        // true means return first
}


void printVector(vector<int>arr){
    for(auto i:arr)
        cout << i << ' ';
    cout << "\n";
}


void printStringVector(vector<string>arr){
    for(auto i:arr)
        cout<<i<<' ';
    cout<<"\n\n";
}


int stringValue(string s){
    int ans = 0;
    for(auto i:s)
        ans += i;
    return ans;
}

// custom comparater in vector of strings
// sort with respect to sum of ascii values of chars of string
bool stringCmp(string first, string second){
    return stringValue(first) < stringValue(second);
}

void printStringVectorValue(vector<string>arr){
    for(auto i:arr){
        cout<<stringValue(i)<<' ';
    }
    cout<<'\n';
}

bool stringCmp2(string first, string second){
    return first > second;
}

// custom comparater in string
bool charCmp(char first, char second){
    return first < second;
}

bool charCmp2(char first, char second){
    return first > second;      
}

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


    /*// sort function in array
        int arr[] = {5,3,1,4,2};
        int n = sizeof(arr)/sizeof(int);
        sort(arr, arr + n);
        printArray(arr, n);
        
        int arr2[] = {5,3,1,4,2};
        sort(arr2, arr2 + n, greater<int>());
        printArray(arr2, n);
        
    // custom comparater in sort function in vector
        int arr3[] = {5,3,1,4,2};
        sort(arr3, arr3 + n, intCmp);
        printArray(arr3, n);
        
        int arr4[] = {5,3,1,4,2};
        sort(arr4, arr4 + n, intCmp2);
        printArray(arr4, n);
    */
        
    /*// sort function in vector
        vector<int>arr{5,3,1,2,4};
        sort(arr.begin(), arr.end());
        printVector(arr);

        arr = {5,3,1,2,4};
        sort(arr.begin(), arr.end(), greater<int>());
        printVector(arr);

    // custom comparater in sort function in vector
        arr = {5,3,1,2,4};
        sort(arr.begin(), arr.end(), intCmp);
        printVector(arr);

        arr = {5,3,1,2,4};
        sort(arr.begin(), arr.end(), intCmp2);
        printVector(arr);
    */

    /*// sort function in vector of strings
        vector<string>arr{"love", "babbar", "rahul", "sandeep"};
        sort(arr.begin(), arr.end());
        printStringVector(arr);

        arr = {"love", "babbar", "rahul", "sandeep"};
        sort(arr.begin(), arr.end(), greater<string>());
        printStringVector(arr);

    // custom comparater in sort function in vector of strings
        arr = {"love", "babbar", "rahul", "sandeep"};
        sort(arr.begin(), arr.end(), stringCmp);
        printStringVectorValue(arr);
        printStringVector(arr);

        arr = {"love", "babbar", "rahul", "sandeep"};
        sort(arr.begin(), arr.end(), stringCmp2);
        printStringVector(arr);
    */

    /*// sort function in string
        string s = "babbar";
        sort(s.begin(), s.end());
        cout<<s<<'\n';

        s = "babbar";
        sort(s.begin(), s.end(), greater<char>());
        cout<<s<<'\n';

    // custom comparater in sort function in string
        s = "babbar";
        sort(s.begin(), s.end(), charCmp);
        cout<<s<<'\n';

        s = "babbar";
        sort(s.begin(), s.end(), charCmp2);
        cout<<s<<'\n';
        cout<<'\n';
    */


    /*// accumulate function
        // in arrays
        int arr[] = {10,50,30,20,40};
        int n = sizeof(arr)/sizeof(int);
        int ans = accumulate(arr, arr+n, 0);
        cout << ans << '\n';
        ans = accumulate(arr, arr+n, 1, multiplies<int>());     // multiplies<int>() is builtin predicate
        cout << ans << "\n\n";

        // in vector
        vector<int>arr2{10,50,30,20,40};
        int ans2 = accumulate(arr2.begin(), arr2.end(), 0);
        cout << ans2 << '\n';
        ans2 = accumulate(arr2.begin(), arr2.end(), 1, multiplies<int>());     // multiplies<int>() is builtin predicate
        cout << ans2 << "\n\n";

        // in string
        string s = "abc";
        int ans3 = accumulate(s.begin(), s.end(), 0);
        cout << ans3 << ' ' << 'a'+'b'+'c' << '\n';
        ans3 = accumulate(s.begin(), s.end(), 1, multiplies<int>());     // multiplies<int>() is builtin predicate
        cout << ans3 << ' ' << 'a'*'b'*'c' << '\n';
    */


    /*// max_element function in array
        int arr[] = {10,50,30,40,20};
        int n = sizeof(arr)/sizeof(int);
        int ans = *max_element(arr, arr + n);
        int index = max_element(arr, arr + n) - arr;
        cout << ans << ' ' << index << '\n';
    */

    /*// max_element function in vector
        vector<int>arr{10,50,30,40,20};
        int ans = *max_element(arr.begin(), arr.end());
        int index = max_element(arr.begin(), arr.end()) - arr.begin();
        cout << ans << ' ' << index << '\n';
    */

    /*// max_element function in string
        string s = "Ujjwal2027";
        char ans = *max_element(s.begin(), s.end());
        int index = max_element(s.begin(), s.end()) - s.begin();
        cout << ans << ' ' << index << '\n';
    */

    return 0;
}