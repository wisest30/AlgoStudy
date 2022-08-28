class Solution {
public:
    void treenode_dfs(TreeNode* cur, vector<vector<int>>& g) {
        if(!cur)
            return;
        
        if(cur->left) {
            g[cur->val].push_back(cur->left->val);
            g[cur->left->val].push_back(cur->val);
            treenode_dfs(cur->left, g);
        }
        
        if(cur->right) {
            g[cur->val].push_back(cur->right->val);
            g[cur->right->val].push_back(cur->val);
            treenode_dfs(cur->right, g);
        }
    }
    
    int g_dfs(int cur, int prev, const vector<vector<int>>& g) {
        int ret = 0;
        
        for(auto nxt: g[cur])
            if(nxt != prev)
                ret = max(ret, g_dfs(nxt, cur, g) + 1);
        
        return ret;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        auto g = vector<vector<int>>(100001);
        treenode_dfs(root, g);
        
        return g_dfs(start, -1, g);
    }
};
