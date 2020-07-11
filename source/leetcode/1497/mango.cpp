#include <cstdlib>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k);
        for(int i = 0; i < arr.size(); i++){
            if( arr[i] < 0)
                arr[i] = (k + arr[i]%k) % k;
            else
                arr[i] %= k;
            count[arr[i]]++;
        }
        if( count[0] && count[0]%2)
            return false;
        for(int i = 1; i <= k/2; i++){
            if( count[i] != count[k-i])
                return false;
        }
        return true;
    }
};
