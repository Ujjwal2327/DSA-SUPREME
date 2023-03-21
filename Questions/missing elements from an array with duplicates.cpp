// array has elements from 1 to n

#include<iostream>
#include<vector>
using namespace std;

// visited method
void missingElements(vector<int> arr) {
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        int index = abs(arr[i]);
        if(arr[index-1]>0)        // if not visited, mark them visited      element is mapped to elementValue-1 index of array
            arr[index-1] = -arr[index-1];
    }

    for(int i=0; i<n; i++){
        if(arr[i]>0)        // all unvisited indices are missing elements
            cout << i+1 << ' ';     // element is mapped to elementValue-1 index of array
    }
    cout << '\n';
}

// mappingg and swapping
void missingElements2(vector<int>& arr){
    int n = arr.size();

    int i=0;
    while(i<n){
        if(arr[arr[i]-1] == arr[i]){
            ++i;
        }
        else{
            swap(arr[i] , arr[arr[i]-1]);
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i]!=i+1)
            cout << i+1 << ' ';
    }
    cout << '\n';
}

int main(){

    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    missingElements(arr);
    missingElements2(arr);

    return 0;
}

/*INPUTS
10
2 8 4 2 6 9 1 6 8 8
*/