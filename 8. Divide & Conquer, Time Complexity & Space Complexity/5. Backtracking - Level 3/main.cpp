#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<string>&arr){
    for(auto i:arr)
        cout << i << ' ';
    cout << '\n';
}

void generateParenthesis(int n, int openP, int closeP, string &output, vector<string>& ans){
    if(closeP > openP)
        return;
    if(openP>n || closeP>n)
        return;
    if(openP==n && closeP==n){
        ans.push_back(output);
        return;
    }

    output.push_back('(');
    generateParenthesis(n, openP+1, closeP, output, ans);
    output.pop_back();

    output.push_back(')');
    generateParenthesis(n, openP, closeP+1, output, ans);
    output.pop_back();

}

void letterCombinations(string &digits, string arr[], int index, vector<string>& ans, string &output){
    if(digits.length()==0)
        return;
    
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    
    int digit = digits[index]-'0';

    string str = arr[digit];

    for(int i=0; i<str.length(); i++){
        output.push_back(str[i]);
        letterCombinations(digits, arr, index+1, ans, output);
        output.pop_back();
    }

}

int main(){

    /*// generate parenthesis
        int n = 3;
        string output;
        vector<string>ans;
        generateParenthesis(n, 0, 0, output, ans);
        printVector(ans);
    */

    /*// Letter Combinations of a Phone Number
        string digits = "23";
        string arr[] = {"", "", "abc", "def", "ghi", "jkl", "mon", "pqrs", "tuv", "wxyz"};
        int index=0;
        vector<string>ans;
        string output;

        letterCombinations(digits, arr, index, ans, output);
        printVector(ans); 
    */

    return 0;
}