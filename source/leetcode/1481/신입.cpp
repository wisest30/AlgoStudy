class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> countInt;
        auto cmp = [&](const int &a, const int &b) -> bool
        {
            return countInt[a] > countInt[b];
        };
        
        for(int num : arr) countInt[num]++;
        
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        
        for(auto it = countInt.begin() ; it != countInt.end(); it++) pq.push(it->first);
        
        while(!pq.empty() && countInt[pq.top()] <= k)
        {
            k -= countInt[pq.top()];
            pq.pop();
        }
        
        return pq.size();
    }
};
