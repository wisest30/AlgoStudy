class Solution {
public:   
    int minOperations(vector<int>& T, vector<int>& A) {
        unordered_map<int, int> M;
        for(auto i = 0; i < T.size(); ++i) M[T[i]] = i;
        
        vector<int> idxes;
        for(auto a : A) {
            if(!M.count(a)) continue;
            auto idx = M[a];
            
            auto p = lower_bound(idxes.begin(), idxes.end(), idx) - idxes.begin();
            if(p >= idxes.size())
                idxes.push_back(idx);
            else
                idxes[p] = idx;
        }
        
        
        return T.size() - idxes.size();
    }
};
