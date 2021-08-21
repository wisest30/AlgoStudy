class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q(piles.begin(), piles.end());
        
        for(auto i = 0; i < k; ++i) {
            int num = q.top();
            q.pop();
            q.push((num + 1) / 2);
        }
        
        int ret = 0;
        while(!q.empty()) {
            ret += q.top();
            q.pop();
        }
        
        return ret;
    }
};
