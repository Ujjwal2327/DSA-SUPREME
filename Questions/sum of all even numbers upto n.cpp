// sum of all even numbers from 1 to n

#include<iostream>
using namespace std;

int getEvenSum(int n){
    int sum = 0;
    for(int i=2; i<=n; i+=2){
        sum += i;
    }
    return sum;
}

int main(){
    
    int n;
    cin >> n;
    int ans = getEvenSum(n);
    cout << ans;

    return 0;
}

/*INPUTS
10
*/