class Solution {
public:
    int countCollisions(string directions) {
        int r = 0, s = 0, ret = 0;
        for(auto d : directions) {
            if(d == 'R')
                ++r;
            else if(d == 'L' && r + s > 0) {
                ret += r + 1;
                r = 0, ++s;
            }
            else if(d == 'S') {
                ret += r;
                r = 0, ++s;
            }
        }
        
        return ret;
    }
};
