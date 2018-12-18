#include "vector"
#include "queue"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
    
    void dfs(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return;
        if (level == res.size()) res.push_back({});
        res[level].push_back(root->val);
        dfs(root->left, level+1, res);
        dfs(root->right, level+1, res);
    }
};
class Solution_iterative {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp; 
            for (int i = 0; i < size; ++i) {
                auto pop = q.front();
                q.pop();
                tmp.emplace_back(pop->val);
                if (pop->left) q.push(pop->left);
                if (pop->right) q.push(pop->right);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
