class Solution {
public:
    int getLucky(string s, int k) {
        string t;
        for(auto c : s)
            t += to_string((int)(c - 'a' + 1));
        
        for(auto i = 0; i < k; ++i) {
            int su = 0;
            for(auto c : t)
                su += c - '0';
            t = to_string(su);
        }
        
        return stoi(t);
    }
};
