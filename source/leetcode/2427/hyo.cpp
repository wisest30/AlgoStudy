class Solution {
public:
    int commonFactors(int a, int b) {
        int ret = 0;
        for(auto i = 1; i <= min(a, b); ++i) ret += !(a % i) && !(b % i);
        return ret;
    }
};
