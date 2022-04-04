class Solution {
    vector<int> z_function(const string &s)
    {
        vector<int> z(s.length(), 0);
        for (int i=1,l=0,r=0; i < z.size(); i++) {
            if (i <= r) z[i] = min(r-i+1, z[i-l]);
            while (i+z[i] < z.size() && s[i+z[i]] == s[z[i]]) z[i]++;
            if (r < i+z[i]-1) r = i+z[i]-1, l = i;
        }
        return z;
    }
    
public:
    long long sumScores(string s) {
        auto z = z_function(s);
        return (long long)s.size() + accumulate(z.begin(), z.end(), 0ll);
    }
};
