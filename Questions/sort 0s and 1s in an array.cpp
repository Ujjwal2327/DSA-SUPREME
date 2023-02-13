// sort 0s and 1s

// https://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>arr){
    for(auto value : arr){
        cout << value << ' ';
    }
    cout<<'\n';
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
            i++;    // i always points to s
        }
        else{
            swap(arr[i],arr[e--]);
        }
    }
    printVector(arr);
}

// best 
void sort0sand1s2(vector<int>arr){
    int n = arr.size();
    int s=0, e=n-1;
    while(s<e){
        // all elements before s are 0
        if(arr[s]==0)
            s++;
        // all elements after e are 1
        else{
            swap(arr[s], arr[e]);
            e--;
        }
    }
    printVector(arr);
}

void sort0sand1s3(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<e){
        if(arr[s]==0)
            s++;
        else if(arr[e]==1)
            e--;
        else{
            swap(arr[s], arr[e]);
            s++;
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
    sort0sand1s(arr);
    sort0sand1s2(arr);
    sort0sand1s3(arr);

    return 0;
}

/*INPUTS
10
0 1 0 1 0 0 1 1 1 0
*/