// https://leetcode.com/problems/find-the-duplicate-number/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int findDuplicate(vector<int>arr){
    int n = arr.size();
    vector<int>cnts(n);

    for(int i=0; i<n; i++){
        int element = arr[i];
        cnts[element]++;
        if(cnts[element]>1)
            return element;
    }
}

// sort method

// negative marking method
int findDuplicate2(vector<int>arr){
    int n = arr.size();

    for(int i=0; i<n; i++){
        int index = abs(arr[i]);
        if(arr[index]<0)     // index already visited
            return index;
        else{
            arr[index]*=-1;      // mark index visited
        }
    }

    return -1;
}

// positioning method
int findDuplicate3(vector<int>arr){
    int n = arr.size();

    for(int i=0; i<n; i++){     // at max loop can run n times (only when everytime arr[0] is distinct)
        if(arr[0] != arr[arr[0]])
            swap(arr[0] , arr[arr[0]]);     // send all elements to their matching indexes   ex - if arr[0]==2, then send 2 at 2nd index
        else
            return arr[0];
    }

    return -1;
}

int findDuplicate3(vector<int>arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;

    while(s<e){
        int mid = s + (e-s)/2;
        int cnt = 0;

        for(auto i:arr){
            if(i<=mid)
                cnt++;
        }

        if(cnt<=mid){       // duplicate element is in right
            s = mid + 1;
        }
        else{       // duplicate element is smaller than or equal to mid
            e = mid;
        }
    }

    return e;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = findDuplicate(arr);
    cout << ans << '\n';

    int ans2 = findDuplicate2(arr);
    cout << ans2 << '\n';

    int ans3 = findDuplicate3(arr);
    cout << ans3 << '\n';

    return 0;
}

/*INPUTS
5
4 3 1 2 2
*/