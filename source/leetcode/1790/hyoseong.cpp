class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff_idx;
        for(auto i = 0; i < s1.size(); ++i)
            if(s1[i] != s2[i])
                diff_idx.push_back(i);

        if(diff_idx.empty())
            return true;
        else if(diff_idx.size() != 2)
            return false;
        
        swap(s1[diff_idx[0]], s1[diff_idx[1]]);
        
        return s1 == s2;
    }
};
