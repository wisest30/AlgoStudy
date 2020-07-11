class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto& i : arr){
            m[(i%k+k)%k]++;
        }
        for(auto& i : arr){
            int key = (i%k+k)%k;
            if(!key && (m[key]&0x01)) return false;
            if(key && (m[key] != m[k-key])) return false;
        }
        return true;
    }
};
