class Solution {
public:
    long long combination[50][50];
    int cnt[8];
    int totalBalls;
    long long ans;
    
    void init(vector<int>& balls)
    {
        ans = 0LL;
        totalBalls = 0;
        for(int ball : balls) totalBalls += ball;
        
        combination[0][0] = 1;
        for(int i=1;i<=48;++i)
        {
            combination[i][0] = 1;
            combination[i][i] = 1;
            
            for(int j=1;j<i;++j)
            {
                combination[i][j] = combination[i-1][j] + combination[i-1][j-1];
            }
        }
    }
    
    void mk(vector<int>& balls, int idx, int cur)
    {
        if(idx == balls.size())
        {
            if(cur != totalBalls/2) return;
            
            int otherColors = 0;
            int colors = 0;
            
            for(int i=0;i<balls.size();++i) 
            {
                if(cnt[i] > 0) colors++;
                if(balls[i] - cnt[i] > 0) otherColors++;
            }
            
            if(otherColors != colors) return;
            
            long long totalCount = 1LL;
            
            for(int i=0;i<balls.size();++i)
            {
                totalCount *= combination[balls[i]][cnt[i]];    
            }
            
            ans += totalCount;
            return;
        }
        
        for(int i=0;i<=balls[idx];++i)
        {
            cnt[idx] = i;
            mk(balls, idx+1, cur + i);
        }
    }
    
    double getProbability(vector<int>& balls) {
        init(balls);
        mk(balls, 0, 0);
        return (double)ans/combination[totalBalls][totalBalls/2];
    }
};
