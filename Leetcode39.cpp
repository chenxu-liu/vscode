class Solution {
private:
    vector<int> v;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0);
        return ans;
        
    }
    void backtrack(vector<int> &candidates, int target, int start){
        if(target < 0){
            return ;
        }
        if(target == 0){
            ans.push_back(v);
        }
        for(int i = start; i < candidates.size(); i++){
            target -= candidates[i];
            v.push_back(candidates[i]);
            backtrack(candidates,target,i);
            target += candidates[i];
            v.pop_back();
        }
    }
};