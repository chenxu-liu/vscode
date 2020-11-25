class Solution {
private:
    vector<string> ans;
public:
    vector<string> permutation(string S) {
        string s;
        int visited[S.size()];
        backtrack(s,S,visited);
        return ans;
    }
    void backtrack(string &s,string &S,int visited[]){
        if(s.size() == S.size()){
            ans.push_back(s);
            return ;
        }
        for(int i = 0; i < S.size(); i++){
            if(visited[i] == 1){
                continue;
            }
            s += S[i];
            visited[i] = 1;
            backtrack(s,S,visited);
            visited[i] = 0;
            s.pop_back();
        }
    }
};