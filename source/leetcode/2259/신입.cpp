class Solution {
public:
    string buildString(string &number, int omitIdx)
    {
        string ret;
        
        for(int i=0;i<number.size();i++)
        {
            if(i == omitIdx) continue;
            ret += number[i];
        }
        
        return ret;
    }
    
    string removeDigit(string number, char digit) {
        int n = number.size();
        set<string> ans;
        
        for(int i=0;i<n;i++)
        {
            if(number[i] == digit) ans.insert(buildString(number, i));        
        }
        
        return *ans.rbegin();
    }
};
