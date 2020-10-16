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
#include <mutex>
using namespace std;

class Singleton {
public :
    static Singleton *getInstance() {
        if (single == nullptr) {
            std::unique_lock<mutex> lock(m_mutex);
            if (single == nullptr) {
                single = new Singleton();
            }
        }
        return single;
    }

private:
    static Singleton *single;
    static std::mutex m_mutex;
    Singleton() = default;
    Singleton(const Singleton &) = default;
    ~Singleton() {}
};

Singleton *Singleton::single = nullptr;
std::mutex Singleton::m_mutex;

int main() {
    Singleton *p = Singleton::getInstance();

    return 0;
}