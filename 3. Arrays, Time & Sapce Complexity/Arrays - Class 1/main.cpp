#include<iostream>
#include<limits.h>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

void inc(int arr[], int size){
    arr[0] = arr[0]+10;
    printArray(arr, size);
}

bool linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(key == arr[i])
            return true;
    }
    return false;
}

void cnt0sAnd1s(int arr[], int n){
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            cnt0++;
        else if(arr[i]==1)
            cnt1++;
    }
    cout << "number of zeroes-> " << cnt0 <<'\n';
    cout << "number of ones-> " << cnt1 <<'\n';
}

int getMax(int arr[], int n){
    int ans = INT_MIN;
    for(int i=0;  i<n; i++){
        if(arr[i]>ans)
            ans = arr[i];
    }
    return ans;
}

int getMin(int arr[], int n){
    int ans = INT_MAX;
    for(int i=0;  i<n; i++){
        if(arr[i]<ans)
            ans = arr[i];
    }
    return ans;
}

void printExtreme(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(s==e)
            cout<<arr[s];
        else
            cout<<arr[s]<<' '<<arr[e]<<' ';
        s++;
        e--;
    }
}

void reverseArray(int arr[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        swap(arr[s++], arr[e--]);
    }
}

int main(){

    /*// declaration
        int arr[7];
        cout<<arr<<'\n';
        cout<<&arr<<'\n';
    */

    /*// initialisation
        int arr1[] = {2,3,4,6,7};
        int arr2[5] = {2,3,4,6,7};
        int arr3[10] = {2,3,4,6,7};
        // int arr4[4] = {2,3,4,6,7};
    */

    /*// index and access in array
        int arr[] = {1,3,5,7,9};
        cout<<arr[2]<<'\n';

        for(int i=0; i<5; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    */

    /*// taking input in array
        int arr[10];
        for(int i=0; i<10; i++){
            cin >> arr[i];
        }
        for(int i=0; i<10; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    */

    /*// take n elements and print their doubles 
        int arr[500];
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n; i++){
            cout<<2*arr[i]<<' ';
        }
        cout<<'\n';
    */

    /*// make all items of an array to 1
        int arr[500];
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n; i++){
            arr[i]=1;
        }
        for(int i=0; i<n; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    */

    /*// remaining values will be 0
        int arr[10]={1,2};
        for(int i=0; i<10; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    */

    /*// declaration
        int arr[10];
        for(int i=0; i<10; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    */

    /*// functions and array    pass by reference
        int arr[] = {5,6};
        int size = 2;
        inc(arr,size);
        printArray(arr, size);
    */

    /*// linear search function
        int arr[]={1,6,2,3,73};
        int n=5;
        int key;
        cin>>key;
        if(linearSearch(arr, n, key)){
            cout<<"present\n";
        }
        else{
            cout<<"absent\n";
        }
    */
    
    /*// linear search without function
        int arr[]={1,6,2,3,73};
        int n=5;
        int key;
        cin>>key;
        bool flag=false;
        for(int i=0; i<n; i++){
            if(key == arr[i]){
                flag = true;
                break;
            }
        }
        if(flag)
            cout<<"present\n";
        else
            cout<<"absent\n";
    */

    /*// count 0s and 1s in array
        int arr[] = {0,1,1,1,0,0,0,0,1,0,1,0,1,0,1,2,4,5,7};
        int n = 19;
        cnt0sAnd1s(arr, n);
    */

    /*// maximum number in an array
        int arr[] = {2,4,6,1,3,7,9,12,56,43,21};
        int n = 11;
        cout << getMax(arr, n) <<'\n';
    */

    /*// minimum number in an array
        int arr[] = {2,4,6,1,3,7,9,12,56,43,21};
        int n = 11;
        cout << getMin(arr, n) <<'\n';
    */

    /*// print extremes of an array
        int arr[] = {10,20,30,40,50,60,70};
        int n = 7;
        printExtreme(arr, n);
    */

    /*// reverse an array
        int arr[] = {10,20,30,40,50,60,70};
        int n = 7;
        reverseArray(arr, n);
        printArray(arr, n);
    */

    return 0;
}