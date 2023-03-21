// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

// https://leetcode.com/problems/sort-colors/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

// best and inplace
void sort0s1sAnd2s(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int i = 0;
    while(i<=e){    // = when arr[i] = arr[e] = 0    swap with arr[s]
        if(arr[i]==0){
            swap(arr[i], arr[s]);   // all values before s are 0
            i++;
            s++;
        }
        else if(arr[i]==2){
            swap(arr[i], arr[e]);   // all values after e are 2
            e--;
        }
        else    // if arr[i]==1, goto next element
            i++;    
    }
    printVector(arr);
}

void sort0s1sAnd2s2(vector<int>arr){
    int n = arr.size();
    // sort 0s and (1s&2s)
    int s = 0;
    int e = n-1;
    while(s<=e){    // = is not necessary but used to find s for next loop for soring 1s and 2s
        if(arr[s]==0)
            s++;
        else{   // if arr[s] == 0 or 1
            swap(arr[s],arr[e]);
            e--;
        }
    }

    // sort 1s and 2s
    // s remains same after coming from above loop 
    e = n-1;
    while(s<e){
        if(arr[s]==1)
            s++;
        else{   // arr[s]=2
            swap(arr[s], arr[e]);
            e--;
        }
    }
    printVector(arr);
}

// not inplace
void sort0s1sAnd2s3(vector<int>arr){
    int n = arr.size();
    int cnt0 = 0;
    int cnt1 = 1;
    int cnt2 = 2;

    for(int i=0; i<n; i++){
        if(arr[i]==0)
            cnt0++;
        else if(arr[i]==1)
            cnt1++;
        else
            cnt2++;
    }

    int i=0;
    while(cnt0--)
        arr[i++] = 0;

    while(cnt1--)
        arr[i++] = 1;

    while(cnt2--)
        arr[i++] = 2;

    printVector(arr);
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort0s1sAnd2s(arr);
    sort0s1sAnd2s2(arr);
    sort0s1sAnd2s3(arr);

    return 0;
}

/*INPUTS
12
0 1 1 0 1 2 1 2 0 0 0 1
*/