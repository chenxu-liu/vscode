class Solution {
private:
    vector<int> v;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0);
        return ans;
    }
    void backtrack(vector<int> &candidates, int target, int start){
        if(target < 0){
            return ;
        }
        if(target == 0){
            ans.push_back(v);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(start < i && candidates[i] == candidates[i-1]){
                continue;
            }
            target -= candidates[i];
            v.push_back(candidates[i]);
            backtrack(candidates,target,i+1);
            target += candidates[i];
            v.pop_back();
        }
    }
};