class Solution {
public:
    vector<vector<TreeNode*>> A;
    void dfs(TreeNode* cur, int lv) {
        if(!cur) return;
        
        if(A.size() == lv) A.push_back({});
        A[lv].push_back(cur);
        
        dfs(cur->left, lv + 1);
        dfs(cur->right, lv + 1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root, 0);
        for(auto i = 1; i < A.size(); i += 2)
            for(auto j = 0; j < A[i].size() / 2; ++j)
                swap(A[i][j]->val, A[i][(int)A[i].size() - 1 - j]->val);
        
        return root;
    }
};
