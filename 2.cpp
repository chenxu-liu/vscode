#include<iostream>
using namespace std;
namespace haizei{
template<typename T,typename U>
auto max(T a, U b) ->decltype(a>b?a:b){
    return a>b?a:b;
}
class A{
public:
    template<typename T>
void operator()(const T &a){
    cout << a << endl;
}
};
}
int main(){
    cout << haizei::max(13,13.2) << endl;
    haizei::A a;
    a("cas");
    a(123);
    return 0;
}