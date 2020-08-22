class Solution {
public:
    char findKthBit(int n, int k) {
        string ret = "0";
        for(int i=0; i<n-1; i++){
          string ret2 = ret + "1";
          for(auto& c : ret) c^=1;
          reverse(ret.begin(), ret.end());
          ret2 += ret;
          ret = ret2;
        }
        return ret[k-1];
    }
};
