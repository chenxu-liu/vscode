class Solution {
private:
    vector<vector<string>> s;
public:
    vector<vector<string>> solveNQueens(int n) {
        int visited[n+5];
        vector<int> ans;
        backtrack(visited,ans,n);
        return s;
    }
    void backtrack(int visited[], vector<int>& ans,int n){
        if(ans.size() == n){
            judgement(ans,n);
            return ;
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 1){
                continue;
            }
            ans.push_back(i);
            visited[i] = 1;
            backtrack(visited,ans,n);
            ans.pop_back();
            visited[i] = 0;
        }
    }
    void judgement(vector<int> & ans,int n){
        vector<string> temp;
        string t;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(abs(i - j) == abs(ans[i] - ans[j])){
                    return;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == ans[i]){
                    t+="Q";   
                }else{
                    t+=".";
                }
            }
             temp.push_back(t);
             t.clear();
        }
        s.push_back(temp);
    }
};