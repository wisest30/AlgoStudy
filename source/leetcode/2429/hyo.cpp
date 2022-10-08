class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int x = 0;
        for(auto i = 31; i >= 0 && cnt; --i) if(num1 & (1 << i)) x |= 1 << i, --cnt;
        for(auto i = 0; i < 32 && cnt; ++i) if(!(x & (1 << i))) x |= 1 << i, --cnt;
        return x;
    }
};
