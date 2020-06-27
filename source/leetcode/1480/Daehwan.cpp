class Solution {
public:
    vector<int> runningSum(vector<int>& ns) {
        vector<int> ret;
        ret.push_back(ns[0]);
        for(int i=1; i<ns.size(); i++){
            ret.push_back(ret[i-1]+ns[i]);
        }
        return ret;
    }
};
