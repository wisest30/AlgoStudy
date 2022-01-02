class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ret = 0, prev = 0;
        for(auto& s : bank) {
            int cnt = count(s.begin(), s.end(), '1');
            if(cnt) {
                ret += prev * cnt;
                prev = cnt;
            }
        }
        return ret;
    }
};
