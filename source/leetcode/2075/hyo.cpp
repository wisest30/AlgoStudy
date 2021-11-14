class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        string ret;
        int n = s.size();
        int cols = n / rows;
        for(auto i = 0; i < cols; ++i)
            for(auto j = 0; i + j * (cols + 1) < n; ++j)
                ret.push_back(s[i + j * (cols + 1)]);
        
        while(ret.back() == ' ')
            ret.pop_back();
        
        return ret;
    }
};
