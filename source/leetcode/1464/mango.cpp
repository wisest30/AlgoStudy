#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum[2];
        maxNum[0] = nums[0];
        maxNum[1] = nums[1];
        if( maxNum[0] < maxNum[1])
            swap(maxNum[0], maxNum[1]);
        for(int i = 2; i < nums.size(); i++){
            for(int j=0 ;j < 2; j++){
                if( maxNum[j] < nums[i]){
                    if( !j )
                        maxNum[1] = maxNum[0];
                    maxNum[j] = nums[i];
                    break;
                }
            }
        }
        return (maxNum[0] - 1) * (maxNum[1] - 1);
    }
};
