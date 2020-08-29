class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            ans += abs(n-(2*i+1));    
        }
        
        return ans/2;
    }
};
