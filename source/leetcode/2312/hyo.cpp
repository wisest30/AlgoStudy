class Solution {
public:
    vector<vector<long long>> dp, A;
    
    long long recur(int r, int c) {  
        if(r == 1 && c == 1) // 없어도 되긴 함.
            return A[r][c];

        auto& ret = dp[r][c];        
        if(ret != -1)
            return ret;
        
        ret = A[r][c];
        for(auto i = 1; i < r; ++i)
            ret = max(ret, recur(i, c) + recur(r - i, c));
        for(auto i = 1; i < c; ++i)
            ret = max(ret, recur(r, i) + recur(r, c - i));
        
        return ret;
    }
    
    long long sellingWood(int r, int c, vector<vector<int>>& prices) {
        A = vector<vector<long long>>(r+1, vector<long long>(c + 1));
        dp = vector<vector<long long>>(r+1, vector<long long>(c + 1, -1));
        
        for(auto& p : prices)
            A[p[0]][p[1]] = p[2];
        
        return recur(r, c);
    }
};
