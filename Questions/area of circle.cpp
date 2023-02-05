// find area of circle with given radius

#include<iostream>
using namespace std;

float printArea(int radius){
    float area = 3.14*radius*radius;
    return area;
}

int main(){

    int r;
    cin >> r;
    float ans = printArea(r);
    cout << ans << '\n';

    return 0;
}