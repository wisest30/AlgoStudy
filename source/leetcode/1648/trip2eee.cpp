class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        
        priority_queue<int> pq;
        
        for(int i = 0; i < inventory.size(); i++)
        {
            pq.push(inventory[i]);
        }
        
        const int m = 1000000007;
        int sum = 0;
        int sell = 0;
        
        // select the most expensive one.
        int val1 = pq.top();
        pq.pop();

        while(sell < orders)
        {
            // select the 2nd most expensive one.
            int val2;
            if(pq.size() > 0)
            {
                val2 = pq.top();
                pq.pop();
                                
                while(val1 >= val2 && sell < orders)
                {
                    sell ++;

                    sum = (sum + val1) % m;
                    val1 --;
                }

                if(val1 > 0)
                {
                    pq.push(val1);
                }            

                val1 = val2;
            }
            else
            {
                while(sell < orders)
                {
                    sell ++;

                    sum = (sum + val1) % m;
                    val1 --;
                }
                
                break;
            }
        }
        
        return sum;
    }
};