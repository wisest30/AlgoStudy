class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> m;
        for(auto& s : arr) m[s]++;
        
        int cur = 1;
        for(auto& s : arr) {
            if(m[s] > 1) continue;
            if(cur == k) return s;
            ++cur;
        }
        
        return "";
    }
};
