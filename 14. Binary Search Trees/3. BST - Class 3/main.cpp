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


void convertBSTToSortedDLL(Node*root, Node* &head){
    if(root==NULL)
        return;
    
    // convert right subtree to DLL
    convertBSTToSortedDLL(root->right, head);

    // head is updated (starting of DLL made from right subtree), points root->right to head
    root->right = head;

    // update head->left to connect root and head only if head!=NULL
    if(head != NULL)
        head->left = root;

    // update the head, now head will points to root
    head = root;
    
    // convert left subtree to DLL and also updates head in the process
    convertBSTToSortedDLL(root->left, head);
}

void printDLL(Node* head){
    Node* temp = head;

    while(head){
        cout << head->data << ' ';
        head = head->right;
    }
    cout << "\n\n";
}

void printReverseDLL(Node* tail){
    Node* temp = tail;

    while(tail){
        cout << tail->data << ' ';
        tail = tail->left;
    }
    cout << "\n\n";
}


Node* getDLLMid(Node*head, Node*tail){
    Node*slow = head;
    Node*fast = head;

    while(fast!=tail){
        fast = fast->right;
        if(fast!=tail){
            fast = fast->right;
            slow = slow->right;
        }
    }

    return slow;
}

Node* convertSortedDLLToBST(Node*head, Node*tail){
    cout << head->data << ' ' << tail->data << '\n';
    if(head==NULL || tail==NULL || head->data > tail->data){
        cout << "returning\n";
        return NULL;
    }
    
    Node* root = getDLLMid(head,tail);
    if(root==NULL)
        return NULL;
    cout << "head and tail are " << head->data << ' ' << tail->data << '\n';
    cout << "root is " << root->data << '\n';
    root->left = convertSortedDLLToBST(head, root->left);
    root->right = convertSortedDLLToBST(root->right, tail);

    return root;
}

Node* getDLLTail(Node* head){
    Node* temp = head;

    while(temp!=NULL && temp->right!=NULL)
        temp = temp->right;
    
    return temp;
}


Node* getDLLMid2(Node* head, int n){
    if(n==0)
        return NULL;
    Node* temp = head;

    int i=1;
    while(temp!=NULL && i != (n+1)/2)
        temp = temp->right;
    
    return temp;
}

Node* convertSortedDLLToBST2(Node*head, int n){
    cout << "head and size are " << head->data << ' ' << n << '\n';
    if(head==NULL || n==0){
        cout << "returning\n";
        return NULL;
    }
    
    Node* root = getDLLMid2(head, n);
    cout << "root is " << root->data << '\n';
    root->left = convertSortedDLLToBST2(head, n- n/2);
    root->right = convertSortedDLLToBST2(root->right, n/2);

    return root;
}

int main(){

    Node* root = NULL;
    takeInput(root);

    levelorderTraversal(root);

    Node* head = NULL;
    convertBSTToSortedDLL(root, head);
    printDLL(head);
    Node*tail = getDLLTail(head);
    printReverseDLL(tail);

    int n = 8;
    root = convertSortedDLLToBST2(head,n);
    levelorderTraversal(root);

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