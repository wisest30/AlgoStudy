class Solution {
public:
    // 1 : Alice, 0 : Bob
    int whoWins(int whoStart, int zeroCnt, int oneCnt, int twoCnt, int selected)
    {
        if(zeroCnt == 0 && oneCnt == 0 && twoCnt == 0) return 0;
        
        if(selected == 1)
        {
            if(oneCnt) return whoWins(1-whoStart, zeroCnt, oneCnt-1, twoCnt, 2);
            else if(zeroCnt) return whoWins(1-whoStart, zeroCnt-1, oneCnt, twoCnt, 1);
            return 1-whoStart;
        }
        else
        {
            if(twoCnt) return whoWins(1-whoStart, zeroCnt, oneCnt, twoCnt-1, 1);
            else if(zeroCnt) return whoWins(1-whoStart, zeroCnt-1, oneCnt, twoCnt, 2);
            return 1-whoStart;
        }
    }
    
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]{};
        for(int stone : stones) cnt[stone%3]++;
        
        if(cnt[1] == 0 && cnt[2] == 0) return false;
        
        int res = 0;
        
        if(cnt[1]) res |= whoWins(0, cnt[0], cnt[1]-1, cnt[2], 1);
        if(cnt[2]) res |= whoWins(0, cnt[0], cnt[1], cnt[2]-1, 2);
        
        return res;
    }
};
