struct entity
{
    int idx;
    int val;
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<entity> dq;
        dq.push_front({0, nums[0]});
        
        for(int i=1;i<nums.size();i++)
        {
            while(!dq.empty() && dq.front().idx < i-k) dq.pop_front();
            
            int curAns = dq.front().val + nums[i];
            while(!dq.empty() && dq.back().val <= curAns) dq.pop_back();
            dq.push_back({i, curAns});
        }
        
        return dq.back().val;
    }
};
