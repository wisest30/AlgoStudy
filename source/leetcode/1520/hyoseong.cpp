class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        auto A = vector<pair<int, int>>(26, {-1, -1});
        for(auto i = 0; i < s.size(); ++i) {
            int x = s[i] - 'a';
            if(A[x].first == -1) A[x].first = i;
            A[x].second = i+1;
        }
        
        auto B = vector<pair<int, int>>{};
        for(auto i = 0; i < A.size(); ++i) {
            if(A[i].first == -1) continue;
            bool include = true;
            int end = A[i].second;
            for(int j = A[i].first; j < end; ++j) {
                auto x = s[j] - 'a';
                if(A[x].first < A[i].first) {
                    include = false;
                    break;
                }
                end = max(end, A[x].second);
            }
            if(include) {
                B.push_back({A[i].first, end});
            }
        }
        
        sort(B.begin(), B.end());
        auto ret = vector<string>{};
        for(auto i = 0; i < B.size(); ++i) {
            if(i+1 < B.size() && B[i+1].first < B[i].second) continue;
            ret.push_back(s.substr(B[i].first, B[i].second - B[i].first));
        }
        return ret;
    }
};
