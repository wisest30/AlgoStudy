class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        auto ret = vector<string>{};
        auto M = map<string, int>{};

        for(auto& name : names) {
            if(M.count(name)) {
                auto nxt_name = name + string("(") + to_string(M[name]) + string(")");
                while(M.count(nxt_name)) {
                    M[name]++;
                    nxt_name = name + string("(") + to_string(M[name]) + string(")");
                }
                ret.push_back(nxt_name);
                M[nxt_name]++;
                M[name]++;
            }
            else {
                ret.push_back(name);
                M[name]++;
            }
        }

        return ret;
    }
};
