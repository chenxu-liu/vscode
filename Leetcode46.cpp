class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        int visited[nums.size()];
        backtrack(nums,v,visited);
        return ans;
    }
    void backtrack(vector<int> & nums, vector<int>& v,int visited[]){
        //终止条件
        if(nums.size() == v.size()){
            ans.push_back(v);
            return;
        }
        //递归过程
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1){
                continue;
            }
            v.push_back(nums[i]);
            visited[i] = 1;
            backtrack(nums,v,visited);
            v.pop_back();
            visited[i] = 0;
        }
    }
};