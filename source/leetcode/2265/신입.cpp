/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct retType
{
    int cnt;
    int sum;
};

class Solution {
public:
    int ans;
    
    retType dfs(TreeNode* root)
    {
        if(root == NULL) return {0, 0};
        
        retType leftRes = dfs(root->left);
        retType rightRes = dfs(root->right);
        
        int resCnt = leftRes.cnt + rightRes.cnt + 1;
        int resSum = leftRes.sum + rightRes.sum + root->val;
        
        if(resSum/resCnt == root->val) ans++;
        
        return {resCnt, resSum};
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
