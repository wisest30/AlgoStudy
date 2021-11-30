class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> know(n);
        know[0] = know[firstPerson] = true;
        
        vector<vector<pair<int, int>>> A(100001);
        for(auto& meeting : meetings)
            A[meeting[2]].push_back({meeting[0], meeting[1]});

        vector<vector<int>> g(n);
        for(auto time = 0; time < A.size(); ++time) {
            set<int> nodes, visited;
            for(auto& e : A[time]) {
                g[e.first].push_back(e.second);
                g[e.second].push_back(e.first);
                nodes.insert(e.first);
                nodes.insert(e.second);
            }
            
            vector<int> st;
            for(auto node : nodes)
                if(know[node])
                    st.push_back(node);
            
            while(!st.empty()) {
                auto node = st.back();
                st.pop_back();
                
                if(visited.count(node)) continue;
                visited.insert(node);
                
                for(auto nxt_node : g[node]) {
                    know[nxt_node] = true;
                    st.push_back(nxt_node);
                }
            }
            
            for(auto node : nodes)
                g[node].clear();
        }
        
        vector<int> ret;
        for(auto i = 0; i < n; ++i)
            if(know[i])
                ret.push_back(i);
        
        return ret;
    }
};
