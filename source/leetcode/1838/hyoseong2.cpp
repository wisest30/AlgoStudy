namespace {
    class SlidingWindow {
        deque<int> A;
        int64_t su = 0;
    public :
        void push(int x) {
            A.push_back(x);
            su += x;
        }

        void pop() {
            su -= A.front();
            A.pop_front();
        }

        int64_t get_need() {
            return (int64_t)A.size() * A.back() - su;
        }

        size_t size() {
            return A.size();
        }
    };
}

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        SlidingWindow sw;
        auto ret = 0;
        for(auto x : nums) {
            sw.push(x);
            while(sw.get_need() > k)
                sw.pop();
            ret = max(ret, (int)sw.size());
        }
        
        return ret;
    }
};
