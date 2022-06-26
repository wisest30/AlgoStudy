class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        
        bool visit[10]{};
        int origin = num;
        int cnt = 0;
        
        num %= 10;
        num += 10;
        
        while(num)
        {
            num = (num+10-k)%10;
            cnt++;
            if(visit[num]) return -1;
            visit[num] = true;
        }
        
        if(origin >= cnt*k) return cnt;
        return -1;
    }
};
