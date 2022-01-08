class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> ab, ba, aa;
        for(auto& w : words) w[0] == w[1] ? aa[w]++ : w[0] < w[1] ? ab[w]++ : ba[w]++;
        int ret = 0, one = 0;
        for(auto& p : aa) one |= p.second % 2, ret += p.second / 2 * 4;
        ret += one * 2;
        for(auto& p : ab) ret += min(p.second, ba[p.first.substr(1) + p.first[0]]) * 4;
        return ret;
    }
};
