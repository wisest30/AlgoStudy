class Solution {
public:
    map<pair<int, int>, int> intersection;
    int roadCnt[100+5];
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for(auto& road : roads)
        {
            int from = min(road[0], road[1]);
            int to = max(road[0], road[1]);

            roadCnt[from]++;
            roadCnt[to]++;
            intersection[make_pair(from, to)]++;
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int thisVal = roadCnt[i]+roadCnt[j]-intersection[make_pair(i, j)];
                if(thisVal > ans) ans = thisVal;
            }
        }
        
        return ans;
    }
};
