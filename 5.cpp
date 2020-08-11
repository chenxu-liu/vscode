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
    Animal(const string &name):__name(name){}
    virtual void run();
protected:
    string __name;
};
class Cat :public Animal{
public:
    Cat():Animal("cat"){}
    void run() override{
        cout << "i can run with four legs" << endl;
    }
    void say() {
        cout << "i can say" << endl;
    }

};
int main(){
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    return 0;
}