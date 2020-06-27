class TreeAncestor {
public:
    static constexpr int MAX_N = 20;
    vector<int> P[MAX_N];
    TreeAncestor(int n, vector<int>& parent) {
        P[0] = parent;
        for(auto i = 1; i < MAX_N; ++i) {
            P[i].resize(parent.size());
            for(auto j = 0; j < P[i].size(); ++j)
                P[i][j] = P[i-1][j] == -1 ? -1:P[i-1][P[i-1][j]];
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(node == -1 || !k) return node;
        for(auto i = 0; i < MAX_N; ++i)
            if((1 << i) > k)
                return getKthAncestor(P[i-1][node], k - (1 << (i-1)));
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
