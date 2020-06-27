#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<PII> pq;
        unordered_map<int, int> count;
        for(int i = 0; i < arr.size(); i++){
            count[arr[i]]++;
        }
        
        for(auto it = count.begin(); it != count.end(); it++){
            pq.push(PII(-(*it).second, (*it).first));
        }
        
        while(k){
            PII top = pq.top();
            pq.pop();
            
            if( -top.first <= k){
                k += top.first;
            }
            else{
                pq.push(PII( -(-top.first-k), top.second));
                k = 0;
            }
        }
        
        return pq.size();
        
    }
private:
    typedef pair<int,int> PII;
};
