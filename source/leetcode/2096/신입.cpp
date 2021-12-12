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
    unordered_map<TreeNode*, TreeNode*> parent;
    bool visit[1'00000+5];
    string route;
    
    void dfs(TreeNode* cur, TreeNode* prv)
    {
        if(cur == NULL) return;
        parent[cur] = prv;
        dfs(cur->left, cur);
        dfs(cur->right, cur);
    }
    
    TreeNode* find(TreeNode* cur, int val)
    {
        if(cur == NULL) return NULL;
        
        visit[cur->val] = true;
        if(cur->val == val) return cur;
        
        if(parent[cur] && !visit[parent[cur]->val]) 
        {
            TreeNode* res = find(parent[cur], val);
            if(res)
            {
                route.push_back('U');
                return res;
            }
        }
        
        if(cur->left && !visit[cur->left->val])
        {
            TreeNode* res = find(cur->left, val);
            if(res) 
            {
                route.push_back('L');
                return res;
            }
        }
        
        if(cur->right && !visit[cur->right->val])
        {
            TreeNode* res = find(cur->right, val);
            if(res) 
            {
                route.push_back('R');
                return res;
            }
        }
        
        return NULL;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        dfs(root, NULL);
        
        TreeNode* startNode = find(root, startValue);
        route.clear();
        memset(visit, 0, sizeof(visit));
        
        find(startNode, destValue);
        reverse(route.begin(), route.end());
        
        return route;
    }
};
