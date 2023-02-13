// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

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

// union for any values in arrays
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

    // find union for any values in arrays
        int m;
        cin>>m;
        vector<int>arr1(m);
        for(int i=0; i<m; i++){
            cin >> arr1[i];
        }

        int n;
        cin>>n;
        vector<int>arr2(n);
        for(int i=0; i<n; i++){
            cin >> arr2[i];
        }

        findUnion(arr1, arr2);
    
    return 0;
}

/*INPUTS
6
1 2 5 3 4 3
7
1 3 5 7 3 5 7
*/