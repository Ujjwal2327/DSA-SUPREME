// sort 0s and 1s   dutch national flag
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>arr){
    for(auto value : arr){
        cout << value << ' ';
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

    return 0;
}