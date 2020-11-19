class Solution {
public:
    static bool compare(int& a, int& b)
    {
        if(a > b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int minDeletions(string s) {
        
        vector<int> freq(26, 0);
                
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i]-'a'] ++;
        }
        
        // sort.
        sort(freq.begin(), freq.end(), compare);
        
        int del = 0;
        
        for(int i = 0; i < 26; i++)
        {
            for(int j = i+1; j < 26; j++)
            {
                if(freq[i] > 0 && freq[j] > 0 && freq[j] == freq[i])
                {
                    freq[j]--;
                    del++;
                }
            }
        }
        
        return del;
    }
};