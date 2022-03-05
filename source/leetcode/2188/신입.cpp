typedef long long ll;

class Solution {
public:
    ll minLapTime[1000+5];
    
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        for(int i=1;i<=numLaps;i++) minLapTime[i] = INT_MAX;
        for(auto &tire : tires)
        {
            int f = tire[0], r = tire[1];
            ll mul = f;
            ll sum = 0;
            
            for(int i=1;i<=min(numLaps, 32);i++)
            {
                sum += mul;
                if(sum >= INT_MAX) break;
                minLapTime[i] = min(minLapTime[i], sum);
                mul *= r;
            }
        }
        
        for(int i=2;i<=numLaps;i++)
        {
            for(int j=1;j<=i-1;j++)
            {
                minLapTime[i] = min(minLapTime[i], minLapTime[j] + changeTime + minLapTime[i-j]);
            }
        }
        
        //for(int i=1;i<=numLaps;i++) cout << minLapTime[i] << "\n";
        
        return minLapTime[numLaps];
    }
};
