#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n\n";
}

Node* getMid(Node* head){
    if(head==NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

Node* reverse(Node* &head){
    Node*curr = head;
    Node* prev = NULL;
    Node* forward = curr -> next;

    while(curr!=NULL){
        forward = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

// TC-O(n)    SC-O(1)
bool checkPalindrome(Node* &head){
    if(head==NULL || head->next==NULL)
        return head;
    
    Node* mid = getMid(head);

    Node* reverseLLHead = reverse(mid->next);
    mid->next = reverseLLHead;

    Node*temp = head;
    Node*temp2 = reverseLLHead;

    while(temp2!=NULL){
        if(temp->data != temp2->data)
            return false;
        temp = temp->next;
        temp2 = temp2->next;
    }

    return true;
}

void removeDuplicates(Node* &head){
    if(head==NULL || head->next==NULL)
        return;

    Node*curr = head;

    while(curr->next!=NULL){
        Node* forward = curr->next;
        
        if(curr->data == forward->data){
            curr->next = forward->next;
            forward->next = NULL;
            delete forward;
        }
        else{
            curr = curr->next;
        }
    }
}

// TC-O(n)    SC-O(1)
void sort012s (Node* &head){
    if(head==NULL || head->next==NULL)
        return;
    
    int cnt0, cnt1, cnt2;
    cnt0 = cnt1 = cnt2 = 0;

    Node*temp = head;
    while(temp!=NULL){
        if(temp->data==0)
            cnt0++;
        else if(temp->data==1)
            cnt1++;
        else
            cnt2++;
        temp=temp->next;
    }

    temp = head;
    while(cnt0--){
        temp->data = 0;
        temp = temp->next;
    }
    while(cnt1--){
        temp->data = 1;
        temp = temp->next;
    }
    while(cnt2--){
        temp->data = 2;
        temp = temp->next;
    }
}

// TC-O(n)    SC-O(1)
void sort012s2(Node* &head){
    if(head==NULL || head->next==NULL)
        return;
    
    Node* head0 = new Node(-1);
    Node* tail0 = head0;
    Node* head1 = new Node(-1);
    Node* tail1 = head1;
    Node* head2 = new Node(-1);
    Node* tail2 = head2;

    Node* curr = head;

    while(curr!=NULL){
        Node* temp = curr;
        curr = curr->next;
        temp->next = NULL;

        if(temp->data == 0){
            tail0->next = temp;
            tail0 = temp;
        }
        else if(temp->data == 1){
            tail1->next = temp;
            tail1 = temp;
        }
        else{
            tail2->next = temp;
            tail2 = temp;
        }
    }

    // method 1
    // join all linked lists without including -1 except for head0 and update head
    if(head1->next!=NULL){
        tail0->next = head1->next;
        tail1->next = head2->next;
    }
    else
        tail0->next = head2->next;

    head = head0->next;

    // remove dummy nodes (dynamic wali, as static will remove on their own after completing function)
    head0->next = NULL;
    delete head0;
    head1->next = NULL;
    delete head1;
    head2->next = NULL;
    delete head2;


    // // method 2
    // // join all linkedlist and update head
    // tail0->next = head1;
    // tail1->next = head2;

    // // ḍelete -1 nodes and update head
    // tail0->next = head1->next;
    // head1->next = NULL;
    // delete head1;
    // tail1->next = head2->next;
    // head2->next = NULL;
    // delete head2;

    // head = head0->next;
    // delete head0;
    
}

// TC-O(max(m,n))    SC-O(1)
Node* addNumbers(Node* &head1, Node* &head2){
    if(head1==NULL)
        return head2;
    else if(head2==NULL)
        return head1;
            
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* curr1 = head1;
    Node* curr2 = head2;
    int carry = 0;

    Node*ans = new Node(-1);
    Node*ansTail = ans;

    while(curr1 != NULL && curr2 != NULL){
        int val1 = curr1->data;
        int val2 = curr2->data;

        int sum = val1 + val2 + carry;
        carry = sum/10;

        Node* digitNode = new Node(sum%10);
        ansTail->next = digitNode;
        ansTail = digitNode;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while(curr1 != NULL){
        int val1 = curr1->data;

        int sum = val1 + carry;
        carry = sum/10;

        Node* digitNode = new Node(sum%10);
        ansTail->next = digitNode;
        ansTail = digitNode;

        curr1 = curr1->next;
    }

    while(curr2 != NULL){
        int val2 = curr2->data;

        int sum = val2 + carry;
        carry = sum/10;

        Node* digitNode = new Node(sum%10);
        ansTail->next = digitNode;
        ansTail = digitNode;

        curr2 = curr2->next;
    }

    while(carry){
        Node* digitNode = new Node(carry%10);
        ansTail->next = digitNode;
        ansTail = digitNode;

        carry = carry/10;
    }

    ans = ans->next;

    ans = reverse(ans);

    return ans;
}

int main(){

    /*// check palindrome
        Node* head = new Node(10);
        Node* second = new Node(20);
        Node* third = new Node(30);
        Node* forth = new Node(40);
        Node* fifth = new Node(50);
        Node* sixth = new Node(40);
        Node* seventh = new Node(30);
        Node* eighth = new Node(20);
        Node* ninth = new Node(10);
        head->next = second;
        second->next = third;
        third->next = forth;
        forth->next = fifth;
        fifth->next = sixth;
        sixth->next = seventh;
        seventh->next = eighth;
        eighth->next = ninth;

        print(head);
        cout << checkPalindrome(head) << '\n';
        print(head);
    */

    /*// remove duplicates from a sorted linked list
        Node* head = new Node(10);
        Node* second = new Node(10);
        Node* third = new Node(20);
        Node* forth = new Node(20);
        Node* fifth = new Node(20);
        Node* sixth = new Node(20);
        Node* seventh = new Node(30);
        Node* eighth = new Node(20);
        Node* ninth = new Node(20);
        head->next = second;
        second->next = third;
        third->next = forth;
        forth->next = fifth;
        fifth->next = sixth;
        sixth->next = seventh;
        seventh->next = eighth;
        eighth->next = ninth;

        print(head);
        removeDuplicates(head);
        print(head);
    */

    /*// sort 0s, 1s and 2s
        Node* head = new Node(0);
        Node* second = new Node(0);
        Node* third = new Node(2);
        Node* forth = new Node(2);
        Node* fifth = new Node(2);
        Node* sixth = new Node(1);
        Node* seventh = new Node(2);
        Node* eighth = new Node(1);
        Node* ninth = new Node(0);
        head->next = second;
        second->next = third;
        third->next = forth;
        forth->next = fifth;
        fifth->next = sixth;
        sixth->next = seventh;
        seventh->next = eighth;
        eighth->next = ninth;

        print(head);
        // sort012s(head);
        sort012s2(head);
        print(head);
    */

    /*
    */
    // add 2 numbers represented by 2 linked lists
        Node* head1 = new Node(9);
        Node* second1 = new Node(9);
        Node* third1 = new Node(9);
        head1->next = second1;
        second1->next = third1;
        
        Node* head2 = new Node(7);
        Node* second2 = new Node(8);
        head2->next = second2;

        print(head1);
        print(head2);
        Node* ans = addNumbers(head1,head2);
        print(ans);


    /*
    */
    // 

    /*
    */
    // 

    return 0;
}