class Solution {
public:
    int minFlips(string target) {
        auto ret = 0;
        auto last = 0;
        int n = target.size();
        for(auto i = 0; i < n; ++i) {
            if(target[i] - '0' != last) {
                ret++;
                last ^= 1;
            }
        }
        return ret;
    }
};
