class Solution {
public:
    vector<int> recover(int k, multiset<int>& mset)
    {
        vector<int> res;
        vector<int> removed;
        
        bool fail = false;
        
        for(auto it = mset.begin();it != mset.end();it++)
        {
            res.push_back(*it+k);
            if(!mset.count(*it+2*k)) 
            {
                fail = true;
                break;
            }
            mset.erase(mset.find(*it+2*k));
            removed.push_back(*it+2*k);
        }
        
        for(int num : removed) mset.insert(num);
        
        if(fail) return {};
        return res;
    }
    
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        multiset<int> mset;
        int n = nums.size();
        
        for(int i=0;i<n;i++) mset.insert(nums[i]);
        
        for(int i=1;i<n;i++)
        {
            if((nums[i] - nums[0])%2 || (nums[i]-nums[0]) == 0) continue;
            else
            {
                vector<int> res = recover((nums[i]-nums[0])/2, mset);
                if(!res.empty()) return res;
            }
        }
        
        return {};
    }
};
