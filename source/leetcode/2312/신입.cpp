typedef long long ll;

class Solution {
public:
    ll memo[200+5][200+5];
    bool visit[200+5][200+5];
    
    ll getMemo(int r, int c)
    {
        ll &ret = memo[r][c];
        
        if(visit[r][c]) return ret;
        
        visit[r][c] = true;
        if(ret == -1) ret = 0;
        
        for(int i=1;i<=r-1;i++) 
            ret = max(ret, getMemo(i, c) + getMemo(r-i, c));    
        
        for(int i=1;i<=c-1;i++)
            ret = max(ret, getMemo(r, i) + getMemo(r, c-i));
        
        return ret;
    }
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(memo, -1, sizeof(memo));
        for(auto &price : prices) memo[price[0]][price[1]] = price[2];
        return getMemo(m, n);
    }
};
