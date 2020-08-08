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
typedef TreeNode t;
class Solution {
public:
    int countPairs(t* root, int d) {
        
        int ans = 0;
        function<vector<int>(t*)> dfs = [&](t* root){
            if(root==nullptr) return vector<int>(0);
            if(root->left==nullptr && root->right==nullptr) return vector<int>(1,1); //leaf
            vector<int> l = dfs(root->left);
            vector<int> r = dfs(root->right);
            for(auto& i : l) for(auto& j : r) if(i+j<=d) ans++;
            vector<int> ret;
            for(auto& i : l) ret.push_back(i+1);
            for(auto& j : r) ret.push_back(j+1);
            return ret;
        };
        dfs(root);
        return ans;
    }
};
