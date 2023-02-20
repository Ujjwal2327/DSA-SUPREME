// https://www.geeksforgeeks.org/find-the-point-where-a-function-becomes-negative/

#include<iostream>
#include<vector>
using namespace std;

// TC-O(1)
int f(int n){
    return n*n - 10*n - 20;   // this is just an example
}

// TC-O(logn)
int binarySearch(int s, int e){
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(f(mid)<=0)
            s = mid + 1;
        else{
            ans = mid;
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}

// TC-O(logn)
// based on exponential search
int unboundedSearch(){
    int i=1;
    while(f(i)<=0){
        i = i<<1;
    }

    int s = i/2;
    int e = i;
    int ans = binarySearch(s, e);

    return ans;
}

int main(){

    int ans = unboundedSearch();
    cout << ans << '\n';

    return 0;
}