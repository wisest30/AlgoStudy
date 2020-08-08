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
    int ans, d;
    vector<int> dfs(TreeNode* cur) {
        auto ret = vector<int>(20);
        if(!cur->left && !cur->right) {
            ret[0]++;
            return ret;
        }
        
        auto sub_ret1 = vector<int>(20);
        auto sub_ret2 = sub_ret1;
        if(cur->left) {
            sub_ret1 = dfs(cur->left);
            for(auto i = 0; i < 15; ++i) {
                ret[i+1] += sub_ret1[i];
            }
        }
        if(cur->right) {
            sub_ret2 = dfs(cur->right);
            for(auto i = 0; i < 15; ++i) {
                ret[i+1] += sub_ret2[i];
            }
        }
        
        for(auto i = 0; i <= d; ++i) {
            for(auto j = 0; j <= d; ++j) {
                if(i + j + 2 <= d) ans += sub_ret1[i] * sub_ret2[j];
            }
        }
        return ret;
    }

    int countPairs(TreeNode* root, int distance) {
        if(!root) return 0;
        ans = 0;
        this->d = distance;
        dfs(root);
        return ans;
    }
};
