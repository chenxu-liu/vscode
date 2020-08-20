#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Cat;
class Bat;
class Dog;
class Mouse;


class Animal {
public:
    class IVisitor {
    public:
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(Mouse *) = 0;
        virtual void visit(Bat *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~Animal() {};
};

class Dog : public Animal {
public:
    virtual void Accept(IVisitor *vis) override{
        vis->visit(this);
    }
};

class Cat : public Animal {
public:
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    }

};

class Mouse : public Animal {
public:
    virtual void Accept(IVisitor *vis) override{
        vis->visit(this);
    }

};

class Bat : public Animal {
public:
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    }

};

class AnimalCout : public Animal::IVisitor {
public:
    virtual void visit(Cat *obj) {
        cout << "this is a cat" << endl;
        sum++;
    } 
    virtual void visit(Dog *) {
        cout << "this is a dog " << endl;
        sum++;
    }
    virtual void visit(Mouse *)  {
        cout << "this is a mouse" << endl;
        sum++;
    }
    virtual void visit(Bat *) {
        cout << "this is a bat " << endl;
        sum++;
    }
    static int sum;
};
int AnimalCout::sum = 0;
int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0: arr[i] = new Cat(); break;
            case 1: arr[i] = new Dog(); break;
            case 2: arr[i] = new Mouse(); break;
            case 3: arr[i] = new Bat(); break;
        }
    }

    /*这么写太操蛋了
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<Cat *>(arr[i])) {
            cout << "this is a cat" << endl;
        } else if (dynamic_cast<Dog *>(arr[i])) {
            cout << "this is a dog" << endl;
        } else if (dynamic_cast<Mouse *>(arr[i])) {
            cout << "this is a mouse" << endl;
        }
    }*/

    AnimalCout vis;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
    }

    cout << vis.sum << endl;
    return 0;
}
