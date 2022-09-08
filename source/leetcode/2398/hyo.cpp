class Solution {
public:
    int maximumRobots(vector<int>& C, vector<int>& R, long long b) {
        long long ret = 0, cnt = 0, su = 0;
        multiset<long long> s;
        for(auto i = 0; i < C.size(); ++i) {
            s.insert(C[i]), su += R[i], ++cnt;
            while(cnt && *s.rbegin() + cnt * su > b) {
                int j = i + 1 - cnt;
                s.erase(s.find(C[j])), su -= R[j], --cnt;
            }
            
            ret = max(ret, cnt);
        }
        
        return ret;
    }
};
