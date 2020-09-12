class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        vector<int> conti(arr.size(), 1);
        int len = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(i-m >= 0 && arr[i] == arr[i-m]) conti[i] = conti[i-m]+1;
            
            if(conti[i] >= k) len++;
            else len = 0;
            
            if(len >= m) return true;
        }
        
        return false;
    }
};
