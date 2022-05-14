class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* cur) {
            if(!cur)
                return make_pair(0, 0);
            
            auto cnt = 1;
            auto su = cur->val;
            
            auto sub_ret = dfs(cur->left);
            cnt += sub_ret.first, su += sub_ret.second;
            
            sub_ret = dfs(cur->right);
            cnt += sub_ret.first, su += sub_ret.second;
            
            if(su / cnt == cur->val)
                ans++;
            
            return make_pair(cnt, su);
        };
        
        dfs(root);
        
        return ans;
    }
};
