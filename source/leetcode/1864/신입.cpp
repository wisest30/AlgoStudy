class Solution {
public:
    int minSwaps(string s) {
        int zeroCnt = 0;
        int oneCnt = 0;
        
        for(char ch : s)
        {
            if(ch == '0') zeroCnt++;
            else oneCnt++;
        }
        
        if(oneCnt == zeroCnt || oneCnt-zeroCnt == -1 || oneCnt-zeroCnt == 1)
        {
            string oneStart(s.size(), '0');
            string zeroStart(s.size(), '1');

            for(int i=0;i<s.size();i+=2) 
            {
                oneStart[i] = '1';
                zeroStart[i] = '0';
            }

            int oneDiff = 0;
            int zeroDiff = 0;

            for(int i=0;i<s.size();i++)
            {
                if(s[i] != oneStart[i]) oneDiff++;
                if(s[i] != zeroStart[i]) zeroDiff++;
            }

            if(oneCnt == zeroCnt) return min(oneDiff/2, zeroDiff/2);
            if(zeroCnt == oneCnt+1) return zeroDiff/2;
            return oneDiff/2;
        }
        
        return -1;
    }
};
