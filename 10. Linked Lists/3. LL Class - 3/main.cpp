#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// TC-O(n)    SC-(1)
int getMiddle(node*head){
    if(head==NULL)
        return -1;
    
    node*slow = head;
    node*fast = head;

    // while(fast!=NULL){           // for both 3rd / 4th node act as middle in ll of 6 nodes
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next;
        // if(fast!=NULL){          // if 4th node act as middle in ll of 6 nodes
        if(fast!=NULL && fast->next!=NULL){       // if 3rd node act as middle in ll of 6 nodes
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow->data;
}

void print(node* head){
    node*temp = head;
    while(temp!=NULL){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n\n";
}

int getLength(node*head){
    node* temp = head;
    int ans = 0;

    while(temp!=NULL){
        ans++;
        temp = temp->next;
    }

    return ans;
}

node* reverseInKGroups(node*head, int k){
    if(head==NULL || k>getLength(head))
        return head;
    
    // cout << "head is " << head->data << '\n';
    node*prev = NULL;
    node*curr = head;
    node* next = curr->next;
    int cnt = 0;

    while(cnt<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    head->next = reverseInKGroups(curr, k);

    return prev;
}

// if k < length, it reverse that too
node* reverseInKGroups2(node*head, int k){
    if(head==NULL)
        return NULL;
    
    // cout << "head is " << head->data << '\n';
    node*prev = NULL;
    node*curr = head;
    node* next = curr->next;
    int cnt = 0;

    int mini = min(k, getLength(head));
    while(cnt<mini){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    head->next = reverseInKGroups2(curr, k);

    return prev;
}

bool checkLoop(node* &head){
    if(head==NULL){
        cout << "linked list is empty";
        return false;
    }
    
    node*slow = head;
    node*fast = head;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast==slow)
            return true;
    }

    return false;
}

int getLoopStart(node* &head){
    if(head==NULL)
        return -1;
    
    node*fast = head;
    node*slow = head;

    bool loopFound = false;

    while(fast!=NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast==slow){
            loopFound = true;
            break;
        }
    }

    if(loopFound){
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }

    return -1;
}

// also works if loop starts from head
void removeLoop(node* &head){
    if(head==NULL)
        return;
    
    node* fast = head;
    node* slow = head;
    bool loopFound = false;

    while(fast!=NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast==slow){
            loopFound = true;
            break;
        }
    }

    if(loopFound){
        slow = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }

        cout << "loop started from " << slow->data << '\n';
        node*prev = slow;
        while(prev->next!=slow){
            prev = prev->next;
        }
        prev->next = NULL;
        
    }
    else{
        cout << "no loop was present\n";
    }
}

int main(){

    /*// get middle node of linked list
        node* head = new node(10);
        node* second = new node(20);
        node* third = new node(30);
        node* forth = new node(40);
        node* fifth = new node(50);
        node* sixth = new node(60);
        head->next = second;
        second->next = third;
        third->next = forth;
        forth->next = fifth;
        fifth->next = sixth;

        print(head);
        cout << getMiddle(head) << "\n\n";
    */

    /*// reverse linked list in k groups
        node* head = new node(10);
        node* second = new node(20);
        node* third = new node(30);
        node* forth = new node(40);
        node* fifth = new node(50);
        node* sixth = new node(60);
        head->next = second;
        second->next = third;
        third->next = forth;
        forth->next = fifth;
        fifth->next = sixth;

        int k = 4;
        head = reverseInKGroups(head, k);
        print(head);

        head = reverseInKGroups2(head, k);
        print(head);
    */

    /*
    */
    // detect and delete loop (floyd's algorithm)
        // check loop is present in linked list or not
        // starting point of loop
        // remove loop
        node* head = new node(10);
        node* second = new node(20);
        node* third = new node(30);
        node* forth = new node(40);
        node* fifth = new node(50);
        node* sixth = new node(60);
        node* seventh = new node(70);
        node* eighth = new node(80);
        node* ninth = new node(90);
        head->next = second;
        second->next = third;
        third->next = forth;
        forth->next = fifth;
        fifth->next = sixth;
        sixth->next = seventh;
        seventh->next = eighth;
        eighth->next = ninth;
        ninth->next = fifth;
        // ninth->next = head;

        cout << checkLoop(head) << "\n\n";

        cout << getLoopStart(head) << "\n\n";

        removeLoop(head);
        print(head);

    /*
    */
    //

    /*
    */
    //

    /*
    */
    //

    /*
    */
    //

    /*
    */
    //

    /*
    */
    //

    return 0;
}