class Solution {
public:
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};
    
    map<char, int> mapping;
    
    void init()
    {
        mapping['R'] = 0;
        mapping['D'] = 1;
        mapping['L'] = 2;
        mapping['U'] = 3;
    }
    
    int execute(int n, int r, int c, string &s)
    {
        int res = 0;
        
        for(int i=(int)s.size()-1;i>=0;--i)
        {
            r += dr[mapping[s[i]]];
            c += dc[mapping[s[i]]];
            
            if(r < 0 || r >= n || c < 0 || c >= n) break;
            
            res++;
        }
        
        return res;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        init();
        reverse(s.begin(), s.end());
        int iter = s.size();
        vector<int> ans;
        
        for(int i=0;i<iter;i++)
        {
            ans.push_back(execute(n, startPos[0], startPos[1], s));
            s.pop_back();
        }
        
        return ans;
    }
};
