struct memoType
{
    int Bob;
    int Alice;
};

class Solution {
public:
    int cumSum[1000+5]{};
    bool visit[1000+5][1000+5][2];
    memoType memo[1000+5][1000+5][2];
    
    memoType getMemo(vector<int>& stones, int st, int ed, int whoStart)
    {
        if(ed < 0 || st >= stones.size() || st > ed) return {0, 0};
        
        if(visit[st][ed][whoStart]) return memo[st][ed][whoStart];
        visit[st][ed][whoStart] = true;
        
        memoType &ret = memo[st][ed][whoStart];
        
        memoType leftRes = getMemo(stones, st+1, ed, 1-whoStart);
        memoType rightRes = getMemo(stones, st, ed-1, 1-whoStart);
        
        // when whoStart is 0, Alice starts.
        if(whoStart == 0)
        {
            leftRes.Alice += cumSum[ed+1] - cumSum[st+1];
            rightRes.Alice += cumSum[ed] - cumSum[st];
            
            /*
            printf("Alice starts, [%d,%d]\n", st, ed);
            printf("leftRes : Alice : %d, Bob : %d\n", leftRes.Alice, leftRes.Bob);
            printf("rightRes : Alice : %d, Bob : %d\n\n", rightRes.Alice, rightRes.Bob);
            */
            
            if(abs(leftRes.Alice - leftRes.Bob) > abs(rightRes.Alice - rightRes.Bob)) return ret = leftRes;
            return ret = rightRes;
        }
        
        // Bob starts.
        leftRes.Bob += cumSum[ed+1] - cumSum[st+1];
        rightRes.Bob += cumSum[ed] - cumSum[st];
        
        /*
        printf("Bob starts, [%d,%d]\n", st, ed);
        printf("leftRes : Alice : %d, Bob : %d\n", leftRes.Alice, leftRes.Bob);
        printf("rightRes : Alice : %d, Bob : %d\n\n", rightRes.Alice, rightRes.Bob);
        */
        
        if(abs(leftRes.Alice - leftRes.Bob) > abs(rightRes.Alice - rightRes.Bob)) return ret = leftRes;
        return ret = rightRes;
    }
    
    int stoneGameVII(vector<int>& stones) {
        memset(visit, 0, sizeof(visit));
        cumSum[0] = 0;
        
        for(int i=0;i<stones.size();i++) cumSum[i+1] = cumSum[i] + stones[i];
        
        memoType res = getMemo(stones, 0, (int)stones.size()-1, 0);
        printf("%d %d\n", res.Alice, res.Bob);
        
        return abs(res.Alice - res.Bob);
    }
};
