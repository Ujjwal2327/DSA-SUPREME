#include<iostream>
#include<stack>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;

    public:

    Stack(int size){
        this->arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data){
        if(top<size-1){
            top++;
            arr[top] = data;
        }
        else{
            cout << "stack overflow\n";
        }
    }

    void pop(){
        if(top==-1)
            cout << "stack underflow\n";
        else{
            top--;
        }
    }

    int getTop(){
        if(top==-1){
            cout << "stack is empty\n";
            return -1;
        }
        else
            return arr[top];
    }

    bool empty(){
        if(top==-1)
            return 1;
        else
            return 0;
    }

    int getSize(){
        return top+1;
    }
};

class Stacks{
    int *arr;
    int size;
    int top1;
    int top2;

    public:

    Stacks(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2 == top1+1)
            cout << "stack1 overflow\n";
        else{
            top1++;
            arr[top1] = data;
        }
    }

    void pop1(){
        if(top1==-1)
            cout << "stack1 underflow\n";
        else
            top1--;
    }

    void push2(int data){
        if(top2 == top1+1)
            cout << "stack2 overflow\n";
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop2(){
        if(top2==size)
            cout << "stack2 underflow\n";
        else
            top2++;
    }
};

void reverseString(string &s){
    stack<char>st;
    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
    }
    
    s = "";

    while(!st.empty()){
        s.push_back(st.top());
        st.pop();
    }

    return;
}

int getMiddle(stack<int>& st, int& size){

    if(size==0){
        cout << "empty stack\n";
        return -1;
    }

    // if(st.size() == size/2+1)        // acc to ques for even number of elements
    if(st.size() == (size+1)/2)
        return st.top();
    
    int curr = st.top();
    st.pop();

    int ans = getMiddle(st, size);

    st.push(curr);

    return ans;
}


int main(){

    /*// operations in STL stackcreate, insert, remove, top element, size, empty or not and print whole stack
        stack<int>st;

        // insertion
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);

        // remove
        st.pop();

        // top element
        cout << st.top() << '\n';

        // size
        cout << st.size() << '\n';

        // empty or not
        cout << st.empty() << '\n';

        // print whole stack
        while(!st.empty()){
            cout << st.top() << ' ';
            st.pop();
        }
        cout << '\n';
    */
        
    /*// stack impementation using dynamic array
        Stack st(5);

        // insertion
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.push(50);
        st.push(60);

        // top element
        cout << st.getTop() << '\n';

        // remove
        st.pop();
        cout << st.getTop() << '\n';

        // // size
        cout << st.getSize() << '\n';

        // empty or not
        cout << st.empty() << '\n';

        // print whole stack
        while(!st.empty()){
            cout << st.getTop() << ' ';
            st.pop();
        }
        cout << '\n';

        st.pop();
        cout << st.getTop() << '\n';
    */
        
    /*// implement 2 stacks with push & pop functionality in an array
        Stacks st(10);
        st.push1(10);
        st.push1(20);
        st.push1(30);
        st.push1(40);

        st.push2(100);
        st.push2(200);
        st.push2(300);
        st.push2(400);

        st.push1(50);

        st.push2(500);
        st.push2(70);

        st.pop1();
        st.pop1();
        st.pop1();
        st.pop1();
        st.pop1();
        st.pop1();
        
        st.pop2();
        st.pop2();
        st.pop2();
        st.pop2();
        st.pop2();
        st.pop2();
    */

    /*// reverse a string using stack
        string s = "Ujjwal2327";
        cout << s << '\n';
        reverseString(s);
        cout << s << '\n';
    */

    /*
    */
    // find middle element in a stack
        stack<int>st;
        st.push(10);
        // st.push(20);
        // st.push(30);
        // st.push(40);
        // st.push(50);
        // st.push(60);
        int size = st.size();
        cout << getMiddle(st, size) << '\n';


    /*
    */
    // 

    /*
    */
    // 

    /*
    */
    // 
   
    /*
    */
    // 

    /*
    */
    // 

    /*
    */
    // 

    return 0;
}