class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        set<int> s;
        for(auto& n : arr){m[n]++;}
    
        vector<int> c;
        int ans = m.size();
        for(auto& i : m){c.push_back(i.second);}
        sort(c.begin(), c.end());
        for(auto& i : c){
            k -= i;
            if(k<0) break;
            else ans--;
        }
        return ans;
    }
    
};
