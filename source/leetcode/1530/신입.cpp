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
    map<TreeNode*, map<int, int>> distanceMap;
    int ans;
    
    void dfs(TreeNode* root, int distance)
    {
        if(root->left) 
        {
            dfs(root->left, distance);
            for(auto it = distanceMap[root->left].begin();it != distanceMap[root->left].end();it++)
            {
                distanceMap[root][it->first + 1] += it->second; 
            }
        }
        
        if(root->right) 
        {
            dfs(root->right, distance);
            for(auto it = distanceMap[root->right].begin();it != distanceMap[root->right].end();it++)
            {
                distanceMap[root][it->first + 1] += it->second; 
            }
        }
        
        if(root->left && root->right)
        {
            for(int leftDist=1;leftDist<distance;leftDist++)
            {
                for(int rightDist=1;leftDist+rightDist<=distance;rightDist++)
                {
                    ans += distanceMap[root->left][leftDist-1] * distanceMap[root->right][rightDist-1];
                }
            }
        }
        
        else if(!root->left && !root->right) distanceMap[root][0] = 1;
       // printf("%d %d %d %d\n", root->val, distanceMap[root][0], distanceMap[root][1], distanceMap[root][2]);
    }
    
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        dfs(root, distance);
        return ans;
    }
};
