#include<iostream>
using namespace std;
int a = 0;
int f(int i){
    while(i){
        a = i % 10;
        i /= 10;
        if(a == 2 || a == 0 || a == 1 || a == 9){
            return 1;
        }
    }
    return 0;
}

int main(){
    long long  sum = 0;
    for(int i = 1; i <= 2019; i++){
        if(f(i)){
            sum += i * i;
        }
    }
    cout << sum << endl;
    return 0;
}