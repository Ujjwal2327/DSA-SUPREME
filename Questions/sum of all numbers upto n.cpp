// sum of all numbers from 1 to n

#include<iostream>
using namespace std;

int getSum(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    return sum;
}

int main(){

    int n;
    cin >> n;
    int ans = getSum(n);
    cout << ans;

    return 0;
}

/*INPUTS
10
*/