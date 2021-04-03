class Solution {
public:
    vector<vector<int>> A;
    vector<int> nums;
    int f(int high) {
        auto ret = 0;
        for(auto num : nums) {
            auto prefix = 0;
            for(auto i = 15; i >= 0; --i) {
                int len = 16 - i;
                bool p = high & (1 << i);
                bool q = num & (1 << i);
                               
                if(p && q) ret += A[len][prefix + 1];
                else if(p && !q) ret += A[len][prefix++];
                else if(!p && q) prefix++;
                else if(!p && !q); //pass
                prefix *= 2;
            }
            ret--;
        }

        return ret / 2;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        this->nums = nums;
        A = vector<vector<int>>(17);
        for(auto i = 1; i <= 16; ++i)
            A[i].resize(1 << i);
        
        for(auto num : nums) {
            for(auto i = 16; i >= 1; --i) {
                A[i][num]++;
                num >>= 1;
            }
        }

        int ret = 0;
        ret = f(high + 1) - f(low);
        return ret;
    }
};
