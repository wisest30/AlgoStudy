class Solution {
public:
    vector<int> shuffle(vector<int>& ns, int n) {
        vector<int> ret;
        for(int i=0; i<n; i++){
            ret.push_back(ns[i]);
            ret.push_back(ns[n+i]);
        }
        return ret;
    }
};
