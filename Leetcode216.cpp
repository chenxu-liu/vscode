class Solution {
private:
    vector<int> ans;
    vector<vector<int>> fin;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,ans,0,1,0);
        return fin;
    }
    void backtrack(int k,int n,vector<int> &ans,int flag,int start,int sum){
        if(flag == k){
            if(sum == n)
            fin.push_back(ans);
            return;
        }
        for(int i = start; i <= 9; i++){
            ans.push_back(i);
            flag++;
            sum += i;
            backtrack(k,n,ans,flag,i+1,sum);
            ans.pop_back();
            flag--;
            sum -= i;

        }
    }
};