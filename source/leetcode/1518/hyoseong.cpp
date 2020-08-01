class Solution {
public:
    int numWaterBottles(int x, int k) {
        int y = 0, ret = 0;
        while(x) {
            ret += x;
            y += x;
            x = y / k;
            y %= k;
        }
        return ret;
    }
};
