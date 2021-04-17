class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> m;
        for(auto& l : logs)
            m[l[0]].insert(l[1]);
        
        auto ret = vector<int>(k);
        for(auto& p : m)
            ret[p.second.size() - 1]++;
        
        return ret;
    }
};
