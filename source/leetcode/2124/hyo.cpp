class Solution {
public:
    bool checkString(string s) {
        auto p = s.rfind('a'), q = s.find('b');
        return p == string::npos || q == string::npos || p < q;
    }
};
