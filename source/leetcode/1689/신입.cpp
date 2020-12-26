class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        
        for(char ch : n)
        {
            if(ch - '0' > ans) ans = ch - '0';    
        }
        
        return ans;
    }
};
