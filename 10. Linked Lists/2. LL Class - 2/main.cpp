// its about doubly linked list
#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node*next;
    node*prev;

    node(){
        this->data = -1;
        this->next = NULL;
        this->prev = NULL;
    }

    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~node(){
        cout << "node with data " << this->data << " is deleted\n";
    }
};

// TC-O(n)    SC-O(1)
void print(node* &head){
    node*temp = head;

    while(temp!=NULL){
        cout << temp->data << ' ';
        temp = temp->next;
    }

    cout << "\n\n";
}

// TC-O(n)    SC-O(1)
int getLength(node* &head){
    node* temp = head;
    int ans = 0;
    while(temp!=NULL){
        ans++;
        temp = temp->next;
    }

    return ans;
}

// TC-O(1)    SC-O(1)
void insertAtHead(node* &head, node* &tail, int data){
    node* newNode = new node(data);

    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// TC-O(1)    SC-O(1)
void insertAtTail(node* &head, node* &tail, int data){
    node* newNode = new node(data);

    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(node* &head, node* &tail, int pos, int data){
    node* newNode = new node(data);

    // no need to write this case, as it also comes under (pos>len) case
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }

    if(pos==1){
        insertAtHead(head, tail, data);
        return;
    }

    int len = getLength(head);
    if(pos>len){
        insertAtTail(head, tail, data);
        return;
    }

    node*temp = head;
    int i=1;
    while(i<=pos-2){
        temp = temp->next;
        i++;
    }
    
    node*curr = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next = curr;
    curr->prev = newNode;

    // above 5 lines of code is same as below code, but in below code, order matters
    // newNode->next = temp->next;
    // temp->next->prev = newNode;
    // newNode->prev = temp;
    // temp->next = newNode;
}

void deleteAtPosition(node* &head, node* &tail, int pos){
    if(head==NULL){
        cout << "cannot delete from empty LL";
    }

    if(head->next==NULL){
        node*temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    if(pos==1){
        node*temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);
    if(pos>len){
        cout << "position exceeds length of doubly LL\n";
        return;
    }

    if(pos==len){
        node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    node* temp = head;
    int i=1;
    while(i<=pos-2){
        temp = temp->next;
        i++;
    }

    node*nodeToDel = temp->next;
    temp->next = nodeToDel->next;
    nodeToDel->next->prev = temp;
    nodeToDel->next = NULL;
    nodeToDel->prev = NULL;
    delete nodeToDel;
}

int main(){

    /*// creating a doubly linked list from individual nodes and printing it
        node*first = new node(10);
        node*second = new node(20);
        node*third = new node(30);
        node*forth = new node(40);

        first->next = second;
        second->prev = first;
        second->next = third;
        third->prev = second;
        third->next = forth;
        forth->prev = third;

        print(first);
    */
    
    /*// inserting a node in doubly LL
        node*head = NULL;
        node*tail = NULL;
        cout << "inset at head\n";
        insertAtHead(head, tail, 10);
        insertAtHead(head, tail, 20);
        insertAtHead(head, tail, 30);
        insertAtHead(head, tail, 40);
        print(head);

        cout << "insert at tail\n";
        insertAtTail(head, tail, 9);
        insertAtTail(head, tail, 8);
        insertAtTail(head, tail, 7);
        print(head);

        cout << "insert at position\n";
        insertAtPosition(head, tail, 1, 50);
        print(head);
        insertAtPosition(head, tail, 8, 15);
        print(head);
        insertAtPosition(head, tail, 10, 6);
        print(head);
        insertAtPosition(head, tail, 15, 5);
        print(head);
        cout << '\n';

        cout << "delete at position\n";
        deleteAtPosition(head, tail, 1);
        print(head);
        deleteAtPosition(head, tail, 10);
        print(head);
        deleteAtPosition(head, tail, 7);
        print(head);
    */

    return 0;
}