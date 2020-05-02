class Solution {
public:
    string reformat(string s) {
        vector<char> digits;
        vector<char> letters;
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i] >= '0' && s[i] <= '9') digits.push_back(s[i]);
            else letters.push_back(s[i]);
        }
        
        int diff = (int)digits.size() - (int)letters.size();
        
        if(diff < -1 || diff > 1) return "";
        
        string ans = "";
        
        if(diff == -1)
        {
            ans += letters[0];
            for(int i=1;i<letters.size();++i)
            {
                ans += digits[i-1];
                ans += letters[i];
            }
        }
        else if(diff == 0)
        {
            for(int i=0;i<letters.size();++i)
            {
                ans += digits[i];
                ans += letters[i];
            }
        }
        else
        {
            ans += digits[0];
            for(int i=1;i<digits.size();++i)
            {
                ans += letters[i-1];
                ans += digits[i];
            }
        }
        return ans;
    }
};
