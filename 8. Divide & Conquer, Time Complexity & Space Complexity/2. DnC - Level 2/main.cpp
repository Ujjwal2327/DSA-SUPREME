#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>&arr){
    for(auto i:arr)
        cout << i << ' ';
    cout << '\n';
}

int partition(vector<int>&arr, int s, int e){
    int pivotIndex = s;
    int pivot = arr[s];

    int cnt = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] < pivot)
            cnt++;
    }

    int correctIndex = s + cnt;
    swap(arr[pivotIndex], arr[correctIndex]);
    pivotIndex = correctIndex;

    int i=s, j=e;
    while(i<correctIndex && j>correctIndex){
        while(arr[i] < pivot)
            i++;
        while(arr[j] >= pivot)
            j--;
        if(i<correctIndex && j>correctIndex)
            swap(arr[i++], arr[j--]);
    }

    return correctIndex;
}

void quickSort(vector<int>&arr, int s, int e){
    if(s>=e)        // s==e single element is sorted already    s>e invalid array
        return;
    
    // partition
    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);     // left half
    quickSort(arr, p+1, e);     // right half

}

void stringPermutations(string &str, int i){
    if(i==str.length()){
        cout << str << ' ';
        return;
    }

    for(int j=i; j<str.length(); j++){
        swap(str[i], str[j]);
        stringPermutations(str, i+1);
        swap(str[i], str[j]);   // backtracking     to create back to original given string
    }

}

int main(){

    vector<int>arr{5,2,5,8,2,1,5,6,34,3};
    int s = 0;
    int e = arr.size()-1;
    printVector(arr);
    quickSort(arr, s, e);
    printVector(arr);

    string str = "abc";
    stringPermutations(str, 0);
    cout << '\n';

    return 0;
}