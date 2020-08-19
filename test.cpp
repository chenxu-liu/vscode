// #include <iostream>
// using namespace std;
// // class shape 
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
// template<typename T>
// void my_swap(T &&a, T &&b) {
//     typename remove_reference<T>::type c;
//     c = a;
//     a = b;
//     b = c;
//     return ;
// }

// int main() {
//     int a = 123, b = 456;
//     cout << a << " " << b << endl;
//     my_swap(a, b);
//     cout << a << " " << b << endl;
//     my_swap(move(a), move(b));
//     cout << a << " " << b << endl;
// }
// #include <iostream>
// #include<algorithm>
// using namespace std;

// namespace haizei{
//     template<typename T>
//     struct less{
//         bool operator()(const T &a,const T &b){
//             return a<b;
//         }
//     };
// }
// int a = 0;

// int y(){
//     a++;
//     return 0;
// }

// int main(){
//     int x = 0;
//     auto inc = [&](){ x++; };
//     inc();
//     inc();
//     y();
//     cout << a << endl;
//     int arr[5]={5,6,17,3,5};
//     sort(arr,arr+5,haizei::less<int>());
//     return 0;
// }
#include <cstdlib>
#include <string>

using namespace std;
class NotCopyable
{
     NotCopyable()=default;
    NotCopyable(const NotCopyable&)=delete;
    NotCopyable(NotCopyable &&)=delete;
    NotCopyable& operator=( const NotCopyable&) = delete;
    NotCopyable& operator= (NotCopyable&&)= delete;
};
struct Student:private NotCopyable
{
    string name;
    time_t birtyday;
};
int main()
{
    Student a;
    Student b = a;
    a = b;
    return 0;
}