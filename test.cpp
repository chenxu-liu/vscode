#include <iostream>
using namespace std;
// class shape 
// {public: 
// virtual int area()=0;
// }; 
// class rectangle:public shape 
// {public: 
// int a, b; 
// void setLength (int x, int y) {a=x;b=y;} 
// int area() {return a*b;} 
// };

// int  main(){
//     rectangle r;
//     r.setLength(3,5);
//     shape *s1=&r;
//     shape &s2=r;
//     //shape s3=r;
    
// }
template<typename T>
void my_swap(T &&a, T &&b) {
    typename remove_reference<T>::type c;
    c = a;
    a = b;
    b = c;
    return ;
}
// template<typename T>
// void my_swap(T &a, T &b) {
//     T c;
//     c = a;
//     a = b;
//     b = c;
//     return ;
// }
int main() {
    int a = 123, b = 456;
    cout << a << " " << b << endl;
    my_swap(a, b);
    cout << a << " " << b << endl;
    my_swap(move(a), move(b));
    cout << a << " " << b << endl;
}