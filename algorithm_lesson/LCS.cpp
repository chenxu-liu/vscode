#include<iostream>
#include<ctime>
#include<string>
using namespace std;
string s,s2;
int dp[10005][10005];
int longestCommonSubsequence(string text1, string text2) {
        //int dp[text1.size()+5][text1.size()+5];
        for(int i = 0; i < text1.size(); i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i < text2.size(); i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
}
int main(){
    int n;
    int f;
    char x;
    srand(time(0));
    cout << "输入数据规模:";
    cin >> n;
   /// string s,s2;
    for(int i = 0; i < n; i++){
        f=rand()%2;
        if(f==1) {
             x = rand()%('Z'-'A'+1)+'A';
        }else{
             x = rand()%('z'-'a'+1)+'a'; 
        }
        //s[i] = x;
        s += x;
    }
    for(int j = 0; j < n; j++){
        f=rand()%2;
        if(f==1) {
             x = rand()%('Z'-'A'+1)+'A';
        }else{
             x = rand()%('z'-'a'+1)+'a'; 
        }
         s2 += x;
    }
    //cout << s <<" "<< s2 << endl;
    cout << longestCommonSubsequence(s,s2) << endl;
    return 0;
}