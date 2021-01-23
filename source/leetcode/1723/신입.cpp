class Solution {
public:
    int total[12+5]{};
    bool visit[12+5]{};
    
    int ans = INT_MAX;
    int N;
    
    void dfs(vector<int>& jobs, int k, int idx, int mxTotal)
    {
        if(idx == N)
        {
            ans = min(ans, mxTotal);
            return;
        }
        
        if(mxTotal > ans) return;
        
        if(visit[idx] == true) dfs(jobs, k, idx+1, mxTotal);
        else
        {
            for(int i=0;i<k;i++)
            {
                total[i] += jobs[idx];
                dfs(jobs, k, idx+1, max(mxTotal, total[i]));
                total[i] -= jobs[idx];
            }
        }
    }
    
    void selectK(vector<int>& jobs, int k, int totalIdx, int lastJobIdx, int mxTotal)
    {
        if(totalIdx == k)
        {
            dfs(jobs, k, 0, mxTotal);
            return;
        }
        
        for(int i=lastJobIdx+1;i<N;i++)
        {
            if(N-i < k-totalIdx) break;
            
            total[totalIdx] += jobs[i];
            visit[i] = true;
            selectK(jobs, k, totalIdx+1, i, max(mxTotal, total[totalIdx]));
            visit[i] = false;
            total[totalIdx] -= jobs[i];
        }
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        N = jobs.size();
        selectK(jobs, k, 0, -1, 0);
        return ans;
    }
};
