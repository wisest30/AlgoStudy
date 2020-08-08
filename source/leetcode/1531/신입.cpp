struct CacheEntry
{
    int totalLen;
    int contiLen;
};

class Solution {
public:
    CacheEntry cache[100+5][100+5][26];
    
    CacheEntry &getCache(string& s, int st, int k, int alphabet)
    {
        if(cache[st][k][alphabet].totalLen != 0x7f7f7f7f) return cache[st][k][alphabet];
        if(st == s.size())
        {
            cache[st][k][alphabet].totalLen = 0;
            cache[st][k][alphabet].contiLen = 0;
            return cache[st][k][alphabet];
        }
        
        if(s[st] != alphabet + 'a')
        {
            if(k == 0)
            {
                cache[st][k][alphabet].totalLen = 0x3f3f3f3f;
                cache[st][k][alphabet].contiLen = 0x3f3f3f3f;
                return cache[st][k][alphabet];
            }
            
            CacheEntry &res = getCache(s, st+1, k-1, alphabet);
            cache[st][k][alphabet] = res;
        }
        else
        {
            if(k > 0)
            {
                CacheEntry &res = getCache(s, st+1, k-1, alphabet);
                cache[st][k][alphabet] = res;
            }
            
            for(int i=0;i<26;i++)
            {
                if(i == alphabet) continue;
                CacheEntry &res = getCache(s, st+1, k, i);
                int newTotalLen = res.totalLen + 1;
                int newContiLen = 1;
                if(newTotalLen < cache[st][k][alphabet].totalLen)
                {
                    cache[st][k][alphabet].totalLen = newTotalLen;
                    cache[st][k][alphabet].contiLen = newContiLen;
                }
            }
            
            CacheEntry &res = getCache(s, st+1, k, alphabet);
            int newTotalLen = res.totalLen;
            int newContiLen = res.contiLen + 1;
            
            if(res.contiLen == 0 || res.contiLen == 1 || res.contiLen == 9 || res.contiLen == 99) newTotalLen++;
            
            if(newTotalLen < cache[st][k][alphabet].totalLen
              || (newTotalLen == cache[st][k][alphabet].totalLen
                 && (cache[st][k][alphabet].contiLen == 0
                    || cache[st][k][alphabet].contiLen == 1
                    || cache[st][k][alphabet].contiLen == 9
                    || cache[st][k][alphabet].contiLen == 99))
              )
            {
                cache[st][k][alphabet].totalLen = newTotalLen;
                cache[st][k][alphabet].contiLen = newContiLen;
            }
        }
        
        return cache[st][k][alphabet];
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(cache, 0x7f, sizeof(cache));
        int ans = 0x7f7f7f7f;
        
        for(int i=0;i<26;i++)
        {
            CacheEntry &res = getCache(s, 0, k, i);
            ans = min(ans, res.totalLen);
        }
        
        return ans;
    }
};
