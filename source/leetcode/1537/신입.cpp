class Solution {
public:
    const long long mod = 1'000'000'007;
    long long nums1Cache[100000+5];
    long long nums2Cache[100000+5];
    
    unordered_map<int, int> newNums1Pos;
    unordered_map<int, int> newNums2Pos;
        
    long long getNums1Cache(vector<int>& newNums1, vector<int>& newNums2, int pos)
    {
        if(nums1Cache[pos] != -1) return nums1Cache[pos];
        
        int val = newNums1[pos];
        long long &ret = nums1Cache[pos];
        ret = 0;
        
        if(newNums2Pos.find(val) != newNums2Pos.end()) ret = max(ret, val + getNums2Cache(newNums1, newNums2, newNums2Pos[val] - 1));
        ret = max(ret, val + getNums1Cache(newNums1, newNums2, pos - 1));
        
        return ret;
    }
    
    long long getNums2Cache(vector<int>& newNums1, vector<int>& newNums2, int pos)
    {
        if(nums2Cache[pos] != -1) return nums2Cache[pos];
        
        int val = newNums2[pos];
        long long &ret = nums2Cache[pos];
        ret = 0;
        
        if(newNums1Pos.find(val) != newNums1Pos.end()) ret = max(ret, val + getNums1Cache(newNums1, newNums2, newNums1Pos[val] - 1));
        ret = max(ret, val + getNums2Cache(newNums1, newNums2, pos - 1));
        
        return ret;
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int> newNums1 = {0};
        vector<int> newNums2 = {0};
        
        memset(nums1Cache, -1, sizeof(nums1Cache));
        memset(nums2Cache, -1, sizeof(nums2Cache));
        
        nums1Cache[0] = 0;
        nums2Cache[0] = 0;
        
        for(int i=0;i<nums1.size();i++)
        {
            newNums1Pos[nums1[i]] = i+1;
            newNums1.push_back(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            newNums2Pos[nums2[i]] = i+1;
            newNums2.push_back(nums2[i]);
        }
        
        long long ans = max(getNums1Cache(newNums1, newNums2, (int)newNums1.size()-1),
                  getNums2Cache(newNums1, newNums2, (int)newNums2.size()-1));
        
        return ans%mod;
    }
};
