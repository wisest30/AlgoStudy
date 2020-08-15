typedef long long ll;

class Solution {
public:
    const ll mod = 1'000'000'007LL;
    
    ll cache[2][100000+5];
    vector<int> newNums[2];
    unordered_map<int, int> numPos[2];
    
    ll getCache(int r, int c)
    {
        if(cache[r][c] != -1) return cache[r][c];
        
        int val = newNums[r][c];
        ll& ret = cache[r][c];
        ret = 0;
        
        if(numPos[1-r].find(val) != numPos[1-r].end()) ret = max(ret, val + getCache(1-r, numPos[1-r][val]-1));
        ret = max(ret, val + getCache(r, c-1));
        
        return ret;
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        newNums[0].push_back(0);
        newNums[1].push_back(0);
        
        memset(cache, -1, sizeof(cache));
        cache[0][0] = cache[1][0] = 0;
        
        for(int i=0;i<nums1.size();i++) 
        {
            numPos[0][nums1[i]] = i+1;
            newNums[0].push_back(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            numPos[1][nums2[i]] = i+1;
            newNums[1].push_back(nums2[i]);
        }
        
        ll ans = max(getCache(0, nums1.size()),
                    getCache(1, nums2.size()));
        
        return ans%mod;
    }
};
