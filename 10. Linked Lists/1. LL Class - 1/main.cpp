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
        // yaha pr ques aa skta hai ki yah jo nayi node bnayi hai vo to ek function ke andr bni hai, mtlb function ke baag khtm ho jayegi?
        // nhi khtm hogi kyuki ye nayi node dynamically bnayi gyi hai
        // mtlb nayi node khtm nhi hogi, pr haa newNode naam ka pointer khtm ho jayega
        // kyuki nayi node heap memory me bni hai, aur newNode pointer stack memory me bana hai(jo function ke baad destroy ho jata hai)

    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }

}

void insertAtTail(node*&head, node* &tail, int data){
    node* newNode = new node(data);

    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

int getLength(node*&head){
    node*temp = head;
    int ans = 0;
    while(temp!=NULL){
        ans++;
        temp = temp->next;
    }

    return ans;
}

// pos starts from 1
void insertAtPosition(node* &head, node* &tail, int pos, int data){
    node * newNode = new node(data);

    // code is perfect without this too
        // if(head==NULL){
        //     head = newNode;
        //     tail = newNode;
        //     return;
        // }

    // insert at head
    if(pos==1){
        insertAtHead(head, tail, data);
        return;
    }

    // insert at tail or beyond that    also for case when head=NULL / len=0
    int len = getLength(head);
    if(pos>len){
        insertAtTail(head, tail, data);
        return;
    }

    // insert in between LL
    node*temp = head;
    int i = 1;
    while(i<=pos-2){
        temp = temp -> next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// pos starts from 1
void deleteAtPosition(node* &head, node* &tail, int pos){
    if(head==NULL){
        cout << "cannot delete from empty LL\n";
        return;
    }

    if(head->next==NULL){
        node*temp = head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }

    if(pos==1){
        node*temp = head;
        head = head->next;
        // temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);
    if(pos>len){
        cout << "position exceed length of linked list\n";
        return;
    }

    node*temp = head;
    int i=1;
    while(i<=pos-2){
        temp = temp->next;
        i++;
    }
    node*nodeToDel = temp->next;
    temp->next = temp->next->next;
    // nodeToDel->next = NULL;
    delete nodeToDel;

    if(temp->next==NULL)
        tail = temp;
}

int main(){

    /*// creating a linked list from individual nodes and printing it
        node* first = new node();
        node* second = new node(20);
        node* third = new node();
        node* forth = new node(40);
        node* fifth = new node(50);

        first->next = second;
        second->next = third;
        third->next = forth;
        forth->next = fifth;

        print(first);
    */

    /*// creating, inserting and deleting from a linked list
    */
        node * head = NULL;
        node * tail = NULL;
        insertAtHead(head, tail, 20);
        insertAtHead(head, tail, 30);
        insertAtHead(head, tail, 40);
        insertAtHead(head, tail, 50);
        print(head);

        insertAtTail(head, tail, 10);
        insertAtTail(head, tail, 9);
        insertAtTail(head, tail, 8);
        print(head);

        insertAtPosition(head, tail, 3, 35);
        print(head);
        insertAtPosition(head, tail, 1, 60);
        print(head);
        insertAtPosition(head, tail, 10, 7);
        print(head);
        insertAtPosition(head, tail, 15, 6);
        print(head);
        cout << "\n";

        deleteAtPosition(head, tail, 1);
        print(head);
        deleteAtPosition(head, tail, 3);
        print(head);
        deleteAtPosition(head, tail, 9);
        print(head);
        deleteAtPosition(head, tail, 9);
        print(head);

    return 0;
}