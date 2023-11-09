#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// TC-O(n)    SC-O(1)
void print(queue<int>q){
    while(!q.empty()){
        cout << q.front()<<' ';
        q.pop();
    }
    cout << '\n';
}

// TC-O(n)    SC-O(n)
void reverse(queue<int>& q){
    stack<int>st;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

// TC-O(n)    SC-O(n)
void reverse2(queue<int>&q){
    if(q.empty())
        return;
    
    int curr = q.front();
    q.pop();

    reverse2(q);

    q.push(curr);
}

// TC-O(n)    SC-O(n)
void reverseFirstK(queue<int>&q, int k){
    int n = q.size();
    k = min(k,n);
    // k = min(k,q.size());    // gives ERROR

    stack<int>st;

    int cnt = 0;
    while(cnt<k){
        st.push(q.front());
        q.pop();
        cnt++;
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    while(cnt<n){
        q.push(q.front());
        q.pop();
        cnt++;
    }

}

// TC-O(n)    SC-O(n)
void interleave(queue<int>&q){
    int n = q.size();

    queue<int>temp1;
    queue<int>temp2;

    for(int i=0; i<n/2; i++){
        temp1.push(q.front());
        q.pop();
    }

    for(int i=n/2; i<n; i++){
        temp2.push(q.front());
        q.pop();
    }

    while(!temp1.empty() || !temp2.empty()){
        if(!temp1.empty()){
            q.push(temp1.front());
            temp1.pop();
        }
        
        if(!temp2.empty()){
            q.push(temp2.front());
            temp2.pop();
        }
    }
}

// TC-O(n)    SC-O(n)
void interleave2(queue<int>&q){
    int n = q.size();

    queue<int>temp1;

    for(int i=0; i<n/2; i++){
        temp1.push(q.front());
        q.pop();
    }

    while(!temp1.empty()){
        q.push(temp1.front());
        temp1.pop();
    
        q.push(q.front());
        q.pop();
    }

    if(n&1){
        q.push(q.front());
        q.pop();
    }
}

// TC-O(n)    SC-O(1)
void reverseVector(vector<int>& arr){
    int s = 0, e = arr.size()-1;
    while(s<e)
        swap(arr[s++], arr[e--]);
}

// TC-O(n)    SC-O(1)
void printVector(vector<int>&arr){
    for(int element : arr)
        cout << element << ' ';
    cout << '\n';
}

// TC-O(n)    SC-O(1)
vector<int> firstNegatives(queue<int>q, int k){
    int n = q.size();
    k = min(k,n);

    vector<int>ans;

    reverse(q);

    int latestNegative = 0;
    int latestNegRange  = 0;

    int cnt=0;
    for(; cnt<k; cnt++){
        int curr = q.front();
        q.pop();
        if(curr<0){
            latestNegative = curr;
            latestNegRange = cnt + k - 1;
        }
    }
    ans.push_back(latestNegative);

    while(cnt<n){
        int curr = q.front();
        q.pop();

        if(curr<0){
            latestNegative = curr;
            latestNegRange = cnt + k - 1;
            ans.push_back(curr);
        }
        else{
            if(latestNegRange >= cnt)
                ans.push_back(latestNegative);
            else
                ans.push_back(0);
        }
        cnt++;
    }

    reverseVector(ans);

    return ans;
}

// TC-O(n)    SC-O(k)
vector<int> firstNegatives2(vector<int>&arr, int k){
    queue<int>q;
    int n = arr.size();
    k = min(k,n);
    vector<int>ans;

    for(int i=0; i<k; i++){
        if(arr[i]<0)
            q.push(i);
    }

    // store ans for 1st ans
    if(q.empty())
        ans.push_back(0);
    else
        ans.push_back(arr[q.front()]);
    
    // solve all other windows
    for(int i=k; i<n; i++){
        if(!q.empty() && i-k==q.front())
        // while(!q.empty() && i-k>=q.front())      // both will work
            q.pop();
        
        if(arr[i]<0)
            q.push(i);
        
        if(q.empty())
            ans.push_back(0);
        else
            ans.push_back(arr[q.front()]);
    }
    return ans;
}

int main(){

    /*// reverse a queue
        queue<int>q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);

        print(q);
        reverse(q);
        print(q);
        reverse2(q);
        print(q);
    */

    /*// reverse first k elements of queue
        queue<int>q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);
        int k = 3;

        print(q);
        reverseFirstK(q, k);
        print(q);
    */

    /*// interleave first and second half of queue
        queue<int>q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);
        q.push(60);
        q.push(70);
        q.push(80);
        q.push(90);

        print(q);
        interleave(q);
        print(q);
        interleave(q);
        print(q);
    */

    /*// find first negative integer in every window of size k, if not found => 0  
        // if elements are given in queue
        queue<int>q;
        q.push(12);
        q.push(-1);
        q.push(-7);
        q.push(8);
        q.push(-15);
        q.push(30);
        q.push(16);
        q.push(28);
        int k = 3;

        vector<int>ans = firstNegatives(q,k);
        printVector(ans);


        // if elements are given in vector      firstNegatives approacjh will also work in this
        vector<int>arr = {12,-1,-7,8,-15,30,16,28};
        k = 3;
        vector<int>ans2 = firstNegatives2(arr,k);
        printVector(ans2);
    */

    /*
    */
    // 

    /*
    */
    // 

    return 0;
}