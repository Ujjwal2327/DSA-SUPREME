// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout<<'\n';
}

// order of elements changes
void moveNegatives(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<e){
        if(arr[s]<0)
            s++;
        else{
            swap(arr[s], arr[e]);   //odrer will change
            e--;
        }
    }
    printVector(arr);
}

// order of -ve elements remains same
// order of +ve elements changes
void moveNegatives2(vector<int>arr){
    int i = 0;
    int n = 0;
    while(i<arr.size()){
        if(arr[i]<0){
            swap(arr[n], arr[i]);
            i++;
            n++;    // n is the next position to insert a -ve number
        }
        else{
            i++;
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
    moveNegatives(arr);
    moveNegatives2(arr);

    return 0;
}