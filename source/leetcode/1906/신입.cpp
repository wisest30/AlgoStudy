class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int count[1'00000+5][100+5]{};
        
        for(int i=0;i<nums.size();i++)
        {
            if(i)
            {
                for(int j=1;j<=100;j++) count[i][j] = count[i-1][j];
            }
            
            count[i][nums[i]]++;
        }
        
        vector<int> answer;
        
        for(auto &query : queries)
        {
            int temp[100+5]{};
            
            for(int i=1;i<=100;i++) 
            {
                temp[i] = count[query[1]][i];
                if(query[0]) temp[i] -= count[query[0]-1][i];
            }
            
            int prev = 0;
            int ans = INT_MAX;
            
            for(int i=1;i<=100;i++)
            {
                if(prev && temp[i]) ans = min(ans, i-prev);
                if(temp[i]) prev = i;
            }
            
            if(ans == INT_MAX) ans = -1;
            
            answer.push_back(ans);
        }
        
        return answer;
    }
};
