class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) return 0;
        bool minus = num < 0;
        num = abs(num);
        auto s = to_string(num);
        if(minus) {
            sort(s.rbegin(), s.rend());
            return -stoll(s);
        } else {
            sort(s.begin(), s.end());
            for(auto i = 0; i < s.size(); ++i) {
                if(s[i] != '0') {
                    swap(s[i], s[0]);
                    break;
                }
            }

            return stoll(s);
        }
    }
};
