class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q(nums.begin(), nums.end());
        double su = accumulate(nums.begin(), nums.end(), 0.0);
        double ori_su = su;
        int ret = 0;
        while(su > ori_su / 2) {
            su -= q.top() / 2;
            q.push(q.top() / 2);
            q.pop();
            ++ret;
        }
        
        return ret;
    }
};
