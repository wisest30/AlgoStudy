class Solution {
public:
    int longestSubsequence(string s, int k) {
        int curLen = 0;
        int curNum = 0;
        
        for(char ch : s)
        {
            curLen++;
            if(ch == '0') curNum = curNum*2;
            else curNum = curNum*2+1;
            
            if(curNum > k)
            {
                for(int i=30;i>=0;--i)
                {
                    if(curNum&(1<<i)) 
                    {
                        curNum -= (1<<i);
                        curLen--;
                        break;
                    }
                }
            }
        }
        
        return curLen;
    }
};
