class Solution {
public:
    vector<vector<int>> A;
    vector<int> nums;
    int f(int high) {
        auto ret = 0;
        for(auto x : nums) {
            auto p = 0;
            for(auto i = 15; i >= 0; --i) {
                int z = 16 - i;
                if(high & (1 << i)) {
                    if(x & (1 << i)) {
                        ret += A[z][p+1];
                    }
                    else {
                        ret += A[z][p];
                        p++;
                    }
                }
                else {
                    if(x & (1 << i)) {
                        p++;
                    }
                    else {
                        
                    }                    
                }
                p *= 2;
            }
            p /= 2;
            ret += A[16][p];
        }
        return ret;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        this->nums = nums;
        A = vector<vector<int>>(17);
        for(auto i = 1; i <= 16; ++i)
            A[i].resize(1 << i);
        
        for(auto x : nums) {
            for(auto i = 16; i >= 1; --i) {
                A[i][x]++;
                x /= 2;
            }
        }

        int ret = 0;
        ret = f(high) - f(low - 1);
        return ret / 2;
    }
};
