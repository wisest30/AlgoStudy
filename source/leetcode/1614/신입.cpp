class Solution {
public:
    int maxDepth(string s) {
        int curDepth = 0;
        int ans = 0;
        
        for(char ch : s)
        {
            if(ch == '(') curDepth++;
            else if(ch == ')') curDepth--;
            
            if(curDepth > ans) ans = curDepth;
        }
        
        return ans;
    }
};
