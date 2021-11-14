class Solution {
public:
    string word;
    int cnt[256];
        
    bool isVowel(int l, int r)
    {
        memset(cnt, 0, sizeof(cnt));
        
        for(int i=l;i<=r;i++) 
        {
            if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') return false;
            cnt[word[i]]++;
        }
        
        if(cnt['a'] && cnt['e'] && cnt['i'] && cnt['o'] && cnt['u']) return true;
        
        return false;
    }
    
    int countVowelSubstrings(string word) {
        this->word = word;
        int n = word.size();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                ans += isVowel(i, j);        
            }
        }
        
        return ans;
    }
};
