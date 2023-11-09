#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// TC-O(n)    SC-O(n)
vector<int> nextSmallerElement(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,0);
    stack<int>st;
    st.push(-1);

    for(int i=n-1; i>=0; i--){
        while(arr[i]<=st.top())
            st.pop();
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

// TC-O(n)    SC-O(1)
void printVector(vector<int>& arr){
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

// TC-O(n)    SC-O(n)
vector<int> prevSmallerElement(vector<int>& arr){
    int n = arr.size();
    stack<int>st;
    st.push(-1);
    vector<int>ans(n,0);

    for(int i=0; i<n; i++){
        int curr = arr[i];

        while(st.top()>=curr)
            st.pop();
        
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main(){

    /*// 155. min stack leetcode question
            // https://leetcode.com/problems/min-stack/submissions/943723893/
    */

    /*// Longest Valid Parentheses
        // https://leetcode.com/problems/longest-valid-parentheses/submissions/944764901/
    */

    /*// store next (right nearest) smaller element from the right subarray for each element
        vector<int>arr = {2,1,4,3};
        vector<int>ans = nextSmallerElement(arr);

        printVector(ans);
    */

    /*// store prev (left nearest) smaller element from the right subarray for each element
        vector<int>arr = {2,1,4,3};
        vector<int>ans = prevSmallerElement(arr);

        printVector(ans);
    */

    /*// Largest Rectangle in Histogram
        // https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/944815655/
    */

    return 0;
}