#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<PII> arrIdxPair;
        vector<int> strongest;
        priority_queue<PII> pq;
        int m;
        for(int i = 0; i < arr.size(); i++){
            arrIdxPair.push_back(PII(arr[i], i));
        }
        
        sort(arrIdxPair.begin(), arrIdxPair.end());

        
        if( arr.size() % 2)
            m = arrIdxPair[arr.size()/2].first;
        else
            m = arrIdxPair[arr.size()/2 - 1].first;
        for(int i = 0; i < arrIdxPair.size(); i++){
            pq.push(PII(-abs(arrIdxPair[i].first - m), -arrIdxPair[i].first));
            if( pq.size() > k)
                pq.pop();
        }
        
        while(!pq.empty()){
            strongest.push_back(-pq.top().second);
            pq.pop();
        }
        reverse(strongest.begin(), strongest.end());
        return strongest;
        
        
    }
private:
    typedef pair<int, int> PII;
};
