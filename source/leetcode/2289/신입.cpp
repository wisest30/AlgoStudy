class Solution {
public:
    int tree[4'00000+5];
    
    void upd(int node, int s, int e, int idx, int target)
    {
        if(idx < s || idx > e) return;
        if(s == e)
        {
            tree[node] = target;
            return;
        }
        
        upd(node*2, s, (s+e)/2, idx, target);
        upd(node*2+1, (s+e)/2+1, e, idx, target);
        
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
    
    int get(int node, int s, int e, int l, int r)
    {
        if(s >= l && e <= r) return tree[node];
        if(s > r || e < l) return 0;
        
        return max(get(node*2, s, (s+e)/2, l, r), get(node*2+1, (s+e)/2+1, e, l, r));
    }
    
    int totalSteps(vector<int>& nums) {
        int N = nums.size();
        stack<int> idxStack;
        
        vector<int> left(N);
        
        int ans = 0;
        
        for(int i=0;i<N;i++)
        {
            while(!idxStack.empty() && nums[idxStack.top()] <= nums[i]) idxStack.pop();
            if(idxStack.empty()) 
            {
                idxStack.push(i);
                continue;
            }
            else left[i] = idxStack.top();
            
            idxStack.push(i);
            
            int res = get(1, 0, N-1, left[i]+1, i-1);
            
            ans = max(ans, res+1);
            upd(1, 0, N-1, i, res+1);
            
        }
        
        return ans;
    }
};
