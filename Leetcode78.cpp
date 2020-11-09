class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(nums,path,0);
        return res;
    }
    void backtrack(vector<int>nums,vector<int>&path,int start)
    {
            res.push_back(path);
            for(int i=start;i<nums.size();i++)
            {
                path.push_back(nums[i]);//做出选择
                backtrack(nums,path,i+1);//递归进入下一层，注意i+1，标识下一个选择列表的开始位置，最重要的一步
                path.pop_back();//撤销选择
            }
    }
};