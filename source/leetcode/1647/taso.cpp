class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnts(26, 0);
        for (int i=0; i<s.size(); i++) {
            cnts[s[i]-'a']++;
        }
        priority_queue<int> pq;
        for (int i=0; i<26; i++) {
            if (cnts[i] == 0)
                continue;
            pq.push(cnts[i]);
        }
        int ret = 0;
        int prev = pq.top();
        pq.pop();
        while (!pq.empty()) {
            int cur = pq.top();
            if (prev == cur) {
                ret++;
                pq.pop();
                if (1 < cur)
                    pq.push(cur-1);
            } else {
                pq.pop();
                prev = cur;
            }
        }
        return ret;
    }
};