class Solution {
public:
    string largestPalindromic(string num) {
        int digitCnt[10]{};
        
        for(char ch : num) digitCnt[ch-'0']++;
        
        string l;
        
        for(int i=9;i>=0;--i)
        {
            l += string(digitCnt[i]/2, i+'0');
            digitCnt[i] %= 2;
        }
        
        string mid;
        
        for(int i=9;i>=0;--i)
        {
            if(digitCnt[i]) 
            {
                mid += i+'0';
                break;
            }
        }
        
        string temp = l;
        reverse(temp.begin(), temp.end());
        
        while(!temp.empty() && temp.back() == '0') temp.pop_back();
        reverse(temp.begin(), temp.end());
        
        l = temp;
        string r = l;
        
        reverse(r.begin(), r.end());
        
        if(l.empty() && mid.empty()) return "0";
        
        return l + mid + r;
    }
};
