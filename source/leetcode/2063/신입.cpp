class Solution {
public:
    typedef long long ll;
    
    long long countVowels(string word) {
        ll ans = 0;
        
        for(int i=0;i<word.size();i++)
        {
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            {
                ans += 1LL * (i+1) * ((int)word.size()-i);        
            }
        }
        
        return ans;
    }
};
