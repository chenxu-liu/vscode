/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int max_sum = INT_MIN;
        int sum = 0,final_num = 0,next_num;
        while(!q.empty()){
            int s = q.size();
             final_num++;
             sum = 0;
            for(int i = 0; i < s; i++){
                TreeNode * node = q.front();
                q.pop();
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
                sum += node->val;

            }
            if(sum > max_sum){
                max_sum = sum;
                next_num = final_num;
            }
        }
        return next_num;
    }
};