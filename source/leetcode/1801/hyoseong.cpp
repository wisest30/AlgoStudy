class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        constexpr int MOD = 1e9 + 7;
        priority_queue<vector<int>> buy_q;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sell_q;
        
        for(auto& order : orders) {
            if(order[2] == 0) { // buy
                while(!sell_q.empty() && sell_q.top()[0] <= order[0]) {
                    auto p = sell_q.top();
                    sell_q.pop();
                    if(order[1] > p[1])
                        order[1] -= p[1];
                    else {
                        p[1] -= order[1];
                        order[1] = 0;
                        sell_q.push(p);
                        break;
                    }
                }
            }
            else { // sell
                while(!buy_q.empty() && buy_q.top()[0] >= order[0]) {
                    auto p = buy_q.top();
                    buy_q.pop();
                    if(order[1] > p[1])
                        order[1] -= p[1];
                    else {
                        p[1] -= order[1];
                        order[1] = 0;
                        buy_q.push(p);
                        break;
                    }
                }                
            }
            
            if(order[1] > 0)
                order[2] == 0 ? buy_q.push(order) : sell_q.push(order);
        }
        
        long long ret = 0;
        while(!buy_q.empty()) {
            ret = (ret + buy_q.top()[1]) % MOD;
            buy_q.pop();
        }
        while(!sell_q.empty()) {
            ret = (ret + sell_q.top()[1]) % MOD;
            sell_q.pop();
        }
        
        return ret;
    }
};
