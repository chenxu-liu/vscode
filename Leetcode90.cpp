class Solution {
private:
    vector<int> v;
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,v,0);
        return res;
    }
    void backtrack(vector<int> &nums,vector<int> v,int start){
        res.push_back(v);
        for(int i = start; i < nums.size(); i++){
            if(start<i && nums[i] == nums[i-1]){
                continue;
            }
            v.push_back(nums[i]);
            backtrack(nums,v,i+1);
            v.pop_back();
        }   
    }
};