class Solution {
public:
    const long long mod = 998244353LL;
    long long binary[100000+5];
    long long hash_val[100000+5];
    
    void init()
    {
        binary[0] = 1LL;
        for(int i=1;i<=100000;++i) binary[i] = (2LL * binary[i-1])%mod;
    }
    
    string longestPrefix(string s) {
        init();
        
        long long cur_hash = 0LL;
        
        for(int i=0;i<s.size();++i)
        {
            cur_hash = ((2LL * cur_hash) + s[i] - 'a') % mod;
            hash_val[i] = cur_hash;
        }
        
        int i;
        int ans = -1;
        
        for(i=0;i<(int)s.size()-1;++i)
        {
            long long temp = (hash_val[(int)s.size() - 1] - ((hash_val[(int)s.size() - i - 2]*binary[i+1])%mod) + mod)%mod;
            
            if(hash_val[i] == temp)
            {
                if(i > ans) ans = i;
            }
        }
        return s.substr(0, ans+1);
    }
};
