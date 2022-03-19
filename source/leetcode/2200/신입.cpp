class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> idxes;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == key)
            {
                for(int j=max(i-k, 0);j<=min(i+k,(int)nums.size()-1);j++) idxes.insert(j);
            }
        }
        
        vector<int> ans;
        
        for(auto it=idxes.begin();it!=idxes.end();it++) ans.push_back(*it);
        
        return ans;
    }
};
