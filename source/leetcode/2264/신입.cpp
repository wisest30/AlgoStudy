class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        
        for(int i=0;i+2<num.size();i++)
        {
            string substr = num.substr(i, 3);
            if(substr[0] == substr[1] && substr[1] == substr[2]) ans = max(ans, substr);
        }
        
        return ans;
    }
};
