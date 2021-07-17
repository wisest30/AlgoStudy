class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        vector<double> T(n);
        for(auto i = 0; i < n; ++i)
            T[i] = (double)dist[i] / speed[i];
        
        sort(T.begin(), T.end());
        
        int ret = 0, curTime = 0;
        for(auto t : T) {
            if(t <= curTime) break;
            ret++, curTime++;
        }
        
        return ret;
    }
};
