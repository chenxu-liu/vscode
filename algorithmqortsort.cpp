#include<iostream>

using namespace std;

void quick_sort(int *num, int l, int r){
    if(l >= r) return;
    int m = num[l];
    while(l < r){
        while(m < num[r]) r--;
        
        while(m > num[l]) l++;
    }

    quick_sort(num,)
}

int main(){
    return 0;
}