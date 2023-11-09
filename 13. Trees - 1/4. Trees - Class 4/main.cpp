#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

void levelOrderTraversal(Node* root){
    if(root==NULL)
        return;
    
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp==NULL){
            cout << '\n';
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout << temp->data << ' ';
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }        
    }
    cout << '\n';
}

// not optimal completely
Node* buildTreeFromInorderAndPreorder(vector<int> &inorder, vector<int> &preorder, int &size, int &preIndex, int inorderStart, int inorderEnd ){
    if(preIndex >= size || inorderStart > inorderEnd)
        return NULL;

    int  element = preorder[preIndex];
    Node*root = new Node(element);

    int inIndex = 0;
    for(int i=0; i<size; i++){
        if(inorder[i] == element){
            inIndex = i;
            break;
        }
    }

    preIndex++;

    root->left = buildTreeFromInorderAndPreorder(inorder, preorder, size, preIndex, inorderStart, inIndex-1);
    root->right = buildTreeFromInorderAndPreorder(inorder, preorder, size, preIndex, inIndex+1, inorderEnd);

    return root;
}

// optimal completely
Node* buildTreeFromInorderAndPreorder2(vector<int> &inorder, vector<int> &preorder, int &size, int &preIndex, int inorderStart, int inorderEnd, unordered_map<int,int>& inorderMapping){
    if(preIndex >= size || inorderStart > inorderEnd)
        return NULL;

    int  element = preorder[preIndex];
    Node*root = new Node(element);

    int inIndex = inorderMapping[element];

    preIndex++;

    // left before right as in postorder => NLR => and we move from leftmost element towards right => N->L->R
    root->left = buildTreeFromInorderAndPreorder2(inorder, preorder, size, preIndex, inorderStart, inIndex-1, inorderMapping);
    root->right = buildTreeFromInorderAndPreorder2(inorder, preorder, size, preIndex, inIndex+1, inorderEnd, inorderMapping);

    return root;
}

Node* buildTreeFromInorderAndPostorder(vector<int> &inorder, vector<int> &postorder, int &size, int &postIndex, int inorderStart, int inorderEnd, unordered_map<int,int> &inorderMapping){
    if(postIndex<0 || inorderStart>inorderEnd)
        return NULL;
    
    int element = postorder[postIndex];
    int inIndex = inorderMapping[element];

    Node* root = new Node(element);
    postIndex--;
    
    // ṛight before left as in postorder => LRN => and we move from rightmost element towards left => N->R->L
    root->right = buildTreeFromInorderAndPostorder(inorder, postorder, size, postIndex, inIndex+1, inorderEnd, inorderMapping);
    root->left = buildTreeFromInorderAndPostorder(inorder, postorder, size, postIndex, inorderStart, inIndex-1, inorderMapping);
    
    return root;
}

int main(){

    Node* root = NULL;
    vector<int> inorder = {80,60,70,20,40,10,50,30};
    vector<int> preorder = {10,60,80,20,70,40,30,50};
    int size = 8, preIndex = 0, inorderSTart = 0, inorderEnd = size-1;
    root = buildTreeFromInorderAndPreorder(inorder, preorder, size, preIndex, inorderSTart, inorderEnd);
    levelOrderTraversal(root);


    unordered_map<int,int>inorderMapping;
    for(int i=0; i<size; i++)
        inorderMapping[inorder[i]] = i;
    
    size = 8, preIndex = 0, inorderSTart = 0, inorderEnd = size-1;
    root = buildTreeFromInorderAndPreorder2(inorder, preorder, size, preIndex, inorderSTart, inorderEnd, inorderMapping);
    levelOrderTraversal(root);



    root = NULL;
    inorder = {80,60,70,20,40,10,50,30};
    vector<int> postorder = {80,70,40,20,60,50,30,10};
    size = 8, inorderSTart = 0, inorderEnd = size-1;
    int postIndex = size-1;

    unordered_map<int,int>inorderMapping2;
    for(int i=0; i<size; i++)
        inorderMapping2[inorder[i]] = i;

    root = buildTreeFromInorderAndPostorder(inorder, postorder, size, postIndex, inorderSTart, inorderEnd, inorderMapping2);
    levelOrderTraversal(root);

    return 0;
}

/*INPUT
10 60 80 -1 -1 20 70 -1 -1 40 -1 -1 30 50 -1 -1 -1

//                   10
//          60               30
//      80      20       50
//            70  40

*/