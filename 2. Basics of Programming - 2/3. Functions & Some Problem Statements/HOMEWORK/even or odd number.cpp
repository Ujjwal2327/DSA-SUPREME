// find a given number is even or odd

// https://www.geeksforgeeks.org/check-whether-given-number-even-odd/

#include<iostream>
using namespace std;

bool isEven(int n){
    if(n%2==0)
        return true;
    else
        return false;
}

bool isEven2(int n){
    if(n&1)
        return false;
    else
        return true;
}

bool isEven3(int n){
    if( n == (n>>1) << 1 )
        return true;
    else
        return false;
}

int main(){

    int n;
    cin>>n;
    bool ans = isEven(n);
    if(ans)
        cout << "even" <<'\n';
    else
        cout << "odd" <<'\n';
    
    bool ans2 = isEven2(n);
    if(ans2)
        cout << "even" <<'\n';
    else
        cout << "odd" <<'\n';

    bool ans3 = isEven3(n);
    if(ans3)
        cout << "even" <<'\n';
    else
        cout << "odd" <<'\n';

    return 0;
}