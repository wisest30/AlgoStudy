class Solution {
public:
    class DisjointSet {
    vector<int> G, Gcnt;
    public :
        DisjointSet(int n) : G(n)
        { iota(G.begin(), G.end(), 0); }

        int find(int x) {
            if(G[x] == x) return x;
            return G[x] = find(G[x]);
        }

        void merge(int x, int y) {
            int gx = find(x), gy = find(y);
            G[gy] = gx;
        }
    };
    
    int str_to_bit(const string& s) {
        int ret = 0;
        for(auto c : s) ret |= 1 << (c - 'a');
        return ret;
    }
    
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        DisjointSet ds(n);
        
        map<int, int> idx_map;
        for(auto i = 0; i < n; ++i) {
            auto key = str_to_bit(words[i]);
            if(idx_map.count(key)) ds.merge(i, idx_map[key]);
            for(auto j = 0; j < 26; ++j) {
                auto nxt_key = key ^ (1 << j);
                if(idx_map.count(nxt_key)) ds.merge(i, idx_map[nxt_key]);
                if(key & (1 << j)) {
                    for(auto k = 0; k < 26; ++k) {
                        if(!(key & (1 << k))) {
                            auto nxt_key = key ^ (1 << j) ^ (1 << k);
                            if(idx_map.count(nxt_key)) ds.merge(i, idx_map[nxt_key]);
                        }
                    }
                }
            }
            idx_map[key] = i;
        }
        
        map<int, int> groups;
        int max_cnt = 0;
        for(auto i = 0; i < n; ++i)
            max_cnt = max(max_cnt, ++groups[ds.find(i)]);
        
        return {(int)groups.size(), max_cnt};
    }
};
