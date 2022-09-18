class Solution {
    class TrieNode {
    public:
        int val;
        map<char, TrieNode> m;
        
        TrieNode() : val(0) {}
        void insert(string& s, int i) {
            if(i) val++;
            if(s.size() == i) return;
            m[s[i]].insert(s, i + 1);
        }
        
        int get_score(string& s, int i) {
            return s.size() == i ? val : val + m[s[i]].get_score(s, i+1);
        }
    };

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode root;
        auto ret = vector<int>();
        
        for(auto& s : words) root.insert(s, 0);        
        for(auto& s : words) ret.push_back(root.get_score(s, 0));
        
        return ret;
    }
};