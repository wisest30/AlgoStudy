class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        map<int, int> prvIdx;
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(prvIdx.count(cards[i])) ans = min(ans, i - prvIdx[cards[i]] + 1);        
            prvIdx[cards[i]] = i;
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
