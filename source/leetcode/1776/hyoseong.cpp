class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        constexpr double INF = numeric_limits<double>::max();
        int n = cars.size();
        vector<double> ret(n);
        stack<int> st;
        
        // get collision time.
        auto get_ct = [&](auto i, auto j) {
            assert(i < j);
            if(cars[i][1] <= cars[j][1]) return INF;
            return (double)(cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);
        };
        
        ret[n-1] = INF;
        st.push(n-1);
        for(auto i = n-2; i >= 0; --i) {
            auto pos = cars[i][0];
            auto speed = cars[i][1];
            
            while(get_ct(i, st.top()) > ret[st.top()])
                st.pop();
            
            ret[i] = get_ct(i, st.top());
            st.push(i);
        }
        
        for(auto& x : ret)
            if(x == INF) x = -1;

        return ret;
    }
};
