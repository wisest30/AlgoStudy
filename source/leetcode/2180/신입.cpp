class Solution {
public:
    int getDigitSum(int num)
    {
        int res = 0;
        
        while(num)
        {
            res += num%10;
            num/=10;
        }
        
        return res;
    }
    
    int countEven(int num) {
        int cnt = 0;
        
        for(int i=1;i<=num;i++)
        {
            if(getDigitSum(i)%2 == 0) cnt++;
        }
        
        return cnt;
    }
};
