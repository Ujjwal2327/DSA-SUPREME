#include<iostream>
using namespace std;

class animal1{

};

class animal2{
    int a = 5;
};

class animal3{
    string name;
};

class animal4{
    int a = 5;
    char ch = 'a';
};

class animal{
    public:

    // states
    int age;
    string name;

    // behaviours
    void eat(){

    }

    void sleep(){
        cout << name << " is sleeping\n";
    }

    private:
    int weight;

    public:
    int getWeight(){
        return weight;
    }

    void setWeight(int w){
        weight = w;
    }

};

int main(){

    /*
    // sizeof(object)
        cout << sizeof(animal1) << '\n';
        cout << sizeof(animal2) << '\n';
        cout << sizeof(animal3) << '\n';        // why 24?
        cout << sizeof(animal4) << '\n';        // due to padding and greedy alignment
    */

    /*
    // object creation  static memory allocation
        animal ramesh;
        cout << sizeof(ramesh) << '\n';
        
        // access properties of object
            cout << ramesh.name << '\n';
            cout << ramesh.age << "\n\n";
        
            ramesh.name = "Lion";
            ramesh.age = 23;
            cout << ramesh.name << '\n';
            cout << ramesh.age << "\n\n";

            ramesh.sleep();
            cout << '\n';

            cout << ramesh.getWeight() << '\n';
            ramesh.setWeight(70);
            cout << ramesh.getWeight() << '\n';
    */

    /*
    */
    // dynamic memory allocation
        animal * suresh = new animal;
        (*suresh).age = 15;
        suresh->age = 17;

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



// #include<iostream>
// #include<vector>
// using namespace std;

// class animal{
//     // string name;
//     // int a;
//     // int b;
//     vector<int>arr;
//     // char b;
//     // char c;
//     // string s;
// };

// int main(){
//     cout<<sizeof(animal)<<'\n';

//     return 0;
// }