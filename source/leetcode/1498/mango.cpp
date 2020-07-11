#include <algorithm>
using namespace std;
class Solution {
private:
    int mod = 1000000007;
public:
    int numSubseq(vector<int>& nums, int target) {
        int num = 0;
        vector<int> d(nums.size(), 1);
        
        for(int i = 1; i < d.size(); i++){
          d[i] = (d[i-1] * 2) % mod;
        }
        
        sort(nums.begin(), nums.end());
        
        if(nums.empty() || nums[0] > target)
            return 0;
        
        int end = 0;
        while(end + 1 < nums.size() && nums[0] + nums[end + 1] <= target)
            end++;
        
        for(int i = 0 ; i < nums.size(); i++){
            if( nums[i] * 2 > target )
                break;
            
            while(end > i && nums[i] + nums[end] > target){
                end--;
            }
            num = (num + d[end - i])% mod;
        }
        
        
        return (int)num;
    }
};
