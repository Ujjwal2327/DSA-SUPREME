#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(){
        this->data = -1;
        this->next = NULL;
    }

    node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~node(){
        cout << "node with data " << this->data << " is deleted\n";
        node*temp = this;
        while(temp->next!=NULL){
            node*nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

void insertAfterValue(node* &head, node* &tail, int value, int data){
    node*newNode = new node(data);

    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    node*temp = head;
    while(temp!=NULL && temp->data!=value){
        temp = temp->next;
    }

    if(temp==NULL || (temp->data==value && temp->next==NULL)){
        tail->next = newNode;
        tail = newNode;
    }
    else{
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void print(node* &head){
    if(head==NULL){
        cout << "empty linked list\n\n";
        return;
    }

    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n\n";
}

void deleteAfterValue(node* &head, node* &tail, int value){
    if(head==NULL){
        cout << "linked list is already empty\n";
        return;
    }

    node*temp = head;
    while(temp!=NULL && temp->data!=value){
        temp = temp->next;
    }

    if(temp==NULL){
        cout << "value not found in linked list\n";
        return;
    }
    
    if(temp->next==NULL){
        cout << "value found at last node, no next node to delete\n";
        return;
    }
    
    node * nodeToDel = temp->next;
    if(nodeToDel==tail)
        tail = temp;

    temp->next = nodeToDel->next;
    nodeToDel->next = NULL;
    delete nodeToDel;
}

void deleteValue(node* &head, node* &tail, int value){
    if(head==NULL){
        cout << "linked list is already empty\n";
        return;
    }

    if(head->data == value){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        if(head==NULL)
            tail=NULL;
        return;
    }

    node*temp = head;
    while(temp->next!=NULL && temp->next->data!=value){
        temp = temp->next;
    }

    if(temp->next==NULL){
        cout << "value not found\n";
    }
    else{
        node* nodeToDel = temp->next;
        if(nodeToDel == tail)
            tail = temp;
        temp->next = nodeToDel->next;
        nodeToDel->next = NULL;
        delete nodeToDel;
    }
}

int main(){

    cout << "inserting\n";
    node* head = NULL;
    node* tail = NULL;
    insertAfterValue(head, tail, 2, 10);
    print(head);
    insertAfterValue(head, tail, 10, 20);
    print(head);
    insertAfterValue(head, tail, 5, 30);
    print(head);
    cout << '\n';

    cout << "deleting node after value\n";
    deleteAfterValue(head, tail, 30);
    print(head);
    deleteAfterValue(head, tail, 20);
    print(head);
    deleteAfterValue(head, tail, 10);
    print(head);
    deleteAfterValue(head, tail, 10);
    print(head);
    cout << "\n\n";
    
    
    cout << "inserting again\n";
    insertAfterValue(head, tail, 2, 30);
    insertAfterValue(head, tail, 10, 20);
    insertAfterValue(head, tail, 5, 40);
    print(head);
    cout << '\n';

    cout << "deleting node with value\n";
    deleteValue(head, tail, 10);
    print(head);
    deleteValue(head, tail, 10);
    print(head);
    deleteValue(head, tail, 40);
    print(head);
    deleteValue(head, tail, 30);
    print(head);
    deleteValue(head, tail, 20);
    print(head);
    deleteValue(head, tail, 100);
    print(head);


    return 0;
}