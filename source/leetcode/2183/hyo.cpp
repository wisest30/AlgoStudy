class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        vector<int> p;
        for(auto i = 1; i <= k; ++i)
            if(k % i == 0)
                p.push_back(i);
        
        map<int, int> cnts;
        for(auto num : nums) {
            for(auto x : p) {
                if(num % x == 0)
                    ++cnts[x];
            }
        }
        
        long long ret = 0;
        for(auto num : nums) {
            auto g = __gcd(num, k);
            auto q = k / g;
            ret += cnts[q];
            if(num % q == 0)
                --ret;
        }
        
        ret /= 2;
        
        return ret;
    }
};
