#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>&arr){
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void merge2SortedArrays(vector<int>&arr, int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;
    vector<int>left(len1);
    vector<int>right(len2);

    int j=0;
    for(int i=s; i<=mid; i++)
        left[j++] = arr[i];

    j=0;
    for(int i=mid+1; i<=e; i++)
        right[j++] = arr[i];

    j=0;
    int i=0;
    int k=s;
    while(i<len1 && j<len2){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i<len1)
        arr[k++] = left[i++];
    
    while(j<len2)
        arr[k++] = right[j++];

}

void mergeSort(vector<int>&arr, int s, int e){
    if(s>=e)        // single element is sorted and s>e is INVALID
        return;
    
    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge2SortedArrays(arr, s, e);
}


int main(){

    /*
    */
    // merge sort
        vector<int>arr{7,3,2,16,2,2,2,2,2,24,4,11,9};
        int s = 0;
        int e = arr.size()-1;
        mergeSort(arr, s, e);
        printVector(arr);
    /*
    */
    // 

    /*
    */
    // 

    /*
    */
    // 

    /*
    */
    // 

    return 0;
}