#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

int findUnique(vector<int>arr){
    int ans = 0;
    for(int i=0; i<arr.size(); i++){
        // all duplicates will cancel each other
        ans = ans ^ arr[i];
    }
    return ans;
}

// arrays having no duplicate
void findUnion(vector<int>arr1, vector<int>arr2){
    vector<int>ans;
    for(int i=0; i<arr1.size(); i++){
        ans.push_back(arr1[i]);
    }
    for(int i=0; i<arr2.size(); i++){
        ans.push_back(arr2[i]);
    }
    printVector(ans);
}

void findIntersection(vector<int>arr1, vector<int>arr2){
    vector<int>ans;
    for(int i=0; i<arr1.size(); i++){
        int element = arr1[i];
        for(int j=0; j<arr2.size(); j++){
            if(element == arr2[j]){
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    printVector(ans);
}

// for each loop
void printVector2(vector<int>arr){
    for(auto value : arr){
        cout << value << ' ';
    }
}

void printAllPairs(vector<int>arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cout << arr[i] << ' ' << arr[j] <<'\n';
        }
    }
    cout<<'\n';
}

void pairSum(vector<int>arr, int sum){
    int n = arr.size();

    for(int i=0; i<n; i++){
        int element1 = arr[i];

        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==sum)
                cout<<arr[i]<<' '<<arr[j]<<'\n';
        }
    }
    cout<<'\n';
}

void tripletSum(vector<int>arr, int sum){
    int n = arr.size();

    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){

            for(int k=j+1; k<n; k++){

                if(arr[i] + arr[j] + arr[k] == sum)
                    cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] <<'\n';
            }
        }
    }
    cout<<'\n';
}

void quadSum(vector<int>arr, int sum){
    int n = arr.size();

    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){

            for(int k=j+1; k<n; k++){

                for(int p=k+1; p<n; p++){

                if(arr[i] + arr[j] + arr[k] + arr[p] == sum)
                    cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] << ' ' << arr[p] <<'\n';
                }
            }
        }
    }
}

void sort0sand1s(vector<int>arr){
    int n = arr.size();
    // s is where we can insert next 0
    int s=0;
    // e is where we can insert next 1
    int e=n-1;
    // i is where we have to process    use for traversing
    int i=0;
    while(i<e){
        if(arr[i]==0){
            swap(arr[i],arr[s++]);
            i++;
        }
        else{
            swap(arr[i],arr[e--]);
        }
    }
    printVector2(arr);
}

int main(){

    /*// vector creation, insertion, removing an element, printing a vector, arr.size(), arr.capacity(), sizeof(arr)
        // vector creation
            vector<int>arr;
            // sizeof(arr) is compiler dependent
            cout << sizeof(arr) <<'\n';
            cout << arr.size() <<'\n';
            cout << arr.capacity() <<'\n';
            cout<<'\n';

        // insert
            arr.push_back(5);
            arr.push_back(6);
            arr.push_back(4);
            arr.push_back(10);
            cout << sizeof(arr) <<'\n';
            cout << arr.size() <<'\n';
            cout << arr.capacity() <<'\n';
            // give ERROR
            // cout << arr <<'\n';
        // print
            printVector(arr);
            cout<<'\n';

        // remove
            arr.pop_back();
            cout << sizeof(arr) <<'\n';
            cout << arr.size() <<'\n';
            cout << arr.capacity() <<'\n';
            printVector(arr);
            cout<<'\n';
    */

    /*// initialization of an vector of a particular size
        vector<int>arr2(10);
        printVector(arr2);
        cout<<arr2.size()<<'\n';
        cout<<arr2.capacity()<<'\n';
    */

    /*// initialization all elements with a particular value
        vector<int>arr3(10,-2);
        cout<<arr3.size()<<'\n';
        cout<<arr3.capacity()<<'\n';
        printVector(arr3);
    */

    /*// initialization of a vector of user input
        int n;
        cin>>n;
        vector<int>arr4(n);
        cout<<arr4.size()<<'\n';
        cout<<arr4.capacity()<<'\n';
        printVector(arr4);
        cout<<'\n';

        vector<int>arr5(n, 10);
        cout<<arr5.size()<<'\n';
        cout<<arr5.capacity()<<'\n';
        printVector(arr5);
        cout<<'\n';
    */

    /*// initialization with some values and arr.empty()
        vector<int>arr6{10,20,30};
        cout<<arr6.size()<<'\n';
        cout<<arr6.capacity()<<'\n';
        printVector(arr6);
        cout<<arr6.empty()<<'\n';
    */

    /*// find unique element
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<arr.size(); i++){
            cin>>arr[i];
        }
        int ans = findUnique(arr);
        cout<<ans<<'\n';
    */

    /*// find union of 2 arrays having no duplicate
        int m;
        cin>>m;
        int n;
        cin>>n;
        vector<int>arr1(m);
        vector<int>arr2(n);
        for(int i=0; i<m; i++){
            cin>>arr1[i];
        }
        for(int i=0; i<n; i++){
            cin>>arr2[i];
        }
        findUnion(arr1, arr2);
    */

    /*// find intersection of 2 arrays
        int m;
        cin>>m;
        int n;
        cin>>n;
        vector<int>arr1(m);
        vector<int>arr2(n);
        for(int i=0; i<m; i++){
            cin>>arr1[i];
        }
        for(int i=0; i<n; i++){
            cin>>arr2[i];
        }
        findIntersection(arr1, arr2);
    */

    /*// print all pairs of a vector
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        printAllPairs(arr);
    */

    /*// pairSum    print all pairs with a given sum and array
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int sum;
        cin>>sum;
        pairSum(arr, sum);
    */

    /*// tripletSum   print all triplets with a given sum and array
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int sum;
        cin>>sum;
        tripletSum(arr, sum);
    */

    /*// quadSum   print all det of 4 elements with a given sum and array
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int sum;
        cin>>sum;
        quadSum(arr, sum);
    */

    /*// sort 0s and 1s   dutch national flag
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort0sand1s(arr);
    */

    /*// declaration
        vector<int>arr;
        cout<<arr.size()<<'\n';
        cout<<arr.capacity()<<'\n';
    */

    return 0;
}