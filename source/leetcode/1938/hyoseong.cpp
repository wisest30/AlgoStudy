class Solution {
    static constexpr int MAX_BIT = 17;
    
    class Indexer {
        vector<vector<int>> counter;
    public :
        Indexer() : counter(MAX_BIT, vector<int>(1 << MAX_BIT)) {}
        void insert(int x) {
            int key = 0;
            for(auto i = MAX_BIT - 1; i >= 0; --i) {
                key <<= 1;
                if(x & (1 << i))
                    key++;
                
                counter[i][key]++;
            }
        }
        void remove(int x) {
            int key = 0;
            for(auto i = MAX_BIT - 1; i >= 0; --i) {
                key <<= 1;
                if(x & (1 << i))
                    key++;
                
                counter[i][key]--;
            }
        }
        
        int get_max_xor(int x) {
            int key = 0;
            for(auto i = MAX_BIT - 1; i >= 0; --i) {
                key <<= 1;
                if(!(x & (1 << i)))
                    key++;

                if(!counter[i][key])
                    key ^= 1;
                
                assert(counter[i][key]);
            }
            
            return key ^ x;
        }
    };

    int n, m;
    Indexer indexer;
    vector<vector<int>> G, Q, queries;
    vector<int> ans;
public:
    void dfs(int cur) {
        indexer.insert(cur);
        
        for(auto i : Q[cur])
            ans[i] = indexer.get_max_xor(queries[i][1]);
        
        for(auto nxt : G[cur])
            dfs(nxt);
        
        indexer.remove(cur);
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        n = parents.size();
        m = queries.size();
        G.resize(n);
        Q.resize(n);
        ans.resize(m, -1);
        this->queries = queries;
        
        int root = -1;
        for(auto i = 0; i < n; ++i) {
            if(parents[i] == -1)
                root = i;
            else
                G[parents[i]].push_back(i);
        }
        
        for(auto i = 0; i < queries.size(); ++i)
            Q[queries[i][0]].push_back(i);

        dfs(root);
        return ans;
    }
};
