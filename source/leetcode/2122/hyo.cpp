class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<int> K;
        for(auto i = 1; i < n; ++i) {
            if(nums[i] > nums[0] && nums[i] % 2 == nums[0] % 2)
                K.insert((nums[i] - nums[0]) / 2);
        }
        
        map<int, int> C;
        for(auto num : nums)
            C[num]++;

        for(auto k : K) {
            vector<int> ret;
            auto cnts = C;
            bool valid = true;
            for(auto& p : cnts) {
                while(p.second) {
                    if(!cnts[p.first + 2 * k]) {
                        valid = false;
                        break;
                    }
                    
                    p.second--;
                    cnts[p.first + 2 * k]--;
                    ret.push_back(p.first + k);
                }
                
                if(!valid)
                    break;
            }

            if(valid)
                return ret;
        }
        return {};
    }
};
