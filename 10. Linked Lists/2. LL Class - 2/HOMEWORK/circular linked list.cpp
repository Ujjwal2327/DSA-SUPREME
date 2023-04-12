#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(){
        this->data = -1;
        this->next = this;
    }

    node(int data){
        this->data = data;
        this->next = this;
    }

    ~node(){
        cout << "node with data " << this->data << " is deleted\n";
    }
};

void print(node* &start){
    if(start==NULL){
        cout << "empty CLL\n\n";
        return;
    }

    node*temp = start;
    do{
        cout << temp->data << ' ';
        temp = temp->next;
    }
    while(temp!=start);

    cout << "\n\n";
}

node* getEnd(node* &start){
    if(start==NULL)
        return NULL;
    
    node*temp = start;
    while(temp->next != start){
        temp = temp->next;
    }

    return temp;
}

void insertAfterValue(node* &start, int value, int data){
    node* newNode = new node(data);

    if(start==NULL){        // empty CLL
        start = newNode;
        return;
    }

    node*temp = start;
    bool valFound = false;
    do{
        if(temp->data==value){
            valFound = true;
            break;
        }
        temp = temp->next;
    }
    while(temp!=start);

    if(valFound){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else{
        node* end = getEnd(start);
        end->next = newNode;
        newNode->next = start;
    }
}

void deleteAfterValue(node* &start, int value){
    if(start==NULL){
        cout << "CLL is already empty\n";
        return;
    }
    
    if(start->next == start && start->data == value){
        start->next = NULL;
        delete start;
        start = NULL;
        return;
    }

    bool valFound = false;
    node* temp = start;
    do{
        // if(temp->next->data == value){     // for deleting a node with its data = value
        if(temp->data == value){
            valFound = true;
            break;
        }

        temp = temp->next;
    }
    while(temp != start);

    if(valFound){
        node* nodeToDel = temp->next;
        if(nodeToDel == start)
            start = start->next;

        temp->next = temp->next->next;
        nodeToDel->next = NULL;
        delete nodeToDel;
    }
    else
        cout << "value not found\n";
}

int getLength(node* &start){
    if(start==NULL)
        return 0;

    int ans = 0;
    node * temp = start;
    do{
        ans++;
        temp = temp->next;
    }
    while(temp != start);

    return ans;
}

int main(){

    /*// creating a circular linked list from individual nodes and printing it
        node* first = new node(10);
        node* second = new node(20);
        node* third = new node(30);
        node* forth = new node(40);

        first->next = second;
        second->next = third;
        third->next = forth;
        forth->next = first;

        print(first);
        print(second);
        print(third);
        print(forth);
    */

    /*// insetion, deletion and length of circular linked list
        cout << "inserting\n";
        node* start = NULL;
        insertAfterValue(start, 5, 50);
        print(start);
        insertAfterValue(start, 5, 40);
        print(start);
        insertAfterValue(start, 50, 45);
        print(start);
        insertAfterValue(start, 45, 69);
        print(start);

        // deleting
        cout << "deleting\n";
        deleteAfterValue(start, 40);
        print(start);
        deleteAfterValue(start, 45);
        print(start);
        deleteAfterValue(start, 40);
        print(start);
        deleteAfterValue(start, 20);
        print(start);
        deleteAfterValue(start, 40);
        print(start);        
        deleteAfterValue(start, 25);
        print(start);
        cout << "\n";

        // getLength
        cout << "getLength\n";
        insertAfterValue(start, 5, 50);
        insertAfterValue(start, 5, 40);
        insertAfterValue(start, 50, 45);
        insertAfterValue(start, 45, 69);
        print(start);
        cout << getLength(start) << '\n';
    */

    return 0;
}