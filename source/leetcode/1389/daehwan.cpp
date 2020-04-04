class Solution {
  public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
      int n = nums.size();
      vector<int> ret;
      for(int i=0; ia<n; i++){
        ret.insert(ret.begin()+index[i], nums[i]);
      }
      return ret;
    }
};
