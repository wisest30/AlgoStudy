class Solution {
public:
    int parent[1'00000+5];
    int N;
    
    int find(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        if(u > v) swap(u, v);
        parent[v] = u;
    }
    
    int cntMinDiff(vector<int> &a, vector<int> &b)
    {
        int aCur = 0;
        int bCur = 0;
        int sameCnt = 0;
        
        while(aCur < a.size() && bCur < b.size())
        {
            if(a[aCur] == b[bCur]) 
            {
                sameCnt++;
                aCur++;
                bCur++;
            }
            else if(a[aCur] < b[bCur]) aCur++;
            else if(a[aCur] > b[bCur]) bCur++;
        }
        
        return a.size()-sameCnt;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        N = source.size();
        map<int, vector<int>> sourceGroup;
        map<int, vector<int>> targetGroup;
        
        for(int i=0;i<N;i++) parent[i] = i;
        for(auto& allowedSwap : allowedSwaps) merge(allowedSwap[0], allowedSwap[1]);
        
        for(int i=0;i<N;i++)
        {
            sourceGroup[find(i)].push_back(source[i]);
            targetGroup[find(i)].push_back(target[i]);
        }
        
        int ans = 0;
        
        for(auto it = sourceGroup.begin() ; it != sourceGroup.end() ; it++)
        {
            sort(sourceGroup[it->first].begin(), sourceGroup[it->first].end());
            sort(targetGroup[it->first].begin(), targetGroup[it->first].end());
            ans += cntMinDiff(sourceGroup[it->first], targetGroup[it->first]);
        }
        
        return ans;
    }
};
