#include<iostream>
#include<stack>
//using namespace std;
int main(){
    int n,arr[1000005],left[1000005],right[1000005];
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    std::stack<int> l,r;
    for(int i = 0; i < n; i++){
        while(!l.empty() && arr[l.top()] > arr[i]){
            left[l.top()] = i;
            l.pop();
        }
        l.push(i);
    }
    for(int i = n; i > 0; i--){
        while(!r.empty() && arr[r.top()] > arr[i]){
            right[r.top()] = i;
            r.pop();
        }
        r.push(i);
    }
    for(int i = 0; i < n;i++){
        if(right[i] == 0){
            std::cout << "-1" << " ";
        }else{
            std::cout << right[i] << " ";
        }
        if(left[i] == 0){
            std::cout << "-1" << std::endl;
        }else{
            std::cout << left[i] << std::endl;
        }

    }
    return 0;
}