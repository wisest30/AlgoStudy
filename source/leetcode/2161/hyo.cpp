class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l, m, r;
        for(auto num : nums) {
            if(num < pivot) l.push_back(num);
            else if(num == pivot) m.push_back(num);
            else r.push_back(num);
        }
        
        vector<int> ret(l.begin(), l.end());
        ret.insert(ret.end(), m.begin(), m.end());
        ret.insert(ret.end(), r.begin(), r.end());
        return ret;
    }
};
