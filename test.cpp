#include <iostream>
using namespace std;
class shape 
{public: 
virtual int area()=0;
}; 
class rectangle:public shape 
{public: 
int a, b; 
void setLength (int x, int y) {a=x;b=y;} 
int area() {return a*b;} 
};

int  main(){
    rectangle r;
    r.setLength(3,5);
    shape *s1=&r;
    shape &s2=r;
    //shape s3=r;
    
}