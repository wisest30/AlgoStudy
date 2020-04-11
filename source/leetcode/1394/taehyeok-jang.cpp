
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> dict;
        for(auto n: arr) {
            dict[n]++;
        }
        int res = -1;
        for(auto it=dict.begin(); it!=dict.end(); it++) {
            if(it->first==it->second) {
                res = it->first;
            }
        }
        return res;
    }
};

