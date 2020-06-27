class TreeAncestor {
public:
    vector<vector<int>> ancestor;
    TreeAncestor(int n, vector<int>& parent) {
        ancestor.resize(20, vector<int>(parent.size(), -1));
        
        for(int i = 0; i < parent.size(); ++i)
            ancestor[0][i] = parent[i];
        
        for(int i = 1; i < 20; i++){
            for(int node = 0; node < parent.size(); node++){
                int nodeAncestor = ancestor[i-1][node];
                if( nodeAncestor != -1)
                    ancestor[i][node] = ancestor[i-1][nodeAncestor];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; i++){
            if(k & (1 << i)){
                node = ancestor[i][node];
                if(node == -1)
                    return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int
