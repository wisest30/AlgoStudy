class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        int ans = 0;
        
        for(int i = (int)s.size()-1;i>0;--i)
        {
            if(s[i] == '1' && carry == 0)
            {
                ans++;
                carry = 1;
            }
            else if(s[i] == '0' && carry == 1) ans++;
            ans++;
        }
        
        return ans + carry;
    }
};
