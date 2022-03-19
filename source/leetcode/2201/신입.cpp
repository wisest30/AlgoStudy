class Solution {
public:
    int prefixSum[1000+5][1000+5];
    
    int getTotalD(int r1, int c1, int r2, int c2)
    {
        return prefixSum[r2][c2] - prefixSum[r2][c1-1] - prefixSum[r1-1][c2] + prefixSum[r1-1][c1-1]; 
    }
    
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        for(auto& thisDig : dig) prefixSum[thisDig[0]+1][thisDig[1]+1] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + prefixSum[i][j];
            }
        }
        
        int ans = 0;
        
        for(auto& artifact : artifacts)
        {
            int total = getTotalD(artifact[0]+1, artifact[1]+1, artifact[2]+1, artifact[3]+1);
            if(total == (artifact[2] - artifact[0] + 1) * (artifact[3] - artifact[1] + 1)) ans++;
        }
        
        return ans;
    }
};
