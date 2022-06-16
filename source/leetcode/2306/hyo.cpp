class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> s(ideas.begin(), ideas.end());
        
        long long ret = 0;
        auto A = vector<vector<long long>>(26, vector<long long>(26));
        for(auto& name : ideas) {            
            for(auto c = 'a'; c <= 'z'; ++c) {
                auto key = name;
                key[0] = c;
                if(!s.count(key)) {
                    ret += 2 * A[c - 'a'][name[0] - 'a'];
                    A[name[0] - 'a'][c - 'a']++;
                }
            }
        }
        
        return ret;
    }
};
