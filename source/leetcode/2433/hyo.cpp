class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for(auto i = (int)pref.size() - 2; i >= 0; --i)
            pref[i+1] ^= pref[i];
        
        return pref;
    }
};
