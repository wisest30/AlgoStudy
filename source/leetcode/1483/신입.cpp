class TreeAncestor {
public:
    int sparseTable[20][50000+5];
    
    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<n;i++) sparseTable[0][i] = parent[i];
        for(int i=1;i<20;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(sparseTable[i-1][j] == -1) sparseTable[i][j] = -1;
                else sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(k == 0) return node;
        if(node == -1) return -1;
        
        int targetNum = 1;
        int targetIdx = 0;
        
        while(targetNum <= k)
        {
            targetNum*=2;
            targetIdx++;
        }
        targetNum/=2;
        targetIdx--;
        
        return getKthAncestor(sparseTable[targetIdx][node], k-targetNum);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
