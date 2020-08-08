class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
      const int MAX = 101;
      int n = (int)s.size();
      int dp[MAX][MAX];
      for(int i=0; i<n; i++) fill(dp[i], dp[i]+n, -1);
      
      auto onetwothree = [](int num)->int{
        if(num==1) return 0;
        else if(num<10) return 1;
        else if(num<100) return 2;
        else return 3;
      };
      
      function<int(int,int)> search = [&](int ix, int k)->int{
        if(ix>=n || n-ix<=k) return 0;
        
        int& ret = dp[ix][k];
        if(ret != -1) return ret;
        
        ret = MAX;
        vector<int> cnt(26,0);
        int most = 0;
        for(int i=ix; i<n; i++){
          most = max(most, ++cnt[s[i]-'a']);
          if(k >= (i-ix+1-most))
            ret = min(ret, 1 + onetwothree(most) + search(i+1,k-(i-ix+1-most)));
        }
        return ret;
      };
      
      return search(0,k);
    }
};
