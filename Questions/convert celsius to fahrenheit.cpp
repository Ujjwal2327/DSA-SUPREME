#include<iostream>
using namespace std;

float toFahrenheit(float temp){
    float ans = (9.0/5)*temp + 32;
    return ans;
}

int main(){

    float temp;
    cin>>temp;
    cout << toFahrenheit(temp) << '\n';

    return 0;
}