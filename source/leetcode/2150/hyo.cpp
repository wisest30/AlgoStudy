class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int> m;
        for(auto num : nums) m[num]++;
        
        vector<int> ret;
        for(auto num : nums)
            if(m[num] == 1 && !m[num+1] && !m[num-1])
                ret.push_back(num);

        return ret;
    }
};
