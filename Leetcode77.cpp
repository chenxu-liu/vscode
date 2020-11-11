class Solution {
private:
    vector<int> v;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n,k,1);
        return ans;
    }
    void backtrack(int n,int k,int start){
        if(v.size() == k){
            ans.push_back(v);
        }
        for(int i = start; i <= n; i++){
            v.push_back(i);
            backtrack(n,k,i+1);
            v.pop_back();
        }
    }
};