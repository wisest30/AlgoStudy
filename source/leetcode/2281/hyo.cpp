class Solution {
public:
    int totalStrength(vector<int>& strength) {
        constexpr int MOD = 1e9 + 7;
        int n = strength.size();
        vector<int> left(n, 0), right(n, n);
        
        vector<int> st;
        for(auto i = 0; i < n; ++i) {
            while(!st.empty() && strength[st.back()] > strength[i])
                st.pop_back();
            if(!st.empty())
                left[i] = st.back() + 1;
            st.push_back(i);
        }
        
        st.clear();
        for(auto i = n-1; i >= 0; --i) {
            while(!st.empty() && strength[st.back()] >= strength[i])
                st.pop_back();
            if(!st.empty())
                right[i] = st.back();
            st.push_back(i);
        }
        
        vector<long long> ps(n+1), ips(n+1), rips(n+1);
        for(long long i = 1; i <= n; ++i) {
            ps[i] = (ps[i-1] + strength[i-1]) % MOD;
            ips[i] = (ips[i-1] + strength[i-1] * i % MOD) % MOD;
            rips[i] = (rips[i-1] + strength[i-1] * (n - i + 1) % MOD) % MOD;
        }
        
        long long ret = 0;
        for(auto i = 0; i < n; ++i) {
            int l = left[i], r = right[i];
            
            // left
            long long s = (ps[i] - ps[l] + MOD) % MOD;
            long long add = (ips[i] - ips[l] + MOD) % MOD;
            add = (add - l * s % MOD + MOD) % MOD;
            add = add * (r - i) % MOD;
            add = add * strength[i] % MOD;
            ret = (ret + add) % MOD;

            // right
            s = (ps[r] - ps[i+1] + MOD) % MOD;
            add = (rips[r] - rips[i+1] % MOD) % MOD;
            add = (add - (n - r) * s % MOD + MOD) % MOD;
            add = add * (i - l + 1) % MOD;
            add = add * strength[i] % MOD;
            ret = (ret + add) % MOD;

            // mid
            add = (long long)strength[i] * strength[i] % MOD;
            add = add * (i - l + 1) % MOD * (r - i) % MOD;
            ret = (ret + add) % MOD;

        }
        
        return ret;
    }
};
