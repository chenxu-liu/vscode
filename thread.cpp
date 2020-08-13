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

class Task{
public:
    template<typename T,typename ...ARGS>
    Task(T func,ARGS...args){
        this->func = std:: bind(func,args...);
    }
    void operator()(){
        this->func();
        return ;
    }
private:
    function<void()> func;
};
void thread_fun1(int a,int b){
    cout << a << "+" << b << "=" << a+ b << endl;
}
int main(){
    Task t(thread_fun1,3,4);
    return 0;
}