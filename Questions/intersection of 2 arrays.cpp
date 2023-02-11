#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>arr){
    for(auto value : arr){
        cout << value << ' ';
    }
}

void findIntersection(vector<int>arr1, vector<int>arr2){
    vector<int>ans;
    for(int i=0; i<arr1.size(); i++){
        int element = arr1[i];
        for(int j=0; j<arr2.size(); j++){
            if(element == arr2[j]){
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    printVector(ans);
}

int main(){

    int m;
    cin>>m;
    vector<int>arr1(m);
    for(int i=0; i<m; i++){
        cin >> arr1[i];
    }
    cout<<"hi\n";
    int n;
    cin>>n;
    vector<int>arr2(n);
    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }
    findIntersection(arr1, arr2);

    return 0;
}