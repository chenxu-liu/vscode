class Solution {
private:
    vector<string> ans;
public:
    vector<string> letterCasePermutation(string S) {
        string fin;
        backtrack(S,fin,0);
        return ans;
    }
    void backtrack(string &S, string &fin,int start){
        if(S.size() == fin.size()){
            ans.push_back(fin);
            return;
        }
        for(int i = start; i < S.size(); i++){
            if(isdigit(S[i])){
                fin.push_back(S[i]);
                backtrack(S,fin,i+1);
                fin.pop_back();
            }
            if(isalpha(S[i])){
                fin.push_back(tolower(S[i]));
                backtrack(S,fin,i+1);
                fin.pop_back();

                fin.push_back(toupper(S[i]));
                backtrack(S,fin,i+1);
                fin.pop_back();
            }
        }
    }
};