class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int lastPos[26]{};
        memset(lastPos, -1, sizeof(lastPos));
        int ans = -1;
        
        for(int i=0;i<s.size();i++)
        {
            int &curAlphabetPos = lastPos[s[i]-'a'];
            
            if(curAlphabetPos == -1) curAlphabetPos = i;
            else
            {
                if(i-curAlphabetPos-1 > ans) ans = i-curAlphabetPos-1;
            }
        }
        
        return ans;
    }
};
