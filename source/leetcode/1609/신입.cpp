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
    vector<int> val[1'00000+5];
    
    void mkVal(TreeNode* root, int level)
    {
        if(root == NULL) return;
        val[level].push_back(root->val);
        mkVal(root->left, level+1);
        mkVal(root->right, level+1);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        
        mkVal(root, 0);
        
        for(int i=0;i<1'00000;i++)
        {
            int before = 0;
            if(i%2 == 1) before = INT_MAX;
            
            for(int j=0;j<val[i].size();j++)
            {
                if(val[i][j]%2 == i%2) return false;
                if(i%2 == 0 && before >= val[i][j]) return false;
                if(i%2 == 1 && before <= val[i][j]) return false;
                before = val[i][j];
                
                //printf("%d ", val[i][j]);
            }
            
            //if(!val[i].empty()) printf("\n");
        }
        return true;
    }
};
