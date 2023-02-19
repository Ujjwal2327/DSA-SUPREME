// https://www.geeksforgeeks.org/divide-two-number-using-binary-search-without-using-any-and-operator/

#include<iostream>
using namespace std;

int divideAByB(int a, int b){
    int s = 0;
    int e = a;
    int mid = s + (e-s)/2;
    int ans = 0;

    while(s<=e){
        if(b*mid > a)
            e = mid - 1;
        else{
            ans = mid;      // store in ans
            s = mid + 1;    // search in right for possible bigger ans
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){

    int a,b;
    cin>>a>>b;
    int ans = divideAByB(a,b);
    cout<<ans<<'\n';

    return 0;
}

/*INPUTS
15 3
*/