class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<pair<int, char>> path, start_path, dest_path;
        function<void(TreeNode*, char)> dfs = [&](auto cur, auto d) {
            path.push_back({cur->val, d});

            if(cur->val == startValue) start_path = path;
            if(cur->val == destValue) dest_path = path;
            if(cur->left) dfs(cur->left, 'L');
            if(cur->right) dfs(cur->right, 'R');
            
            path.pop_back();
        };
        
        dfs(root, ' ');
        
        int i = 0, n = start_path.size(), m = dest_path.size();
        while(i < min(n, m) && start_path[i].first == dest_path[i].first)
            ++i;
        
        auto ret = string(n - i, 'U');
        while(i < m)
            ret.push_back(dest_path[i++].second);

        return ret;
    }
};
