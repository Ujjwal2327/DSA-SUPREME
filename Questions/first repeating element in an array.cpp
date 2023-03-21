// https://www.geeksforgeeks.org/find-first-repeating-element-array-integers/

#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

// void printVector(vector<int>arr){
//     for(int i=0; i<arr.size(); i++){
//         cout << arr[i] << ' ';
//     }
//     cout << '\n';
// }

int firstRepeatingElement(vector<int>arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j])
                return i+1;     // index    in 1 based indexing
        }
    }

    return -1;
}

int firstRepeatingElement2(vector<int>arr){
    int n = arr.size();

    map<int,int>hash;

    for(int i=0; i<n; i++)
        hash[arr[i]]++;

    for(int i=0; i<n; i++){
        if(hash[arr[i]]>1)
            return i+1;
    }

    return -1;
}

int firstRepeatingElement3(vector<int>arr){
    int n = arr.size();

    int maxi = INT_MIN;
    for(int i=0; i<n; i++)
        maxi = max(maxi, arr[i]);
    
    vector<int>cnt(maxi,0);

    for(int i=0; i<n; i++){
        cnt[arr[i]-1]++;
    }

    for(int i=0; i<n; i++){
        if(cnt[arr[i]-1] > 1)
            return i+1;
    }

    return -1;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = firstRepeatingElement(arr);
    cout << ans << '\n';

    int ans2 = firstRepeatingElement2(arr);
    cout << ans2 << '\n';

    int ans3 = firstRepeatingElement3(arr);
    cout << ans3 << '\n';

    return 0;
}

/*INPUTS
9
6 10 5 4 9 120 4 6 10
*/