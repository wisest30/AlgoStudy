class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), -1);
        set<int> zeroIdx;
        unordered_map<int, int> floodedLakeIdx;
        
        for(int i=0;i<rains.size();++i)
        {
            if(rains[i] == 0) zeroIdx.insert(i);
            else
            {
                if(floodedLakeIdx.find(rains[i]) == floodedLakeIdx.end()) floodedLakeIdx[rains[i]] = i+1;
                else
                {
                    auto it = zeroIdx.lower_bound(floodedLakeIdx[rains[i]]);
                    
                    if(it == zeroIdx.end()) return vector<int>(0);
                    
                    floodedLakeIdx[rains[i]] = i+1;
                    ans[*it] = rains[i];
                    zeroIdx.erase(it);
                }
            }
        }
        
        for(int idx : zeroIdx) ans[idx] = 1;
        
        return ans;
    }
};
