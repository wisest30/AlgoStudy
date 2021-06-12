class Solution {
public:
    string maxNegativeValue(const string& n, int x) {
        auto p = 1;
        while(p < n.size() && n[p] - '0' <= x)
            ++p;
        
        return n.substr(0, p) + to_string(x) + n.substr(p);
    }

    string maxPositiveValue(const string& n, int x) {
        auto p = 0;
        while(p < n.size() && n[p] - '0' >= x)
            ++p;
        
        return n.substr(0, p) + to_string(x) + n.substr(p);
    }

    string maxValue(string n, int x) {
        if(n[0] == '-')
            return maxNegativeValue(n, x);
        else
            return maxPositiveValue(n, x);
    }
};
