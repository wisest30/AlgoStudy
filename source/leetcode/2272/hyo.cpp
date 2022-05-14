static int rightcnt[10001];
class Solution {
public:
    int largestVariance(string s) {
        int ret = 0;
        for(auto c = 'a'; c <= 'z'; ++c) {           
            for(auto d = 'a'; d <= 'z'; ++d) {
                if(s.find(d) == string::npos || c == d) continue;
                                
                int cnt = 0;
                for(auto l = 1; l <= s.size(); ++l) {
                    if(s[s.size() - l] == c) ++cnt;
                    else if(s[s.size() - l] == d) cnt = 0;
                    rightcnt[l] = cnt;
                }

                int min_sum = 0, cur_sum = 0;
                for(auto i = 0; i < s.size(); ++i) {
                    if(s[i] == c) cur_sum++;
                    else if(s[i] == d) cur_sum--;
                    else continue;

                    if(s[i] == d) {
                        int candi = cur_sum - min_sum;
                        candi += rightcnt[s.size() - (i+1)];
                        ret = max(ret, candi);
                    }
                    min_sum = min(min_sum, cur_sum);
                }
            }
        }
        
        return ret;
    }
};
