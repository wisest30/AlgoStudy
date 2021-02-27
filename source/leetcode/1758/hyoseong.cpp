class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        string s0, s1;
        for(auto i = 0; i < n; ++i) {
            s0.push_back(i % 2 + '0');
            s1.push_back((i % 2) ^ 1 + '0');
        }
        
        int candi0 = 0, candi1 = 0;
        for(auto i = 0; i < n; ++i) {
            if(s[i] != s0[i]) candi0++;
            if(s[i] != s1[i]) candi1++;
        }
        
        return min(candi0, candi1);
    }
};
