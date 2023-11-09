#include<iostream>
#include<queue>
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

// preorder method
Node* buildTree(){
    int data;
    cout << "enter the data:\n";
    cin>>data;

    if(data==-1)
        return NULL;
    
    Node*root = new Node(data);

    cout << "enter the data for left part of " << data << '\n' ;
    root->left = buildTree();

    cout << "enter the data for right part of " << data << '\n' ;
    root->right = buildTree();

    return root;
}

void buildTree2(Node* &root){
    int data;
    cout << "enter the data:\n";
    cin>>data;

    if(data==-1)
        return;
    
    root = new Node(data);
    cout << "enter the data for left part of " << data << '\n' ;
    buildTree2(root->left);
    cout << "enter the data for right part of " << data << '\n' ;
    buildTree2(root->right);

}

void levelOrderTraversal(Node* &root){    
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr->data << ' ';

        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    cout << '\n';
        
}

void advanceLevelOrderTraversal(Node* &root){    
    if(root==NULL)      // yaha hi fasoge
        return;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr!=NULL){
            cout << curr->data << ' ';

            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        else{       // old level is completed
            cout << '\n';
            
            if(!q.empty())
                q.push(NULL);
        }
    }
}

void advanceLevelOrderTraversal2(Node* &root){ 
    if(root==NULL)      // yaha hi fasoge
        return;
    
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        
        while(q.front()!=NULL){
            Node* curr = q.front();
            cout << curr->data << ' ';

            q.pop();

            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }

        cout << '\n';
        q.pop();

        if(!q.empty())
            q.push(NULL);
    }
}

void inorderTraversal(Node* &root){
    if(root==NULL)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << ' ';
    inorderTraversal(root->right);
}

void preorderTraversal(Node* &root){
    if(root==NULL)
        return;
    
    cout << root->data << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* &root){
    if(root==NULL)
        return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << ' ';
}

int getHeight(Node* &root){
    if(root==NULL)
        return 0;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// brute force
int getDiameter(Node* root) {
    if(root==NULL)
        return 0;
    
    int leftAns = getDiameter(root->left);
    int rightAns = getDiameter(root->right);
    int currAns = getHeight(root->left) + getHeight(root->right);

    return max(currAns, max(leftAns, rightAns));
}

// optimal
int getDiameter2(Node* root, int &ans){
    if(root==NULL)
        return 0;
    
    int leftHeight = getDiameter2(root->left, ans);
    int rightHeight = getDiameter2(root->right, ans);
    int currHeight = max(leftHeight, rightHeight) + 1;

    ans = max(ans, leftHeight + rightHeight);

    return currHeight;
}





int getBreadth(Node* &root, int &leftVal, int &rightVal){
    if(root==NULL)
        return 0;
    
    int LLVal = leftVal+1;
    int LRVal = rightVal-1;
    int RLVal = leftVal-1;
    int RRVal = rightVal+1;
    int leftAns = getBreadth(root->left, LLVal, LRVal);
    int rightAns = getBreadth(root->left, RLVal, RRVal);

    return max(rightVal, max(LRVal,RRVal)) - min(leftVal, min(LLVal,RLVal));
}

int main(){

    // wrong way
    // Node*root = buildTree();

    // right way
    Node*root = NULL;
    root = buildTree();
    cout << '\n';

    levelOrderTraversal(root);
    cout << '\n';

    advanceLevelOrderTraversal(root);
    cout << '\n';

    advanceLevelOrderTraversal2(root);
    cout << '\n';

    inorderTraversal(root);
    cout << '\n';

    preorderTraversal(root);
    cout << '\n';

    postorderTraversal(root);
    cout << "\n\n";

    int height = getHeight(root);
    cout << height << "\n\n";

    int diameter = getDiameter(root);
    cout << diameter << '\n';

    int diameter2 = 0;
    getDiameter2(root, diameter2);
    cout << diameter2 << "\n\n";
    



    int leftVal =0, rightVal = 0;
    int breadth = getBreadth(root, leftVal, rightVal);
    cout << breadth << '\n';

    return 0;
}

/*INPUT
10 60 80 -1 -1 20 70 -1 -1 40 -1 -1 30 50 -1 -1 -1

//                   10
//          60               30
//      80      20       50
//            70  40

*/