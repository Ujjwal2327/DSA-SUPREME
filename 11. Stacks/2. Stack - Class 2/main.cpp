#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& st, int target){
    if(st.empty()){
        st.push(target);
        return;
    }

    int curr = st.top();
    st.pop();

    insertAtBottom(st, target);

    st.push(curr);
}

void insertTopAtBottom(stack<int>&st){
    if(st.empty()){
        cout << "empty stack\n";
        return;
    }

    int top = st.top();
    st.pop();

    insertAtBottom(st, top);        
}

void print(stack<int>&st){
    stack<int>temp = st;
    while(!temp.empty()){
        cout << temp.top() << ' ';
        temp.pop();
    }
    cout << '\n';
}

void reverse(stack<int>& st){
    if(st.empty())
        return;

    int curr = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st, curr);
}

bool isOpenParenthesis(char ch){
    if(ch=='(' || ch=='{' || ch=='[')
        return true;
    return false;
}

bool isPair(char a, char b){
    if( (a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}') )
        return true;
    return false;
}

bool validParenthesis(string s){
    stack<char>st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(isOpenParenthesis(ch)){
            st.push(ch);
        }
        else{
            if(!st.empty() && isPair(st.top(), ch)){
                st.pop();
            }
            else
                return false;
        }
    }

    if(s.empty())
        return true;
    else
        return false;
}

void insertAtSortedStack(stack<int>&st, int target){
    if(st.empty() || st.top()>=target){
        st.push(target);
        return;
    }

    int curr = st.top();
    st.pop();

    insertAtSortedStack(st,target);
    st.push(curr);
}

void sort(stack<int>& st){
    if(st.empty())
        return;
    
    int curr = st.top();
    st.pop();

    sort(st);

    insertAtSortedStack(st,curr);
}

bool isCloseParenthesis(char ch){
    if(ch==')' || ch=='}' || ch==']')
        return true;
    return false;
}

// consider anything as non empty in between
bool isRedundantBrackets(string &s){
    stack<char>st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(!isCloseParenthesis(ch)){
            st.push(ch);
        }
        else{
            if(isOpenParenthesis(st.top())){
                return true;
            }
            else{
                while(!isOpenParenthesis(st.top())){
                    st.pop();
                }
                st.pop();
            }
        }
    }

    return false;
}

// consider only operator as non empty in between
bool isRedundantBrackets2(string &s){
    stack<char>st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if( ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' ){
            st.push(ch);
        }
        else if( ch==')' ) {
            if(isOpenParenthesis(st.top())){
                return true;
            }
            else{
                while(!isOpenParenthesis(st.top())){
                    st.pop();
                }
                st.pop();
            }
        }
    }

    return false;;
}

int main(){

    /*// insert at bottom
        stack<int>st;
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.push(50);
        print(st);
        insertTopAtBottom(st);
        print(st);
    */

    /*// reverse a stack
        stack<int>st;
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.push(50);
        print(st);
        reverse(st);
        print(st);
    */

    /*// valid parenthesis
        string s="{([[]]{}){([])}}([])";
        cout << validParenthesis(s) << '\n';
    */

    /*// sort a stack
        stack<int>st;
        st.push(10);
        st.push(30);
        st.push(20);
        st.push(40);
        st.push(80);
        st.push(70);
        st.push(40);

        print(st);
        sort(st);
        print(st);
    */

    /*// redundant brackets present or not
        string s = "((a+b)+(c))";
        cout << isRedundantBrackets(s) << '\n';
        cout << isRedundantBrackets2(s) << '\n';
    */
    
    return 0;
}