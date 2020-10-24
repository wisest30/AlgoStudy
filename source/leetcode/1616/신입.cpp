class Solution {
public:
    bool startFromBtoA(const string &a, const string &b)
    {
        int diffCnt = 0;
        
        string temp = b;
        
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i] != temp[temp.size()-1-i]) diffCnt++;
        }
        
        for(int i=0;i<temp.size();i++)
        {
            int leftPos = min(i, (int)temp.size()-1-i);
            int rightPos = max(i, (int)temp.size()-1-i);
            
            char prevLeftChar = temp[leftPos];
            char prevRightChar = temp[rightPos];
            
            temp[i] = a[i];
            
            char leftChar = temp[leftPos];
            char rightChar = temp[rightPos];
            
            if(prevLeftChar != prevRightChar)
            {
                if(leftChar == rightChar) diffCnt -= 2;
            }
            else
            {
                if(leftChar != rightChar) diffCnt += 2;
            }
            
            if(diffCnt == 0) return true;
        }
        
        return false;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        bool res = startFromBtoA(a, b);
        if(res) return true;
        return startFromBtoA(b, a);
    }
};
