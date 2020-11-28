class Solution {
private:
    vector<int> ans;
    vector<vector<int>> fin;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size() == 0){
            return fin;
        }
        backtrack({0},graph,0);
        return fin;
    }
    void backtrack(vector<int> ans,vector<vector<int>> &graph,int x){
        if(ans.back() == graph.size()-1){
            fin.push_back(ans);
            return;
        }
        for(int i = 0; i < graph[x].size(); i++){
            ans.push_back(graph[x][i]);
            backtrack(ans,graph,graph[x][i]);
            ans.pop_back();   
        }
        return;
    }
};