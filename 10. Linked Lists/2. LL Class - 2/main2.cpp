// its about singly /simple linked list
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(){
        this -> data = -1;
        this -> next = NULL;
    }

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~node(){
        cout << "node with data " << this->data << " is deleted\n";
    }
};

void print(node* &head){
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data << ' ';
        temp = temp -> next;
    }
    cout << "\n\n";
}

void insertAtHead(node* &head, node* &tail, int data){
    node* newNode = new node(data);

    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }

}

// TC-O(n)    SC-O(1)
void reverse(node* &head, node* &tail){
    if(head==NULL || head->next==NULL)
        return ;
    
    tail = head;

    node*left = NULL;
    node*curr = head;
    node*right = head->next;

    while(curr!=NULL){
        curr->next = left;
        left = curr;
        curr = right;
        if(curr!=NULL)
            right = curr->next;
    }
    head = left;
}

// TC-O(n)    SC-O(n)
void reverse2(node* &head, node* &tail, node* curr, node* left){
    if(curr==NULL){
        head=left;
        return;
    }

    tail = head;
    node*right = curr->next;        // not made right as parameter as i didnt handle length=0 wala case (in which there is no right) outside thefunction, 
    curr->next = left;
    left = curr;
    curr = right;
    reverse2(head, tail, curr, left);
}

// TC-O(n)    SC-O(n)
node* reverse3(node* &head, node* &tail, node* curr, node* left){
    if(curr==NULL){
        return left;
    }

    if(left==NULL)
        tail = curr;

    node*right = curr->next;
    curr->next = left;
    left = curr;
    curr = right;
    return reverse3(head, tail, curr, left);
}

int main(){

    /*// reversing a linked list
        node * head = NULL;
        node * tail = NULL;
        insertAtHead(head, tail, 20);
        insertAtHead(head, tail, 30);
        insertAtHead(head, tail, 40);
        insertAtHead(head, tail, 50);
        print(head);

        cout << "reversing a linked list\n";
        reverse(head, tail);
        print(head);

        reverse2(head, tail, head, NULL);
        print(head);

        head = reverse3(head, tail, head, NULL);
        print(head);
    */

    return 0;
}