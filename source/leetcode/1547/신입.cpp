class Solution {
public:
    int cache[100+5][100+5];
    
    int getCache(vector<int>& intervals, int l, int r)
    {
        if(cache[l][r] != -1) return cache[l][r];
        if(l == r) return cache[l][r] = 0;
        
        int total = intervals[r];
        int& ret = cache[l][r] = INT_MAX;
        
        for(int i=l;i<r;i++)
        {
            total += intervals[i];
            ret = min(ret, getCache(intervals, l, i) + getCache(intervals, i+1, r));
        }
        
        ret += total;
        
        return ret;
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> intervals;
        
        int before = 0;
        for(int i=0;i<cuts.size();i++)
        {
            intervals.push_back(cuts[i] - before);
            before = cuts[i];
        }
        intervals.push_back(n - before);
        
        memset(cache, -1, sizeof(cache));
        return getCache(intervals, 0, (int)intervals.size()-1);
    }
};
