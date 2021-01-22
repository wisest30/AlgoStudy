class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for (int v : encoded) {
            ans.push_back(ans.back() ^ v);
        }
        return ans;
    }
};
