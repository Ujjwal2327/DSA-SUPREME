// find all common elements in 3 sorted arrays

// https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

vector<int> findCommon(vector<int>arr1, vector<int>arr2, vector<int>arr3){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();
    int i=0, j=0, k=0;
    vector<int>ans;

    while(i<n1 && j<n2 && k<n3){
        int maxi = max(arr1[i], max(arr2[j], arr3[k]));
        while(i<n1 && arr1[i]<maxi){
            i++;
        }
        while(j<n2 &&arr2[j]<maxi){
            j++;
        }
        while(k<n3 && arr3[k]<maxi){
            k++;
        }
        if( (i<n1 && j<n2 && k<n3) && (arr1[i]==arr2[j]) && (arr1[i]==arr3[k])){
            if((ans.empty()) || (!ans.empty() && ans.back()!=arr1[i]))
                ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
    }

    return ans;
}

vector<int> findCommon2(vector<int>arr1, vector<int>arr2, vector<int>arr3){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();
    int i=0, j=0, k=0;
    vector<int>ans;

    while(i<n1 && j<n2 && k<n3){

        if(arr1[i] == arr2[j] && arr1[i] == arr3[k]){
            if((ans.empty()) || (!ans.empty() && ans.back()!=arr1[i]))
                ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr2[j] < arr3[k])
            j++;
        else        // if(arr3[k] < arr1[i])
            k++;
    }

    return ans;
}

// TC-O(nlogn) due to insertion in set
vector<int> findCommon3(vector<int>arr1, vector<int>arr2, vector<int>arr3){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();
    int i=0, j=0, k=0;
    vector<int>ans;
    set<int>st;

    while(i<n1 && j<n2 && k<n3){

        if(arr1[i] == arr2[j] && arr1[i] == arr3[k]){
            st.insert(arr1[i]);
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr2[j] < arr3[k])
            j++;
        else        // if(arr3[k] < arr1[i])
            k++;
    }

    for(auto i:st)
        ans.push_back(i);

    return ans;
}

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int j=0;
    for(int i=1; i<n; i++){
        if(nums[i]!=nums[j]){
            j++;
            nums[j] = nums[i];
        }
    }
    return j+1;
}

vector<int> findCommon4(vector<int>arr1, vector<int>arr2, vector<int>arr3){
    // remove duplicates from an array
    int n1 = removeDuplicates(arr1);
    int n2 = removeDuplicates(arr2);
    int n3 = removeDuplicates(arr3);
    int i=0, j=0, k=0;
    vector<int>ans;

    while(i<n1 && j<n2 && k<n3){

        if(arr1[i] == arr2[j] && arr1[i] == arr3[k]){
            ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr2[j] < arr3[k])
            j++;
        else        // if(arr3[k] < arr1[i])
            k++;
    }

    return ans;
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

    vector<int> ans = findCommon(arr1, arr2, arr3);
    printVector(ans);

    vector<int> ans2 = findCommon2(arr1, arr2, arr3);
    printVector(ans2);

    vector<int> ans3 = findCommon3(arr1, arr2, arr3);
    printVector(ans3);

    vector<int> ans4 = findCommon4(arr1, arr2, arr3);
    printVector(ans4);

    return 0;
}

/*INPUTS
8
1 5 10 20 20 20 40 80
6
6 7 20 20 80 100
11
3 4 15 20 20 20 20 30 70 80 120
*/