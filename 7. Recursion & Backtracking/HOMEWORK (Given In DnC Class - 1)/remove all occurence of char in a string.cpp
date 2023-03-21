// https://www.geeksforgeeks.org/remove-all-occurrences-of-a-character-in-a-string-recursive-approach/

#include<iostream>
using namespace std;

void removeAllOcc(string &s, char &ch, int i, string &ans){
    if(i>=s.length())
        return;

    if(s[i]==ch)
        removeAllOcc(s, ch, i+1, ans);
    else{
        ans.push_back(s[i]);
        removeAllOcc(s, ch, i+1, ans);
    }

}

string removeAllOcc2(string &s, char &ch, int i){
    string ans;
    if(i>=s.length())
        return ans;

    if(s[i]==ch)
        ans = removeAllOcc2(s, ch, i+1);
    else{
        ans.push_back(s[i]);
        ans += removeAllOcc2(s, ch, i+1);
    }

    return ans;
}



int main(){

    string s = "geeksforgeeks";
    char ch = 'g';
    int i=0;
    string ans;
    removeAllOcc(s, ch, i, ans);
    cout << ans << '\n';

    string ans2 = removeAllOcc2(s, ch, i);
    cout << ans2 << '\n';

    return 0;
}