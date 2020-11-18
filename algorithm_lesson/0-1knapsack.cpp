/*#include<iostream>
#include<ctime>
using namespace std;

int main(){
    int all, n,w[105],v[105],ans[105][10005];
    srand(time(0));
    //cout << "背包承重：";
    cin >> all;
    //cout << "物品数量：";
    cin >> n;

    for(int i = 1; i <= n; i++){
        w[i] = rand()%10;
        v[i] = rand()%10;
        //cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= all; j++){
            if(w[i] > j){
                ans[i][j] = ans[i-1][j];
            }else{
                ans[i][j] = max(ans[i-1][j], v[i] + ans[i-1][j-w[i]]);
            }
        }
    }
    cout << ans[n][all]<<endl;
    return 0;
}*/
#include <iostream>
#include<ctime>
using namespace std;

int all, n, w[1000005], v[1000005], ans[1000005];

int main() {
    srand(time(0));
    cout << "背包承重：";
    cin >> all;
    cout << "物品数量：";
    cin >> n;

    for(int i = 1; i <= n; i++){
        w[i] = rand()%10;
        v[i] = rand()%10;
        //cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = all; j > 0; j--) { //从后向前
            if (j < w[i]) {
                break;
            } else {
                ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << "w:" << w[i] << " v:" << v[i] << " " ;
    }
    cout << endl;
    cout << "物品的最大价值:"<<ans[all] << endl;
    return 0;
}
