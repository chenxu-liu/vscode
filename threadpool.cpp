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
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>
using namespace std;

namespace haizei {
class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, std::forward<ARGS>(args)...);
    }
    void operator()() {
        this->func();
        return ;
    }
    ~Task() {}

private:
    std::function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int n = 5) 
    : max_threads_num(n),
    m_mutex(),
    m_cond() {}
    void start() {
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new std::thread(&ThreadPool::worker, this));
        }
        return ;
    }
    void worker() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = true;
        while (is_running[id]) {
            Task *t = this->getOneTask();
            (*t)();
            delete t;
        }
        return ;
    }
    void stop() {
        for (int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return ;
    }

    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS...args) {
        std::unique_lock<std::mutex> lock(m_mutex);
        //std::cout << std::this_thread::get_id() << " add one task" << std::endl;
        this->task_queue.push(new Task(func, std::forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }

private:
    void stop_task() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = false;
        return ;
    }
    Task *getOneTask() {
        std::unique_lock<std::mutex> lock(m_mutex); 
        while (task_queue.empty()) {
            //std::cout << std::this_thread::get_id() << " wait one task" << std::endl;
            m_cond.wait(lock);
        }
        //std::cout << std::this_thread::get_id() << " take one task" << std::endl;
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    int max_threads_num;
    std::vector<std::thread *> threads;
    std::queue<Task *> task_queue;
    std::map<std::thread::id, bool> is_running;
    
    std::mutex m_mutex;
    std::condition_variable m_cond;
};
} // end of namespace haizei

void thread_func1(int a, int b) {
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    return ;
}

void thread_func2(int &n) {
    n += 1;
    return ;
}

void (*func)();

void task_func(int x) {
    std::cout << "thread task func" << std::endl;
    return ;
}
bool isPrime(int x){
    for(int i=2;i*i<=x;++i){
        if(x%i==0) return false;
    }
    return true;
}
void  countPrimes(int l,int n) {
    int count=0;
    if(n<2) return ;
    for(int i=l;i<=n;++i){
        if(isPrime(i))   //如果 i为素数
        {
            ++count;
        }
    }
    cout  << count <<endl;
}
int main() {
    haizei::Task t1(thread_func1, 3, 4);
    haizei::Task t2(thread_func1, 5, 6);
    haizei::Task t3(thread_func1, 7, 8);
    t1(), t2(), t3();
    int n = 0;
    
    haizei::Task t4(thread_func2, std::ref(n));
    t4(), t4(), t4();
    std::cout << n << std::endl;

    haizei::ThreadPool tp(6);
    tp.start();
    // tp.addOneTask(task_func, 123);
    // tp.addOneTask(task_func, 123);
    // tp.addOneTask(task_func, 123);
    // tp.addOneTask(task_func, 123);
    // tp.stop();
    // tp.addOneTask(task_func, 123);
    // tp.addOneTask(task_func, 123);
    // tp.addOneTask(task_func, 123);
    cout << "-------" << endl;
    tp.addOneTask(countPrimes, 2,200000);
     tp.addOneTask(countPrimes, 200000,400000);
    tp.addOneTask(countPrimes, 4000000,600000);
     tp.addOneTask(countPrimes, 600000,800000);
     tp.addOneTask(countPrimes, 800000,1000000);
    tp.stop();
    std::cout << "hello world" << std::endl;
    std::cout << 17984+15876+14853+14547 << std::endl;
    return 0;
}