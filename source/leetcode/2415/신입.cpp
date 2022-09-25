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
class Solution {
public:
    static constexpr size_t MAXN = (1 << 14) + 5;
    
    vector<int> val[MAXN];
    
    void getVal(TreeNode* root, int depth)
    {
        if(root == NULL) return;
        
        if(depth%2) val[depth].push_back(root->val);
        
        getVal(root->left, depth+1);
        getVal(root->right, depth+1);
    }
    
    void changeVal(TreeNode* root, int depth)
    {
        if(root == NULL) return;
        
        if(depth%2)
        {
            root->val = val[depth].back();
            val[depth].pop_back();
        }
        
        changeVal(root->left, depth+1);
        changeVal(root->right, depth+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        getVal(root, 0);
        changeVal(root, 0);
        
        return root;
    }
};
