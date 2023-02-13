// convert distance in km to miles

#include<iostream>
using namespace std;

float getMiles(int n){
    float ans = n/1.609;
    return ans;
}

int main(){

    int n;
    cin>>n;
    float ans = getMiles(n);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
12
*/