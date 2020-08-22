class Solution {
public:
    string makeGood(string s) {
      int n = s.size();
      vector<int> stk;
      string ret="";
      for(int i=0; i<n; i++){
        int cur = (int)s[i];
        if(ret.size()>0 && ((int)ret.back()^(1<<5))==cur){ret.pop_back(); continue;}
        ret.push_back((char)cur);
      }
      return ret;
    }
};
