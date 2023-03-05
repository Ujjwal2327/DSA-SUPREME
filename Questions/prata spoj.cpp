// https://www. spoj.com/problems/PRATA/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC-O(n)    SC-O(1)
int isPossibleSol(vector<int>arr, int reqPrata, int givenTime){
    int n = arr.size();
    int ans = 0;

    for(int i=0; i<n; i++){
        int rank = arr[i];
        int usedTime = 0;

        for(int cnt=1; usedTime + (cnt*rank) <= givenTime; cnt++){
            ans++;
            usedTime += cnt*rank;
        }
        if(ans>=reqPrata){
            return true;
        }
    }

    return false;
}

// TC-O(nlogn)    SC-O(1)
int prata(vector<int>arr, int reqPrata){
    int n = arr.size();
    int s = 0;
    int e = *max_element(arr.begin(), arr.end())*(reqPrata*(reqPrata+1))/2;    // if least efficient cook made all pratas
    // int e = 8*(reqPrata*(reqPrata+1))/2;    // this will also work   if r=8 cook made all pratas     doesnot matter it is in arr or not, but it cant be max than this
    int ans = -1;

    // sort(arr.begin(), arr.end());        // will work without this too

    while(s<=e){
        int mid = s + (e-s)/2;

        if(isPossibleSol(arr, reqPrata, mid)){
            ans = mid;
            e = mid - 1;
        }
        else
            s =  mid + 1;
    }

    return ans;
}

// TC-O(nlogn)    SC-O(1)
int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int reqPrata;
    cin>>reqPrata;

    int ans = prata(arr, reqPrata);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
4
1 2 3 4
10

1   
1
8
*/