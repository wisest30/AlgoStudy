class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c_cnt = 0;
        int r_cnt = 0;
        int o_cnt = 0;
        int a_cnt = 0;
        
        int ans = 0;
        
        for(int i=0;i<croakOfFrogs.size();++i)
        {
            if(croakOfFrogs[i] == 'c') c_cnt++;
            else if(croakOfFrogs[i] == 'r')
            {
                r_cnt++;
                c_cnt--;
                if(c_cnt < 0) return -1;
            }
            else if(croakOfFrogs[i] == 'o')
            {
                o_cnt++;
                r_cnt--;
                if(r_cnt < 0) return -1;
            }
            else if(croakOfFrogs[i] == 'a')
            {
                a_cnt++;
                o_cnt--;
                if(o_cnt < 0) return -1;
            }
            else if(croakOfFrogs[i] == 'k')
            {
                a_cnt--;
                if(a_cnt < 0) return -1;
            }
            
            int sum = c_cnt+r_cnt+o_cnt+a_cnt;
            if(sum > ans) ans = sum;
        }
        if(c_cnt || r_cnt || o_cnt || a_cnt) return -1;
        return ans;
    }
};
