class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& prefs, vector<vector<int>>& pairs) {
      vector<int> met(n);
      for(int i=0; i<pairs.size(); i++){
        int l = pairs[i][0];
        int r = pairs[i][1];
        met[l] = r;
        met[r] = l;
      }
      auto more_pref = [&](int who, int whom)->bool{
        int ix, nix;
        for(int i=0; i<n-1; i++){
          if(prefs[who][i]==whom) nix=i;
          if(prefs[who][i]==met[who]) ix=i;
        }
        if(nix<ix) return true;
        else return false;
      };
      int ans = 0;
      for(int who=0; who<n; who++){
        for(int i=0; i<n-1; i++){
          int whom = prefs[who][i];
          if(whom==met[who]) break;
          if(more_pref(whom, who)){ans++; break;}
        }
      }
      return ans;
    }
};
