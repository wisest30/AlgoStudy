class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        
        while(target > 1)
        {
            if(target&1 == 1)
            {
                target--;
                cnt++;
            }
            else if(maxDoubles > 0)
            {
                target /= 2;
                maxDoubles--;
                cnt++;
            }
            else
            {
                cnt += target - 1;
                break;
            }
        }
        
        return cnt;
    }
};
