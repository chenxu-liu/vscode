class Solution {
private:
    string ans;
    vector<string> fin;
public:
    vector<string> permutation(string S) {
        sort(S.begin(),S.end());
        int visited[S.size()];
        memset(visited,0,S.size());
        backtrack(S,ans,visited);
        return fin;
    }
    void backtrack(string &S,string &ans,int visited[]){
        if(ans.size() == S.size()){
            fin.push_back(ans);
            return;
        }
        for(int i = 0; i < S.size(); i++){
            if(visited[i] == 1) continue;
            if(i > 0 && S[i] == S[i - 1] && visited[i - 1] == 0){
                continue;
            }
            visited[i] = 1;
            ans += S[i];
            backtrack(S,ans,visited);
            ans.pop_back();
            visited[i] = 0;
        }
    }
};