// https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void findCommon(vector<int>arr1, vector<int>arr2, vector<int>arr3){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();
    int i=0, j=0, k=0;
    while(i<n1 && j<n2 && k<n3){
        int maxi = max(arr1[i], max(arr2[j], arr3[k]));
        while(arr1[i]<maxi){
            i++;
        }
        while(arr2[j]<maxi){
            j++;
        }
        while(arr3[k]<maxi){
            k++;
        }
        if((arr1[i]==arr2[j]) && (arr1[i]==arr3[k])){
            cout << arr1[i] << ' ';
            i++;
            j++;
            k++;
        }
    }
}

int main(){

    int n1,n2,n3;
    cin>>n1;
    vector<int>arr1(n1);
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }
    cin>>n2;
    vector<int>arr2(n2);
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }
    cin>>n3;
    vector<int>arr3(n3);
    for(int i=0; i<n3; i++){
        cin>>arr3[i];
    }

    findCommon(arr1, arr2, arr3);

    return 0;
}

// 6
// 1 5 10 20 40 80
// 5
// 6 7 20 80 100
// 8
// 3 4 15 20 30 70 80 120