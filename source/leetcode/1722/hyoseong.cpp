class Solution {
public:
    int get_group(vector<int>& G, int x) {
        if(G[x] == x) return x;
        return G[x] = get_group(G, G[x]);
    }
    
    void merge_group(vector<int>& G, int x, int y) {
        int gx = get_group(G, x);
        int gy = get_group(G, y);
        G[gx] = gy;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {       
        vector<int> G(source.size());
        iota(G.begin(), G.end(), 0);
        
        for(auto& a : allowedSwaps)
            merge_group(G, a[0], a[1]);
        
        vector<multiset<int>> A(source.size());
        for(auto i = 0; i < source.size(); ++i) {
            auto g = get_group(G, i);
            A[g].insert(source[i]);
        }

        int ret = 0;
        for(auto i = 0; i < target.size(); ++i) {
            auto g = get_group(G, i);
            auto p = A[g].find(target[i]);
            
            if(p != A[g].end()) A[g].erase(p);
            else ret++;
        }
        return ret;
    }
};
