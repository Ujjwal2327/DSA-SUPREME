#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(auto val : arr){
        cout << val <<' ';
    }
    cout << '\n';
}

// arrays having no duplicate
void findUnion(vector<int>arr1, vector<int>arr2){
    vector<int>ans;
    for(int i=0; i<arr1.size(); i++){
        ans.push_back(arr1[i]);
    }
    for(int i=0; i<arr2.size(); i++){
        ans.push_back(arr2[i]);
    }
    printVector(ans);
}


bool isAlreadyPresent(int element, vector<int>arr){
    for(int j=0; j<arr.size(); j++){
        if(arr[j]==element)
            return true;
    }
    return false;
}

void findUnion2(vector<int>arr1, vector<int>arr2){
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

    /*// find union of 2 arrays having no duplicate
        int m;
        cin>>m;
        int n;
        cin>>n;
        vector<int>arr1(m);
        vector<int>arr2(n);
        for(int i=0; i<m; i++){
            cin>>arr1[i];
        }
        for(int i=0; i<n; i++){
            cin>>arr2[i];
        }
        findUnion(arr1, arr2);
    */

    // find union for any values in arrays
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
        findUnion2(arr1, arr2);
    

    return 0;
}