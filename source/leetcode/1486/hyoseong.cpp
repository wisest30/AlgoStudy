class Solution {
public:
    int xorOperation(int n, int start) {
        auto ret = 0;
        for(auto i = 0; i < n; ++i) {
            ret ^= start + 2 * i;
        }
        return ret;
    }
};
