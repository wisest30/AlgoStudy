class Solution {
public:
    int minFlips(string target) {
        int light = 0;
        int numFlip = 0;
        for(int i = 0; i < target.size(); i++){
            if( (target[i] - '0') == light )
                continue;
            light ^= 1;
            numFlip++;
        }
        
        return  numFlip;
    }
};
