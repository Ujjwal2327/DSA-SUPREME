#include<iostream>
#include<queue>
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
        cout << "hiiii\n";
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

    cout << "\n\n";
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

void preorder(Node* root){
    if(root==NULL)
        return;
    
    cout << root->data << ' ';

    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

// TC-O(height)    SC-O(height)
bool searchInBST(Node* root, int target){
    if(root == NULL)
        return false;
    
    if(root->data == target)
        return true;
    
    if(target > root->data)
        return searchInBST(root->right, target);
    else
        return searchInBST(root->left, target);
}

void getMinimum(Node* root, vector<int> &inorder){
    if(root==NULL)
        return;
    
    getMinimum(root->left, inorder);
    inorder.push_back(root->data);
    getMinimum(root->right, inorder);
}

void getMinimum2(Node* root, vector<int> &inorder){
    if(root==NULL)
        return;
    
    getMinimum2(root->left, inorder);
    inorder.push_back(root->data);
}

int getMinimum3(Node* root){
    if(root==NULL)
        return -1;
    
    if(root->left)
        return getMinimum3(root->left);
    else
        return root->data;
}

int getMinimum4(Node* root){
    if(root==NULL)
        return -1;

    Node* temp = root;

    while(temp!=NULL && temp->left!=NULL)
        temp = temp->left;

    return temp->data;
}

int getMaximum(Node* root){
    if(root==NULL)
        return -1;

    Node* temp = root;

    while(temp!=NULL && temp->right!=NULL)
        temp = temp->right;

    return temp->data;
}

Node* deleteInBST(Node* root, int target){
    if(root == NULL)
        return NULL;
    
    int currVal = root->data;
    if(target > currVal)
        root->right = deleteInBST(root->right, target);
    else if(target < currVal)
        root->left = deleteInBST(root->left, target);
    else{
        if(root->left!=NULL && root->right!=NULL){
            // ṃinimum value from right subtree
            int inorderSuccessor = getMinimum4(root->right);
            root->data = inorderSuccessor;
            root->right = deleteInBST(root->right, inorderSuccessor);
        }
        else if(root->left){
            Node* child = root->left;
            root->left = NULL;
            delete root;
            return child;
        }
        else if(root->right){
            Node* child = root->right;
            root->right = NULL;
            delete root;
            return child;
        }
        else{
            delete root;
            return NULL;
        }
    }
}

Node* deleteInBST2(Node* root, int target){
    if(root == NULL)
        return NULL;
    
    int currVal = root->data;
    if(target > currVal)
        root->right = deleteInBST2(root->right, target);
    else if(target < currVal)
        root->left = deleteInBST2(root->left, target);
    else{
        if(root->left!=NULL && root->right!=NULL){
            // ṃaximum value from left subtree
            int inorderPredecessor = getMaximum(root->left);
            root->data = inorderPredecessor;
            root->left = deleteInBST2(root->left, inorderPredecessor);
        }
        else if(root->left){
            Node* child = root->left;
            root->left = NULL;
            delete root;
            return child;
        }
        else if(root->right){
            Node* child = root->right;
            root->right = NULL;
            delete root;
            return child;
        }
        else{
            delete root;
            return NULL;
        }
    }
}


int main(){

    Node* root = NULL;
    takeInput(root);
    levelorderTraversal(root);

    preorder(root);
    cout << "\n\n";

    inorder(root);
    cout << "\n\n";

    postorder(root);
    cout << "\n\n";

    int target = 60;
    cout << searchInBST(root, target) << "\n\n";

    vector<int>arr;
    getMinimum(root, arr);
    cout << arr[0] << '\n';
    
    vector<int>arr2;
    getMinimum(root, arr2);
    cout << arr2[0] << '\n';

    cout << getMinimum3(root) << '\n';
    cout << getMinimum4(root) << "\n\n";

    cout << getMaximum(root) << "\n\n";

    target = 100;
    deleteInBST2(root, target);
    levelorderTraversal(root);



    return 0;
}

/*INPUT
100 150 50 125 75 60 30 80 -1

//                   100
//          50               150
//      30      75       125
//            60  80

*/