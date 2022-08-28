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
    vector<int> adj[1'00000+5];
    int ans;
    
    void buildAdj(TreeNode* root, int parent)
    {
        if(root == NULL) return;
        if(parent != -1) 
        {
            adj[root->val].push_back(parent);
            adj[parent].push_back(root->val);
        }
        buildAdj(root->left, root->val);
        buildAdj(root->right, root->val);
    }
    
    void dfs(int cur, int parent, int depth)
    {
        ans = max(ans, depth);
        
        for(auto &nxt : adj[cur])
        {
            if(nxt == parent) continue;
            dfs(nxt, cur, depth+1);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        buildAdj(root, -1);
        dfs(start, -1, 0);
        return ans;
    }
};
