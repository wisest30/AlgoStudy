class Solution {
  public:
    int sumFourDivisors(vector<int>& nums) {
      int sum(0);
      for(auto& n : nums){
        int l(0);
        for(int i=2; i*i<=n; i++){
          if(!(n%i)){
            if(!l) l=i;
            else {l=0; break;}
          }
        }
        if(l>0 && l!=n/l){
          sum += (1+n+l+n/l);
        }
      }
      return sum;
    }
};
