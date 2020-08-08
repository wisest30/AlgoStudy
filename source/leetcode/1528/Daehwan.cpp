class Solution {
public:
    string restoreString(string s, vector<int>& id) {
        int n = s.size();
        s += s;
        for(int i=0; i<n; i++) s[n+id[i]] = s[i];
        s.erase(s.begin(), s.begin()+n);
        return s;
    }
};
