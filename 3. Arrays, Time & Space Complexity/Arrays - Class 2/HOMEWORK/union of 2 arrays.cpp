#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(auto val : arr){
        cout << val <<' ';
    }
    cout << '\n';
}

bool isAlreadyPresent(int element, vector<int>arr){
    for(int j=0; j<arr.size(); j++){
        if(arr[j]==element)
            return true;
    }
    return false;
}

void findUnion(vector<int>arr1, vector<int>arr2){
    vector<int>ans;
    for(auto element : arr1){
        bool flag = isAlreadyPresent(element, ans);
        if(flag == false){
            ans.push_back(element);
        }
    }
    for(auto element : arr2){
        bool flag = isAlreadyPresent(element, ans);
        if(flag == false){
            ans.push_back(element);
        }
    }
    printVector(ans);
}

int main(){

    int m,n;
    cin>>m;
    vector<int>arr1(m);
    for(int i=0; i<m; i++){
        cin >> arr1[i];
    }
    cin>>n;
    vector<int>arr2(n);
    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }
    findUnion(arr1, arr2);

    return 0;
}