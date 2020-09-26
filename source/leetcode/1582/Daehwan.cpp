class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
      int n = mat.size();
      int m = mat[0].size();
      vector<int> row_cnt(n,0);
      for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
          if(mat[y][x]==1) row_cnt[y]++;
        }
      }
      int ans=0;
      for(int x=0; x<m; x++){
        int candi = 0;
        for(int y=0; y<n; y++){
          if(mat[y][x]==1 && row_cnt[y]>1){candi=0; break;}
          if(mat[y][x]==1 && row_cnt[y]==1) candi++;
        }
        if(candi==1) ans++;
      }
      return ans;
    }
};
