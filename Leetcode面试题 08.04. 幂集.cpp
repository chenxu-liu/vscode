class Solution {
private:
    vector<int> v;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,v,0);
        return ans;
    }
    void backtrack(vector<int> &nums, vector<int> v, int k){
        ans.push_back(v);
        for(int i = k; i < nums.size(); i++){
            v.push_back(nums[i]);
            backtrack(nums,v,i+1);
            v.pop_back();
        }
    }
};