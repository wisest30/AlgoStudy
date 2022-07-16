class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        string s, t;
        vector<int> sp, tp;
        for(auto i = 0; i < n; ++i) {
            if(start[i] != '_') {
                s.push_back(start[i]);
                sp.push_back(i);
            }
            if(target[i] != '_') {
                t.push_back(target[i]);
                tp.push_back(i);
            }
        }
        
        if(s != t)
            return false;
        
        n = s.size();
        for(auto i = 0; i < n; ++i)
            if(s[i] == 'L' && sp[i] < tp[i] || s[i] == 'R' && sp[i] > tp[i]) 
                return false;
        
        return true;
    }
};
