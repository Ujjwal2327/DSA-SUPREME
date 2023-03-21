#include<iostream>
using namespace std;

void add2Numbers(string &s1, string &s2, int i, int j, int &carry, string &ans){
    if(i<0 && j<0 && carry==0)
        return;

    int digit1 = 0, digit2 = 0;

    if(i>0)
        digit1 = s1[i] - '0';
    
    if(j>0)
        digit2 = s2[j] - '0';

    // cout <<"digit1 " << digit1<<'\n';
    int sum = digit1 + digit2 + carry;

    int ansDigit = sum%10;
    carry = sum/10;

    // cout << digit1 << ' ' << digit2 << ' ' << ansDigit << ' ' << carry << '\n';
    add2Numbers(s1, s2, i-1, j-1, carry, ans);

    ans.push_back(ansDigit + '0');
    // cout << ansDigit << ' ';

}

int main(){

    string s1 = "1120";
    string s2 = "15";
    int i = s1.length()-1;
    int j = s2.length()-1;
    int carry = 0;

    string ans;

    add2Numbers(s1, s2, i, j, carry, ans);
    cout << ans << '\n';

    return 0;
}