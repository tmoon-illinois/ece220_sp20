#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char name[20];
    int age;
    public:
//    Person(){};
    Person(char const *_name, int _age){
        strcpy(name, _name);
        age = _age;
    };
    void ShowData(){
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
    };
    ~Person();
};
/*
Person::Person(char const *_name, int _age){
    strcpy(name, _name);
    age = _age;
}
Person::~Person(){
    cout<< "Delete object:"<<name<<endl;
}
void Person::ShowData(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
}
*/

int main(){
//    Person p = {"Alice", 20};

    //Person p("Alice", 20);
    Person p = Person("Alice", 20);
    p.ShowData();

    Person p2;
    p2.ShowData();
}
