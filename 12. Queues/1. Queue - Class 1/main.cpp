#include<iostream>
#include<queue>
#include<deque>
using namespace std;

// simple code can be done using modulus
class Queue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear==size)
            cout << "queue overflow\n";
        else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(front==rear)
            cout << "queue underflow\n";
        else{
            front++;

            // optimization     if queue is empty, again start from 0
            if(front==rear)
                front = rear = 0;
        }
    }

    int getFront(){
        if(front==rear){
            cout << "queue underflow\n";
            return -1;
        }
        else
            return arr[front];
    }
    
    int back(){
        if(front==rear){
            cout << "queue underflow\n";
            return -1;
        }
        else
            return arr[rear-1];
    }

    bool empty(){
        if(front==rear)
            return true;
        return false;
    }

    int getSize(){
        return rear-front;
    }
};

class CQueue{
    int *arr;
    int size;
    int front; 
    int rear;

    public:
    CQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        if((front==0 && rear==size-1) || front==rear+1)     // full case
        // if( rear== (front-1) % (size-1) )     // full case     can also use this condition
            cout << "queue overflow\n";
        else if(front==-1){                                 // single element case
            front = rear = 0;
            arr[rear] = data;
        }
        else if(front!=0 && rear==size-1){                  // circular nature
            rear=0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        if(front==-1)                       // empty case
            cout << "queue underflow\n";
        else if(front==rear)                // singlr element case
            front = rear = -1;
        else if(front==size-1)              // circular nature
            front = 0;
        else
            front++;
    }
};

class CDeque{
    int *arr;
    int size;
    int front; 
    int rear;

    public:
    CDeque(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data){
        if((front==0 && rear==size-1) || front==rear+1)     // full case
            cout << "queue overflow\n";
        else if(front==-1){                                 // single element case
            front = rear = 0;
            arr[rear] = data;
        }
        else if(front!=0 && rear==size-1){                  // circular nature
            rear=0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }
    
    void pushFront(int data){
        if((front==0 && rear==size-1) || front==rear+1)     // full case
            cout << "queue overflow\n";
        else if(front==-1){                                 // single element case
            front = rear = 0;
            arr[front] = data;
        }
        else if(front==0 && rear!=size-1){                  // circular nature
            front = size-1;
            arr[front] = data;
        }
        else{
            front--;
            arr[front] = data;
        }
    }

    void popFront(){
        if(front==-1)                       // empty case
            cout << "queue underflow\n";
        else if(front==rear)                // singlr element case
            front = rear = -1;
        else if(front==size-1)              // circular nature
            front = 0;
        else
            front++;
    }

    void popRear(){
        if(front==-1)                       // empty case
            cout << "queue underflow\n";
        else if(front==rear)                // singlr element case
            front = rear = -1;
        else if(rear==0)              // circular nature
            rear = size-1;
        else
            rear--;
    }
};

int main(){

    /*// using STL queue for creation, insertion, removal, front element, back element, empty or not, size of queue 
        queue<int>q;
        q.push(10);
        q.push(20);
        q.push(30);
        cout << q.front() << '\n';
        cout << q.back() << '\n';
        cout << q.empty() << '\n';
        q.pop();
        cout << q.front() << '\n';
        cout << q.size() << '\n';
    */

    /*// implement queue using dynamic array and implement for creation, insertion, removal, front element, back element, empty or not, size of queue 
        Queue q(5);
        q.push(10);
        q.push(20);
        q.push(30);
        cout << q.getFront() << '\n';
        cout << q.back() << '\n';
        cout << q.empty() << '\n';
        q.pop();
        cout << q.getFront() << '\n';
        cout << q.getSize() << '\n';
    */

    /*
    */
    // STL deque
        deque<int>dq;
        dq.push_front(5);
        dq.push_front(10);
        dq.push_back(20);
        dq.push_back(30);
        cout << dq.front() << '\n';
        cout << dq.back() << '\n';
        dq.pop_front();
        dq.pop_back();
        cout << dq.front() << '\n';
        cout << dq.back() << '\n';
        cout << dq.size() << '\n';
        cout << dq.empty() << '\n';


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