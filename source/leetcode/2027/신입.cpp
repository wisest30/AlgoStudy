class Solution {
public:
    int minimumMoves(string s) {
        s += "OO";
        int ans = 0;
        
        for(int i=0;i+2<s.size();i++)
        {
            if(s[i] == 'X')
            {
                ans++;
                s[i] = s[i+1] = s[i+2] = 'O';
            }
        }
        
        return ans;
    }
};
