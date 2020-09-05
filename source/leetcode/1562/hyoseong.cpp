class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        
        if(n == m)
            return n;

        set<pair<int, int>> S;
        S.insert({0, 0});
        S.insert({1, n+1});
        S.insert({INT_MAX, INT_MAX});
                    
        for(auto i = (int)arr.size() - 1; i >= 0; --i) {
            auto p = prev(S.lower_bound({arr[i], INT_MAX}));
            if (p->first == arr[i]) {
                auto left = arr[i]+1, right = p->second;
                S.erase(p);
                S.insert({arr[i]+1, right});
                if(right - left == m)
                    return i;
            }
            else if(p->second >= arr[i]) {
                auto left = p->first, right = p->second;
                S.erase(p);
                
                S.insert({left, arr[i]});
                if(arr[i] - left == m)
                    return i;
                
                S.insert({arr[i]+1, right});                
                if(right - (arr[i] + 1) == m)
                    return i;
            }
        }
        
        return -1;
    }
};
