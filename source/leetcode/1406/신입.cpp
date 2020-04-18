class Solution {
public:
    bool visit[50000+5]{};
    int memo[50000+5]{};
    int sum[50000+5]{};
    
    int dp(int idx, vector<int>& stoneValue)
    {
        if(idx == stoneValue.size()) return 0;
        if(visit[idx]) return memo[idx];
        int cur_sum = 0;
        
        memo[idx] = -50000000-5;
        visit[idx] = true;
        
        for(int i=0;i<3;++i)
        {
            if(idx + i >= stoneValue.size()) break;
            cur_sum += stoneValue[idx+i];
            int temp = cur_sum + sum[idx+i+1] - dp(idx+i+1, stoneValue);
            if(temp > memo[idx]) memo[idx] = temp;
        }
        
        return memo[idx];
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        for(int i=(int)stoneValue.size()-1;i>=0;--i) sum[i] = sum[i+1] + stoneValue[i];
        dp(0, stoneValue);
        if(memo[0] > sum[0] - memo[0]) return "Alice";
        else if(memo[0] == sum[0]-memo[0]) return "Tie";
        return "Bob";
    }
};
