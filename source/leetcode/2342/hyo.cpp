class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, int> m;
        int ret = -1;
        for(auto num : nums) {
            int key = 0;
            for(auto c : to_string(num))
                key += c - '0';
            
            if(m.count(key))
                ret = max(ret, m[key] + num);
            
            m[key] = max(m[key], num);
        }
        
        return ret;
    }
};
