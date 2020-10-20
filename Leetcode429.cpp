/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        vector<vector<int>> v;
        q.push(root);
        //v.push_back({root->val});
        if(root == nullptr) return v;
        while(!q.empty()){
            int s = q.size();
            vector<int> vec;
            for(int i = 0; i < s; i++){
                Node * node = q.front();
                vec.push_back(node->val);
                q.pop();
                if(node->children.size() != 0){
                    int ss = node->children.size();
                    for(int i = 0; i < ss; i++){
                        q.push(node->children[i]);
                    }
                } 
            }
            v.push_back(vec);
        }
        return v;
    }
};