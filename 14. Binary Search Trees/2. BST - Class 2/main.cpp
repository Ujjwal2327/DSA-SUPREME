#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelorderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp){
            cout << temp->data << ' ';
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
        else{
            cout << '\n';
            if(!q.empty())
                q.push(NULL);
        }
    }

    cout << '\n';
}

// TC-O(height)    SC-O(height)
Node* insertIntoBST(Node* root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    int currVal = root->data;

    if(data >= currVal)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);
    
    return root;
}

// TC-O(nlogn)    worst TC-O(n^2)    SC-O(height)
void takeInput(Node* &root){
    cout << "enter data\n";
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root, data);
        cin>>data;
    }

}

void inorder(Node* root, vector<int> &arr){
    if(root==NULL)
        return;
    
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}


// .for non duplicate BST
bool isValidBST(Node*root){
    vector<int>arr;
    inorder(root, arr);

    // check inorder is sorted or not
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i]>=arr[i+1])
            return false;
    }
    return true;
}

bool isValidBST2(Node* root, int &curr){
    if(root==NULL)
        return true;
    
    bool leftAns = isValidBST2(root->left, curr);
    if(leftAns==false)
        return false;

    if(root->data < curr)
        return false;
    else
        curr = root->data;

    bool rightAns = isValidBST2(root->right, curr);
    if(rightAns==false)
        return false;

    return true;
}

bool isValidBST3(Node* root, int low, int high){
    if(root==NULL)
        return true;
    
    if(!(root->data > low && root->data < high))
        return false;
    
    bool leftAns = isValidBST3(root->left, low, root->data);
    if(leftAns==false)
        return false;    

    bool rightAns = isValidBST3(root->right, root->data, high);
    if(rightAns==false)
        return false;
    
    return true;
}

bool isValidBST4(Node* root, int low, int high){
    if(root==NULL)
        return true;
    
    if((root->data > low && root->data < high)){
        bool leftAns = isValidBST4(root->left, low, root->data);
        bool rightAns = isValidBST4(root->right, root->data, high);
        return leftAns && rightAns;
    }
    else
        return false;
}


// TC-O(logn)    worst TC-O(n)    SC-O(height)
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==NULL)
        return NULL;

    int currVal = root->data;
    
    if(p->data > currVal && q->data > currVal)
        return lowestCommonAncestor(root->right, p, q);
    else if(p->data < currVal && q->data < currVal)
        return lowestCommonAncestor(root->left, p, q);
    else
        return root;
}


void kthSmallest(Node* root, vector<int> &arr){
    if(root==NULL)
        return;
    
    kthSmallest(root->left, arr);
    arr.push_back(root->data);
    kthSmallest(root->right, arr);
}

void kthSmallest2(Node* root, vector<int> &arr, int &k){
    if(root==NULL)
        return;
    
    if(k>0)
        kthSmallest2(root->left, arr, k);

    if(k>0){
        arr.push_back(root->data);
        k--;
    }
    
    if(k>0)
        kthSmallest2(root->right, arr, k);
}

int kthSmallest3(Node* root, int &k){
    if(root==NULL)
        return -1;
    
    int leftAns = -1;
    int rightAns = -1;

    if(k>0)
        leftAns = kthSmallest3(root->left, k);

    k--;
    if(k==0)
        return root->data;
    
    if(k>0)
        rightAns = kthSmallest3(root->right, k);
    
    if(leftAns != -1)
        return leftAns;
    else if(rightAns != -1)
        return rightAns;
    else
        return -1;
}

void kthSmallest4(Node* root, int &ans, int &k){
    if(root==NULL)
        return;
    
    if(k>0)
        kthSmallest4(root->left, ans, k);

    k--;
    if(k==0)
        ans = root->data;
    
    if(k>0)
        kthSmallest4(root->right, ans, k);
}


// TC-O(n)    SC-O(height)
Node* buildBSTFromInorder(vector<int>& arr, int s, int e){
    if(s>e)
        return NULL;
    
    int mid = s + (e-s)/2;

    Node*root = new Node(arr[mid]);
    root->left = buildBSTFromInorder(arr, s, mid-1);
    root->right = buildBSTFromInorder(arr, mid+1, e);

    return root;
}


bool twoSum(Node* root, int k) {
    vector<int>arr;
    inorder(root, arr);

    int s=0, e=arr.size()-1;

    while(s<e){
        if(arr[s]+arr[e] == k)
            return true;
        else if(arr[s]+arr[e] < k)
            s++;
        else
            e--;
    }

    return false;
}

int main(){

    Node* root = NULL;
    takeInput(root);

    levelorderTraversal(root);


    cout << isValidBST(root) << '\n';
    int curr = -1;
    cout << isValidBST2(root, curr) << '\n';
    cout << isValidBST3(root, INT_MIN, INT_MAX) << '\n';
    cout << isValidBST4(root, INT_MIN, INT_MAX) << "\n\n";


    Node* p = new Node(50);
    Node* q = new Node(75);
    cout << lowestCommonAncestor(root, p, q)->data << "\n\n";


    int k = 4;
    vector<int>arr;
    kthSmallest(root, arr);
    cout << arr[k-1] << '\n';

    k=4;
    vector<int>arr2;
    kthSmallest2(root, arr2, k);
    cout << arr2.back() << '\n';

    k=4;
    cout <<  kthSmallest3(root, k) << '\n';

    k=4;
    int ans2 = -1;
    kthSmallest4(root, ans2, k);
    cout << ans2 << "\n\n";


    vector<int>arr3 = {10,20,30,40,50,60,70,80,90};
    Node* root2 = buildBSTFromInorder(arr3, 0, arr3.size()-1);
    levelorderTraversal(root2);

    k = 225;
    cout << twoSum(root, k) << "\n\n";

    return 0;
}

/*INPUT
100 150 50 125 75 60 30 80 -1

//                   100
//          50               150
//      30      75       125
//            60  80


10 20 30 40 50 60 70 80 90

//               50
//        20            70
//    10      30    60      80
//              40            90
//

*/