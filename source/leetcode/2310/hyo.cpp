class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(!num)
            return 0;
        
        for(auto i = 1; i <= num; ++i)
            if(i * k % 10 == num % 10 && i * k <= num)
                return i;
        
        return -1;
    }
};
