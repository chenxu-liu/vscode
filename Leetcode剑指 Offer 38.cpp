class Solution {
private:
    vector<string> ans;
    string fin;
public:
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        int visited[s.size()];
        backbrack(s,visited,fin);
        return ans;
    }
    void backbrack(string &s,int visited[],string & fin){
        if(fin.size() == s.size()){
            ans.push_back(fin);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            if(visited[i] == 1 || (i> 0 && s[i] == s[i-1] && visited[i-1] == 1)){
                continue;
            }
            fin.push_back(s[i]);
            visited[i] = 1;
            backbrack(s,visited,fin);
            fin.pop_back();
            visited[i] = 0;
        }
    }
};