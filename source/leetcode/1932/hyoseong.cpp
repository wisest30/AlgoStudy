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
    map<int, TreeNode*> val_to_ptr;
    set<int> visited;
    int merge_count;
    bool valid;
    
    array<int, 2> dfs(TreeNode* cur) {
        if(visited.count(cur->val))
            return {0, 0};
        visited.insert(cur->val);

        array<int, 2> ret;
        ret[0] = ret[1] = cur->val;
        
        for(auto i = 0; i < 2; ++i) {
            auto& p = i == 0 ? cur->left : cur->right;
            if(p && val_to_ptr.count(p->val))
                p = val_to_ptr[p->val], merge_count++;
            
            if(p) {
                auto sub_ret = dfs(p);
                ret[0] = min(ret[0], sub_ret[0]);
                ret[1] = max(ret[1], sub_ret[1]);
                
                if(i == 0 && cur->val < sub_ret[1])
                    valid = false;
                if(i == 1 && cur->val > sub_ret[0])
                    valid = false;
            }
        }
        
        return ret;
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        valid = true;
        merge_count = 0;
        set<int> leaf_values;
        for(auto p : trees) {
            val_to_ptr[p->val] = p;
            if(p->left) leaf_values.insert(p->left->val);
            if(p->right) leaf_values.insert(p->right->val);
        }
        
        TreeNode* root = nullptr;
        for(auto p : trees) {
            if(leaf_values.count(p->val) == 0) {
                if(root) return nullptr;
                root = p;
            }
        }
        
        if(!root) return nullptr;
        
        dfs(root);
        if(!valid || merge_count + 1 < trees.size())
            return nullptr;
        else
            return root;
    }
};
