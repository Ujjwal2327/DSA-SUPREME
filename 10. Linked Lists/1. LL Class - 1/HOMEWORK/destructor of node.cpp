#include<iostream>
using namespace std;

/*// singly linked list node
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
        int val = this->data;
        node*temp = this;
        if(temp->next!=NULL){
            node * newNode = temp->next;
            delete newNode;
            temp->next = NULL;
        }
        cout << "node with data " << val << " is deleted\n";
        // first delete aage wali node, then make current ke next ko NULL so that it does not point to any memory and after finishing of destructor current node and temp pointer both will be deleted
    }
};
*/

/*// doubly linked list node
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(){
        this->data = -1;
        this->next = this;
        this->prev = this;
    }

    node(int data){
        this->data = data;
        this->next = this;
        this->prev = this;
    }

    ~node(){
        int val = this->data;
        node*temp = this;
        if(temp->next!=NULL){
            node * newNode = temp->next;
            delete newNode;
            temp->next = NULL;
        }
        cout << "node with data " << val << " is deleted\n";
        // first delete aage wali node, then make current ke next ko NULL so that it does not point to any memory and after finishing of destructor current node and temp pointer both will be deleted
    }
};
*/

int main(){



    return 0;
}