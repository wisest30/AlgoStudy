class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ret = 0;
        while(target > 1 && maxDoubles) {
            if(target % 2 == 0 && maxDoubles) target /= 2, maxDoubles--;
            else target--;
            ret++;
        }
        ret += target - 1;
        return ret;
    }
};
