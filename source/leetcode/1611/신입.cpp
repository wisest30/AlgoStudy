class Solution {
public:
    int getCnt(int from, int to)
    {
        int ret = 0;
        
        for(int i=30;i>0;--i)
        {
            unsigned int fromBit = from&(1<<i);
            unsigned int toBit = to&(1<<i);
            
            if(fromBit != toBit)
            {
                ret = getCnt(from&((1<<i)-1), (1<<(i-1))) + 1 + (1<<i) - 1;
                return ret;
            }
        }
        
        if(from == to) return 0;
        return 1;
    }
    
    int minimumOneBitOperations(int n) {
        return getCnt(n, 0);
    }
};
