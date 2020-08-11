#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <functional>
using namespace std;
class Animal{
public:
    Animal(){}
    Animal(const string &name):__name(name){}
    Animal(const Animal &a){
         this->__name = a.__name;
         cout << "copy" << endl;
     }
    virtual void run(){}
    virtual ~Animal(){
        cout << "Animal Deconstruction" << endl;
    }
protected:
    string __name;
};
class Cat :public Animal{
public:
    Cat():Animal("cat"){
        cout << "Cat" << endl;
    }
    Cat(const Cat &a){
         cout << "CAR copy" << endl;
     }
    void run() override{
        cout << "i can run with four legs" << endl;
    }
    void say() {
        cout << "i can say" << endl;
    }
    ~Cat() override{
        cout << "Cat Deconstruction" << endl;
    }

};
int main(){
    //Cat a;
    Animal *b = new Cat();
    // Animal *c = &a;
    // a.run();
    // b.run();
    // c->run();
    delete b;
    return 0;
}