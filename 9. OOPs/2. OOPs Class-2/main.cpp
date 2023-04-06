#include<iostream>
using namespace std;

// encapsulation
class Animal{
    public:
    int age;
    int weight;
    void eat(){
        cout << "eating\n"; 
    }
};

// perfect encapsulation
class Animal2{
    int age;
    int weight;

    public:
    void eat(){
        cout << "eating\n"; 
    }

    int getAge(){
        return this->age;
    }

    void setAge(int age){
        this->age = age;
    }

};


// inheritence
// parent class
class Animal3{
    int age;

    public:
    int weight;

    protected:
    void eat(){
        cout << "eating\n"; 
    }
};

// child class
class Dog : public Animal3 {

};


// single level inheritence
class Car{
    public:
    string name;
    int age;
    int weight;

    void speedUp(){
        cout << "Speeding Up\n";
    }

};

class scorpio : public Car{

};


// multilevel
class Fruit{
    public:
    string name;
};

class Mango : public Fruit{
    public:
    int weight;
    Mango(){
        weight=150;
        cout << "address of weight in Mango is " << &weight<<'\n';
    }
};

class Alphonso : public Mango{
    public:
    int sugarLevel;
    int weight;
    Alphonso(){
        weight = 120;
        cout << "address of weight in Alphonso is " << &weight<<'\n';
    }
};


// multiple inheritence
class A {
    public:
    int physics;
};

class B {
    public:
    int chemistry;
};

class C : public A, public B{
    public:
    int maths;
};


// heirarchical
class Bike{
    public:
    int weight;
    string name;

    void speedUp(){
        cout << "Speeding Up\n";
    }
};

class bmw : public Bike{
    
};

class bullet : public Bike{

};



// polymorphism
// function overloading
class Maths{
    public:

    int sum(int a, int b){
        return a+b;
    }

    int sum(int a, int b, int c){
        return a+b+c;
    }

    int sum(int a, float b){
        return a+b;
    }
};


// operator overloading
class Para{
    public:
    int val;

    void operator+(Para &obj2){
        int value1 = this->val;
        int value2 = obj2.val;
        cout << value1 + value2 << '\n';
    }

    void operator+(char ch){
        int value = this->val;
        cout << value+10 << '\n';
    }
};

int main(){

    /*
    // 
        Dog d1;
        d1.age;
        d1.weight;
        d1.eat();
    */

    /*
    // 
        Alphonso a;
        cout << a.name << ' ' << a.weight << ' ' << a.sugarLevel << '\n';
        cout << &(a.weight) << '\n';
    */

    /*
    // 
        C pcm;
        cout << pcm.chemistry << ' ' << pcm.physics << ' ' << pcm.maths << '\n';

    */

    /*
    // 
        Para a;
        Para b;
        a.val = 5;
        b.val = 2;

        a+b;
        a+'c';
    */

    return 0;
}