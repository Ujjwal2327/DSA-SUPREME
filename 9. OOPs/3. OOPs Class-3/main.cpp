#include<iostream>
using namespace std;

class Animal{
    public:
    void speak(){
        cout << "speaking\n";
    }
};

class Dog : public Animal{
    public:
    void speak(){
        cout << "barking\n";
    }
};

int main(){

    Animal a;
    cout << a.speak();

    Dog d;
    cout << d.speak();

    return 0;
}