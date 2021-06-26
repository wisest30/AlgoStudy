class Solution {
public:
    map<int, pair<int, int>> memo;
    set<int> visit;
    
    pair<int, int> res;
    
    void recursion(int n, int idx, vector<int> &arr, int firstP, int secondP, int curBit, pair<int, int>& res)
    {
        if(idx == (int)arr.size()/2)
        {
            pair<int, int> temp = getMemo(n, curBit, firstP, secondP);
            res.first = min(res.first, temp.first+1);
            res.second = max(res.second, temp.second+1);
            return;
        }
        
        int l = arr[idx];
        int r = arr[(int)arr.size()-1-idx];
        
        if(l == firstP || l == secondP) recursion(n, idx+1, arr, firstP, secondP, curBit | (1<<l), res);
        else if(r == firstP || r == secondP) recursion(n, idx+1, arr, firstP, secondP, curBit | (1<<r), res);
        else
        {
            recursion(n, idx+1, arr, firstP, secondP, curBit | (1<<l), res);
            recursion(n, idx+1, arr, firstP, secondP, curBit | (1<<r), res);
        }
    }
    
    pair<int, int> getMemo(int n, int bits, int firstP, int secondP)
    {
        if(visit.find(bits) != visit.end()) return memo[bits];
        
        visit.insert(bits);
        pair<int, int> &ret = memo[bits];
        
        vector<int> idxes;
        int firstPos = -1;
        int secondPos = -1;
        
        for(int i=0;i<n;i++)
        {
            if(bits&(1<<i)) 
            {
                idxes.push_back(i);
                if(i == firstP) firstPos = (int)idxes.size()-1;
                if(i == secondP) secondPos = (int)idxes.size()-1;
            }
        }
        
        if(firstPos + secondPos == (int)idxes.size()-1) return ret = {1, 1};
        
        ret.first = INT_MAX;
        ret.second = INT_MIN;
        int curBit = 0;
        
        if(idxes.size()%2 == 1) curBit |= (1<<idxes[(int)idxes.size()/2]);
        recursion(n, 0, idxes, firstP, secondP, curBit, ret);
        
        return ret;
    }
    
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        pair<int, int> temp = getMemo(n, (1<<n)-1, firstPlayer-1, secondPlayer-1);
        return {temp.first, temp.second};
    }
};
