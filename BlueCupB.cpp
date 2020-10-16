#include<iostream>
using namespace std;
int arr[30000000];
int main(){
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    for(int i = 4; i <= 20190324; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        //arr[i] %= 10000;
    }
    cout << arr[20190324] << endl;
    return 0;
}