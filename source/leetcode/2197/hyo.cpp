class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ret;
        auto adjust = [&] {
            while(ret.size() >= 2) {
                auto i = (int)ret.size() - 2, j = (int)ret.size() - 1;
                auto g = __gcd(ret[i], ret[j]);
                if(g > 1) {
                    auto new_val = (long long)ret[i] * ret[j] / g;
                    ret.pop_back();
                    ret.pop_back();
                    ret.push_back(new_val);
                } else {
                    break;
                }
            }
        };
        
        for(auto num : nums) {
            ret.push_back(num);
            adjust();
        }
        
        return ret;
    }
};
