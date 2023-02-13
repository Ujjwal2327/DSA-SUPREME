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

// best
void sort0s1sAnd2s(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int i = 0;
    while(i<=e){    // = when arr[i] = arr[e] = 0    swap with arr[s]
        if(arr[i]==0){
            swap(arr[i], arr[s]);   // all values before s is 0
            i++;
            s++;
        }
        else if(arr[i]==2){
            swap(arr[i], arr[e]);   // all values after e is 1
            e--;
        }
        else    // if arr[i]==1, goto next element
            i++;    
    }
    printVector(arr);
}

void sort0s1sAnd2s2(vector<int>arr){
    int n = arr.size();
    // sort 0s and (1&2)
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

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort0s1sAnd2s(arr);
    sort0s1sAnd2s2(arr);

    return 0;
}