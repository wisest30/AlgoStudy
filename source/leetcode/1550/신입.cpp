class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=0;i+2<arr.size();i++)
        {
            if(arr[i]%2 && arr[i+1]%2 && arr[i+2]%2) return true;
        }
        return false;
    }
};
