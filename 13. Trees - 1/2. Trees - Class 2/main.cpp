#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(){
    int data;
    cout << "enter the data\n";
    cin>> data;

    if(data==-1)
        return NULL;
    
    Node*root = new Node(data);

    cout << "enter the data for left part of " << data << '\n';
    root->left = buildTree();
    cout << "enter the data for right part of " << data << '\n';
    root->right = buildTree();

    return root;
}

int getHeight(Node* root){
    if(root==NULL)
        return 0;
    
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

// bruteforce
bool isBalanced(Node* root) {
    if(root==NULL)
        return true;
    
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);
    int diff = abs( getHeight(root->left) - getHeight(root->right) );

    if( diff<=1 && leftAns && rightAns )
        return true;
    else
        return false;
}

// optimal
pair< bool, int > isBalanced2(Node* root){
    if(root==NULL)
        return {true, 0};
    
    pair<bool,int> leftAns = isBalanced2(root->left);
    pair<bool,int> rightAns = isBalanced2(root->right);

    int height = max(leftAns.second, rightAns.second) + 1;

    bool flag = leftAns.first && rightAns.first && abs(leftAns.second - rightAns.second) <=1;

    return {flag, height};
}

// int convertIntoSumtree(Node* root){
//     if(root==NULL)
//         return 0;
//     int leftAns = convertIntoSUmtree(root->left);
//     int rightAns = convertIntoSUmtree(root->right);
//     return root->data += leftAns + rightAns;
// }

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==NULL)
        return NULL;
    
    if(root->data == p->data)
        return root;
    if(root->data == q->data)
        return root;
    
    Node* leftAns = lowestCommonAncestor(root->left, p, q);
    Node* rightAns = lowestCommonAncestor(root->right, p, q);

    if(leftAns && rightAns)
        return root;
    else if(leftAns)
        return leftAns;
    else if(rightAns)
        return rightAns;
    else
        return NULL;
}

bool kthAncestor(Node*root, int val, int &k, Node* &ans){
    if(root==NULL)
        return false;
    
    if(root->data == val)
        return true;
    
    bool leftAns = kthAncestor(root->left, val, k, ans);
    bool rightAns = kthAncestor(root->right, val, k, ans);

    if(leftAns || rightAns)
        k--;
    
    if(k==0){
        k--;    // to change k for ahead values
        ans = root;
    }
    
    return leftAns || rightAns;
}

int kthAncestor2(Node* root, int val, int k, vector<int> &storage){
    if(root==NULL)
        return -1;

    
    if(root->data == val){
        int n = storage.size();
        return k==0 ? val : (n-k>=0 ? storage[n-k] : -1) ;
    }

    storage.push_back(root->data);
    int leftAns = kthAncestor2(root->left, val, k, storage);
    int rightAns = kthAncestor2(root->right, val, k, storage);
    storage.pop_back();

    if(leftAns!=-1)
        return leftAns;
    else if(rightAns!=-1)
        return rightAns;
    
    return -1;
}

void pathSum(Node* root, int &targetSum, vector<vector<int>>&ans, vector<int>&curr, int &currSum){
    if(root==NULL){
        return;
    }

    curr.push_back(root->data);
    currSum += root->data;

    if(root->left==NULL && root->right==NULL){
        if(currSum == targetSum)
            ans.push_back(curr);
        currSum -= root->data;
        curr.pop_back();
        return;
    }

    pathSum(root->left, targetSum, ans, curr, currSum);
    pathSum(root->right, targetSum, ans, curr, currSum);

    currSum -= root->data;
    curr.pop_back();
}

int main(){

    Node* root = NULL;
    root = buildTree();


    cout << isBalanced(root) << '\n';

    cout << isBalanced2(root).first << "\n\n";


    Node*p = new Node(70);
    Node*q = new Node(80);
    cout << lowestCommonAncestor(root, p, q)->data << "\n\n";


    Node* ancestor = NULL;
    int val = 70;
    int k = 2;
    kthAncestor(root, val, k, ancestor);
    cout << ancestor->data << '\n';

    val = 70;
    k = 2;
    vector<int>storage;
    cout << kthAncestor2(root, val, k, storage) << "\n\n";


    vector<vector<int>>paths;
    vector<int>curr;
    int targetSum = 100;
    int currSum = 0;
    pathSum(root, targetSum, paths, curr, currSum);

    return 0;
}

/*INPUT
10 60 80 -1 -1 20 70 -1 -1 40 -1 -1 30 50 -1 -1 -1

//                   10
//          60               30
//      80      20       50
//            70  40

*/