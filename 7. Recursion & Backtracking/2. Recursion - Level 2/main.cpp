#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int climbStairs(int n){
    if(n==1 || n==2)    // for n=1, come from 0th stair     for n=2, come from either 1st or 0th stair
        return n;

    // come either from (n-1)th stair or from (n-2)th stair
    return climbStairs(n-1) + climbStairs(n-2);
}

// best method      easy to understand
void printArray(int arr[], int n, int i){
    if(i==n)
        return;
    
    cout << arr[i] << ' ';

    printArray(arr, n, i+1);
    // printArray2(++arr, n-1);     /// will also work as arr in this function is a copied pointer pointing to element of array
}

void printArray2(int arr[], int n){
    if(n==0)
        return;
    
    cout << arr[0] << ' ';

    printArray2(arr+1, n-1);
}

void printReverseArray(int arr[], int n, int i){
    if(i==n)
        return;
    
    printReverseArray(arr, n, i+1);

    cout << arr[i] << ' ';
}

// best method      easy to understand
void getMax(int arr[], int n, int i, int &maxi){
    // if no element, return INT_MIN
    if(i==n)
        return;

    // returns max of curr element and maxi
    maxi = max(maxi, arr[i]);
    // check for remaining array
    getMax(arr, n, i+1, maxi);
}

int getMax2(int arr[], int n, int i){
    // if no element, return INT_MIN
    if(i==n)
        return INT_MIN;

    // returns max of curr element and max element from forward array
    return max( arr[i], getMax2(arr, n, i+1) );
}

void getMin(int arr[], int n, int i, int &mini){
    if(i==n)
        return;

    mini = min(mini, arr[i]);
    getMin(arr, n, i+1, mini);
}

int searchInString(string s, int n, int i, char key){
// int searchInString(string &s, int &n, int i, char &key){     // will also work but have less TC and SC
    if(i==n)
    // if(s[i]=='\0')       // will also work
        return -1;

    if(s[i]==key)
        return i;
    else
        return searchInString(s, n, i+1, key);
}

void findAllOcc(string &s, int &n, int i, char &key, vector<int>&ans){
    if(i==n)
        return;

    if(s[i]==key)
        ans.push_back(i);
    
    findAllOcc(s, n, i+1, key, ans);
}

void printVector(vector<int>arr){
    for(auto i:arr)
        cout << i << ' ';
    cout << '\n';
}

void printDigits(int n){
    if(n==0)
        return;
    
    printDigits(n/10);

    int digit = abs(n%10);
    cout << digit << ' ';
}

int main(){

    /*// climb stairs
        int n;
        cin>>n;
        int ans = climbStairs(n);
        cout << ans << '\n';
    */

    /*// print array
        int arr[] = {1,2,5,3,4};
        int n = sizeof(arr)/sizeof(int);
        int i = 0;
        printArray(arr, n, i);
        cout << '\n';
        printArray2(arr, n);
    */
  
    /*// print reverse array
        int arr[] = {1,2,5,3,4};
        int n = sizeof(arr)/sizeof(int);
        int i = 0;
        printReverseArray(arr, n, i);
    */
  
    /*// maximum and minimum number from an array
        int arr[] = {1,2,5,3,4};
        int n = sizeof(arr)/sizeof(int);
        int i = 0;
        int ans = INT_MIN;
        getMax(arr, n, i, ans);
        cout << ans << '\n';

        int ans2 = getMax2(arr, n, i);
        cout << ans2 << '\n';

        int ans3 = INT_MAX;
        getMin(arr, n, i, ans3);
        cout << ans3 << '\n';
    */

    /*// search in string
        string str = "lovebabbar";
        int n = str.length();
        char key = 'a';
        int i=0;
        int ans = searchInString(str, n, i, key);
        cout << ans << '\n';
    */

    /*// find all occurence of key
        string str = "lovebabbar";
        int n = str.length();
        char key = 'b';
        int i=0;
        vector<int>ans;
        findAllOcc(str, n, i, key, ans);
        printVector(ans);
    */

    /*// number to digits
        int n;
        cin>>n;
        cout << "n is " << n << '\n';
        if(n==0)
            cout << 0 << '\n';
        else{
            if(n<0)
                cout << "- ";
            printDigits(n);
        }
    */

    /*// integer literal with a leading 0
        int num = 0100;     // interpretted as an octal number
        int num2 = num;
        cout << num << ' ' << num2 << '\n';

        cin>>num;
        num2 = num;
        cout << num << ' ' << num2 << '\n';     // no conversion as cin reads 0100 as 100
    */

    return 0;
}

/*INPUTS
// number to digits
123
-123
0100
*/