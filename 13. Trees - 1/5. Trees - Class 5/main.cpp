#include<iostream>
#include<queue>
#include<map>
#include<unordered_map>
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

void buildTree(Node* &root){
    int data;
    cout << "enter the data:\n";
    cin>>data;

    if(data == -1)
        return;
    
    root = new Node(data);

    cout << "enter the data for the left part of " << data << '\n';
    buildTree(root->left);
    cout << "enter the data for the right part of " << data << '\n';
    buildTree(root->right);

}

void topView(Node* root){
    if(root==NULL)
        return;
    
    queue<pair<Node*,int>>q;
    map<int,int>mapping;

    q.push({root,0});

    while(!q.empty()){
        Node* temp = q.front().first;
        int horizontalDistance = q.front().second;
        q.pop();

        if(mapping.find(horizontalDistance) == mapping.end())
            mapping[horizontalDistance] = temp->data;
        
        if(temp->left)
            q.push({temp->left, horizontalDistance-1});

        if(temp->right)
            q.push({temp->right, horizontalDistance+1});
    }

    for(auto it:mapping){
        cout << it.first << "=>" << it.second << "  ";
    }
    cout << "\n\n";
}

void bottomView(Node* root){
    if(root==NULL)
        return;
    
    queue<pair<Node*,int>>q;
    q.push({root, 0});
    map<int,int>mapping;

    while(!q.empty()){
        Node*temp = q.front().first;
        int hd = q.front().second;

        q.pop();

        mapping[hd] = temp->data;

        if(temp->left)
            q.push(make_pair(temp->left, hd-1));

        if(temp->right)
            q.push({temp->right, hd+1});

        // to show 20 instead of 50, push right before left

    }

    for(auto it : mapping)
        cout << it.first << "->" << it.second << "  ";
    cout << "\n\n";
}

void leftView(Node* root){
    if(root==NULL)
        return;
    
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        cout << q.front()->data << ' ';

        while(q.front()!=NULL){
            Node* temp = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
        q.pop();

        if(!q.empty())
            q.push(NULL);
    }
    cout << '\n';
}

void leftView2(Node* root, int currLevel, unordered_map<int,int> &mapping){
    if(root==NULL)
        return;
    
    if(mapping.find(currLevel) == mapping.end()){
        mapping[currLevel] = root->data;
        cout << root->data << ' ';
    }
    
    leftView2(root->left, currLevel+1, mapping);
    leftView2(root->right, currLevel+1, mapping);
}

void rightView2(Node* root, int currLevel, unordered_map<int,int> &mapping){
    if(root==NULL)
        return;
    
    if(mapping.find(currLevel) == mapping.end()){
        cout << root->data << ' ';
        mapping[currLevel] = root->data;
    }

    rightView2(root->right, currLevel+1, mapping);
    rightView2(root->left, currLevel+1, mapping);
}

void rightView3(Node* root, int currLevel, map<int,int> &mapping){
    if(root==NULL)
        return;
    
    mapping[currLevel] = root->data;

    rightView3(root->left, currLevel+1, mapping);
    rightView3(root->right, currLevel+1, mapping);
}

void rightView4(Node* root, int currLevel, vector<int> &ans){
    if(root==NULL)
        return;
    
    if(ans.size()==currLevel)
        ans.push_back(root->data);

    rightView4(root->right, currLevel+1, ans);
    rightView4(root->left, currLevel+1, ans);
}

int main(){

    Node* root = NULL;
    buildTree(root);

    topView(root);

    bottomView(root);

    leftView(root);

    int currLevel = 0;
    unordered_map<int,int>leftMapping;
    leftView2(root, currLevel, leftMapping);
    cout << "\n\n";

    currLevel = 0;
    unordered_map<int,int>rightMapping2;
    rightView2(root, currLevel, rightMapping2);
    cout << '\n';

    currLevel = 0;
    map<int,int>rightMapping3;
    rightView3(root, currLevel, rightMapping3);
    for(auto it : rightMapping3)
        cout << it.second << ' ';
    cout << '\n';

    currLevel = 0;
    vector<int>ans;
    rightView4(root, currLevel, ans);
    for(auto element : ans)
        cout << element << ' ';
    cout << "\n\n";

    return 0;
}

/*INPUT
10 60 80 -1 -1 20 70 -1 -1 40 -1 -1 30 50 -1 -1 -1

//                   10
//          60               30
//      80      20       50
//            70  40

// same as above
//                   10
//             60          30
//       80         20,50
//             70          40

*/