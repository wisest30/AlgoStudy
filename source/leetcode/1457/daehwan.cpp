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
    int pseudoPalindromicPaths (TreeNode* r) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* r, int b)->int{
            if(r == nullptr) return 0;
            b ^= (1<<(r->val));
            if(r->left==nullptr && r->right==nullptr){
                //leaf node
                int cnt = __builtin_popcount(b);
                if(cnt <= 1) return 1;
                else return 0;
            }
            int ret = 0;
            if(r->left != nullptr) ret += dfs(r->left, b);
            if(r->right != nullptr) ret += dfs(r->right, b);
            return ret;
        };
        int ans = dfs(r,0);
        return ans;
    }
};
