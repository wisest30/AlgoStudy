class Solution {
public:
    int minDeletions(string s) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for (char c : s) {
            freq[c-'a']++;
        }
        vector<int> arr;
        for (int i=0; i<26; i++) {
            if (freq[i]) 
                arr.push_back(freq[i]);
        }
        sort(arr.begin(), arr.end(), greater<int>());
        int need = arr.front();
        int ans = 0;
        for (int item : arr) {
            //cout << item << ' ';
            ans += max(item - need, 0);
            need = max(min(need-1, item-1), 0);
        }
        return ans;
    }
};
