struct player
{
    int score;
    int age;
};

bool operator<(const player &a, const player &b)
{
    if(a.age != b.age) return a.age < b.age;
    return a.score < b.score;
}

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<player> players;
        vector<int> maxSum;
        int ans = 1;
        
        for(int i=0;i<scores.size();i++) players.push_back({scores[i], ages[i]});
        sort(players.begin(), players.end());
        
        maxSum = vector<int>(players.size(), 0);
        
        for(int i=0;i<players.size();i++)
        {
            int localMax = 0;
            
            for(int j=i-1;j>=0;--j)
            {
                if(players[j].score <= players[i].score)
                {
                    localMax = max(localMax, maxSum[j]);
                }
            }
            
            maxSum[i] = localMax + players[i].score;
            
            ans = max(ans, maxSum[i]);
        }
        
        return ans;
    }
};
