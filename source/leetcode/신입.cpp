class Solution {
public:
    int fenwick[1'00000+5];
    int N;
    
    void update(int idx, int newVal)
    {
        for(;idx<=N;idx+=(idx&(-idx))) fenwick[idx] = max(fenwick[idx], newVal);
    }
    
    int getMx(int idx)
    {
        int ret = 0;
        for(;idx>0;idx-=(idx&(-idx)))
        {
            ret = max(ret, fenwick[idx]);
        }
        return ret;
    }
    
    int minOperations(vector<int>& target, vector<int>& arr) {
        map<int, vector<int>> arrIdxes;
        N = (int)arr.size();
        int ans = 0;
        
        for(int i=0;i<N;i++) arrIdxes[arr[i]].push_back(i+1);
        
        for(int num : target)
        {
            vector<int> updateVal;
            for(int idx : arrIdxes[num])
            {
                int mxLen = getMx(idx)+1;
                updateVal.push_back(mxLen);
                ans = max(ans, mxLen);
            }
            for(int i=0;i<arrIdxes[num].size();i++) update(arrIdxes[num][i], updateVal[i]);
        }
        
        return (int)target.size()-ans;
    }
};
