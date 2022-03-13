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
    unordered_map<int, TreeNode*> valueNodeMap;
    unordered_map<int, int> parentMap;
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for(auto &description : descriptions)
        {
            TreeNode* parent;
            if(valueNodeMap.find(description[0]) == valueNodeMap.end()) 
            {
                parent = new TreeNode(description[0]);
                valueNodeMap[description[0]] = parent;
            }
            parent = valueNodeMap[description[0]];
            
            TreeNode* child;
            if(valueNodeMap.find(description[1]) == valueNodeMap.end()) 
            {
                child = new TreeNode(description[1]);
                valueNodeMap[description[1]] = child;
            }
            child = valueNodeMap[description[1]];
            
            if(description[2] == 1) parent->left = child;
            else parent->right = child;
            
            parentMap[child->val] = parent->val;
        }
        
        int cur = descriptions[0][0];
        
        while(parentMap.find(cur) != parentMap.end()) cur = parentMap[cur];
        
        return valueNodeMap[cur];
    }
};
