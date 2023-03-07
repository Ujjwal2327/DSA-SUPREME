#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

bool charCmp(char first, char second){
    return first < second;      // first will come first if first < second      first parameter in comparater function will act as first
}

bool charCmp2(char first, char second){
    return first > second;      // first will come first if first > second      first parameter in comparater function will act as first
}       // true means return first

void printVector(vector<int>arr){
    for(auto i:arr)
        cout<<i<<' ';
    cout<<'\n';
}

bool intCmp(int first, int second){
    // cout<<first<<' '<<second<<'\n';
    return first < second; 
}

bool intCmp2(int first, int second){
    return first > second;
}

void printStringVector(vector<string>arr){
    for(auto i:arr)
        cout<<i<<' ';
    cout<<'\n';
}

int stringValue(string s){
    int ans = 0;
    for(auto i:s)
        ans += i;
    return ans;
}

// sort with respect to sum of ascii values of chars of string
bool stringCmp(string first, string second){
    return stringValue(first) < stringValue(second);
}

void printStringVectorValue(vector<string>arr){
    for(auto i:arr){
        cout<<stringValue(i)<<' ';
    }
    cout<<'\n';
}

bool stringCmp2(string first, string second){
    return first > second;
}

int main(){

    /*// custom comparater in sort function in string
        string s = "babbar";
        sort(s.begin(), s.end());
        cout<<s<<'\n';

        s = "babbar";
        sort(s.begin(), s.end(), greater<char>());
        cout<<s<<'\n';

        s = "babbar";
        sort(s.begin(), s.end(), charCmp);
        cout<<s<<'\n';

        s = "babbar";
        sort(s.begin(), s.end(), charCmp2);
        cout<<s<<'\n';
        cout<<'\n';
    */

    /*// custom comparater in sort function in vector
        vector<int>arr{5,3,1,2,4};
        sort(arr.begin(), arr.end());
        printVector(arr);

        arr = {5,3,1,2,4};
        sort(arr.begin(), arr.end(), greater<int>());
        printVector(arr);

        arr = {5,3,1,2,4};
        sort(arr.begin(), arr.end(), intCmp);
        printVector(arr);

        arr = {5,3,1,2,4};
        sort(arr.begin(), arr.end(), intCmp2);
        printVector(arr);
    */

    /*// custom comparater in sort function in vector of strings
        vector<string>arr{"love", "babbar", "rahul", "sandeep"};
        sort(arr.begin(), arr.end());
        printStringVector(arr);

        arr = {"love", "babbar", "rahul", "sandeep"};
        sort(arr.begin(), arr.end(), greater<string>());
        printStringVector(arr);

        arr = {"love", "babbar", "rahul", "sandeep"};
        sort(arr.begin(), arr.end(), stringCmp);
        printStringVector(arr);
        printStringVectorValue(arr);

        arr = {"love", "babbar", "rahul", "sandeep"};
        sort(arr.begin(), arr.end(), stringCmp2);
        printStringVector(arr);
    */

    /*// hash map
        map<int, char>m;
        m[0] = 'a';
        m[1] = 'b';
        m[25] = 'z';
        cout<<m[0]<<'\n';
        cout<<m[1]<<'\n';
        cout<<m[25]<<'\n';
        cout<<m[20]<<"->"<<(int)m[20]<<'\n';
    */

    return 0;
}