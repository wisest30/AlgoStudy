class Solution {
public:
    string robotWithString(string s) {
        multiset<char> ms(s.begin(), s.end());
        stack<char> st;
        string ret;
        for(auto c : s) {
            auto p = ms.find(c);
            ms.erase(p);
            st.push(c);
            
            while(!st.empty() && (ms.empty() || st.top() <= *ms.begin())) {
                ret.push_back(st.top());
                st.pop();
            }
        }
        
        return ret;
    }
};
