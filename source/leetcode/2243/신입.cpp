class Solution {
public:
    string getSum(string s)
    {
        int res = 0;
        
        for(char ch : s) res += ch-'0';
        
        return to_string(res);
    }
    
    string digitSum(string s, int k) {
        if(s.size() <= k) return s;
        
        string temp;
        
        for(int i=0;i<s.size();i+=k) temp += getSum(s.substr(i, k));  
        
        return digitSum(temp, k);
    }
};
