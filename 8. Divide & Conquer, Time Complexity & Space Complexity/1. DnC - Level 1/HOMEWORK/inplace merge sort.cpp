// https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(auto i:arr)
        cout << i << ' ';
    cout << '\n';
}

void inplaceMerge(vector<int>&arr, int s, int e){
    int mid = s + (e-s)/2;

    int i = s;
    int j = mid+1;
    int ans = 0;

    if(arr[j]>=arr[mid])
        return;

    while(i<=e && j<=e && i!=j){
        if(arr[i]<=arr[j]){
            i++;
        }
        else{
            int temp = arr[j];
            int k = j;
            while(k>i){
                arr[k] = arr[k-1];
                k--;
            }
            arr[i] = temp;
            i++;
            j++;
        }
    }

}

void mergeSort(vector<int>&arr, int s, int e){
    if(s>=e)
        return ;
    
    int mid = s + (e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    inplaceMerge(arr, s, e);
}

int main(){

    vector<int>arr{2,4,1,3,5};
    int s = 0, e = arr.size()-1;
    mergeSort(arr, s, e);
    printVector(arr);

    return 0;
}