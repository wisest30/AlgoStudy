class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_map<int, int> indeg;
        for(auto& d : descriptions) {
            if(!m.count(d[0]))
                m[d[0]] = new TreeNode(d[0]);
            if(!m.count(d[1]))
                m[d[1]] = new TreeNode(d[1]);
            
            if(d[2])
                m[d[0]]->left = m[d[1]];
            else
                m[d[0]]->right = m[d[1]];
            
            indeg[d[0]];
            indeg[d[1]]++;
        }
        
        for(auto& p : indeg) {
            if(!p.second)
                return m[p.first];
        }
        
        return nullptr;
    }
};
