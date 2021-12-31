class Solution {
public:
    int numRev(int num)
    {
        int res = 0;
        
        while(num)
        {
            res = res*10 + num%10;
            num/=10;
        }
        
        return res;
    }
    
    bool isSameAfterReversals(int num) {
        if(numRev(numRev(num)) == num) return true;
        return false;
    }
};
