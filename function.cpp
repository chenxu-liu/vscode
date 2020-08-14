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

namespace haizei {

template<typename RT, typename ...PARAMS> 
class base {
public :
    virtual RT operator()(PARAMS...) = 0;
    virtual ~base() {}
};

template<typename RT, typename ...PARAMS> 
class normal_func : public base<RT, PARAMS...> {
public :
    typedef RT (*func_type)(PARAMS...);
    normal_func(func_type func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }

private:
    func_type ptr;
};

template<typename C, typename RT, typename ...PARAMS> 
class functor : public base<RT, PARAMS...> {
public :
    functor(C &func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }

private:
    C &ptr;
};

template<typename RT, typename ...PARAMS> class function;
template<typename RT, typename ...PARAMS>
class function<RT(PARAMS...)> {
public :
    function(RT (*func)(PARAMS...)) 
    : ptr(new normal_func<RT, PARAMS...>(func)) {}

    template<typename T>
    function(T &&a) 
    : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(a)){}

    RT operator()(PARAMS... args) {
        return this->ptr->operator()(args...);
    }
    ~function() {
        delete ptr;
    }

private:
    base<RT, PARAMS...> *ptr;
};

} // end of haizei

void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
    return ;
}

int add(int a, int b) {
    return a + b;
}

struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b;
    }
};

// template<typename T>
// class FunctionCnt {
// public :
//     FunctionCnt(function<T(T, T)> g) : g(g), __cnt(0) {}
//     int operator()(T a, T b) {
//         __cnt += 1;
//         return g(a, b);
//     }
//     int cnt() { return __cnt; }

// private:
//     function<T(T, T)> g;
//     int __cnt;
// };
template<typename RT, typename ...PARAMS> class FunctionCnt;
template<typename RT, typename ...PARAMS>
class FunctionCnt<RT(PARAMS...)> {
public:
//template< class F >
//function( F f );
//此处是浅拷贝

    FunctionCnt(haizei::function<RT(PARAMS...)> g) : g(g), __cnt(0) {}
    RT operator()(PARAMS... args) {
        __cnt += 1;
        return g(args...);
    }
    int cnt() { return __cnt; }
private:
    function<RT(PARAMS...)> g;
    int __cnt;
};

int main() {
    MaxClass max;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;
    
    FunctionCnt<int(int,int)> add_cnt(add);
    add_cnt(3, 4);
    add_cnt(4, 5);
    add_cnt(7, 9);
    cout << add_cnt.cnt() << endl;
    // FunctionCnt<float> add_cnt2(add);
    // add_cnt2(3.0, 4.4);
    // add_cnt2(4.5, 5.0);
    // add_cnt2(7.4, 9.4);
    //  add_cnt2(7.4, 9.4);
    // cout << add_cnt2.cnt() << endl;
    return 0;
}