class Solution {
private:
    string s;
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        backtrack(s,0,0,n);
        return ans;
    }
    void backtrack(string &s,int left,int right,int n){
        if(left == n && right == n){
            ans.push_back(s);
            return ;
        }
        if(left < n){
            s += "(";
            backtrack(s,left+1,right,n);
            s.pop_back();
        }
        if(right < left){
            s += ")";
            backtrack(s,left,right+1,n);
            s.pop_back();
        }
    }
};