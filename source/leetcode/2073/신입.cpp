class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cur = 0;
        int total = 0;
        
        while(true)
        {
            if(tickets[cur])
            {
                tickets[cur]--;
                total++;
            }
            cur = (cur+1)%tickets.size();
            
            if(tickets[k] == 0) return total;
        }
        
        return -1;
    }
};
