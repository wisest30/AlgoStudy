class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        
        while(n > 1)
        {
            ans += n/2;
            if(n%2 == 0) n/=2;
            else n = n/2+1;
        }
        
        return ans;
    }
};
