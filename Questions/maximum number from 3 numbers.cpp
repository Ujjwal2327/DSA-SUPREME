#include<iostream>
using namespace std;

int findMax(int num1, int num2, int num3){
    if(num1 >= num2 && num1 >= num3)
        return num1;
    if(num2 >= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

int main(){
    
    int a, b, c;
    cin >> a >> b >> c;
    int maxNumber = findMax(a,b,c);
    cout << maxNumber << '\n';

    return 0;
}

/*INPUTS
3 5 4
*/