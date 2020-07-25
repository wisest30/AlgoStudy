class Solution {
public:
    int numSub(string s) {
        int cur = 0;
        int ans = 0;
        
        for(char ch : s)
        {
            if(ch == '1') cur++;
            else cur = 0;
            ans += cur;
            ans %= 1'000'000'007;
        }
        
        return ans;
    }
};
