class Solution {
public:
    string str;
    string ans;
    string temp;
    
    int chk(string &target, int k)
    {
        int targetCur = 0;
        int repeat = 0;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == target[targetCur]) targetCur++;
            if(targetCur == target.size())
            {
                repeat++;
                targetCur = 0;
            }
        }
        
        return repeat;
    }
    
    void dfs(int k)
    {
        int res = chk(temp, k);
        if(res < k) return;
        
        if(temp.size() > ans.size()) ans = temp;
        else if(temp.size() == ans.size() && temp > ans) ans = temp;
        
        for(char ch='a';ch<='z';ch++)
        {
            temp += ch;
            dfs(k);
            temp.pop_back();
        }
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        str = s;
        dfs(k);
        return ans;
    }
};
