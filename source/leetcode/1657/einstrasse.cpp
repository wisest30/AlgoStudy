class Solution {
public:
    bool closeStrings(string a, string b) {
        if (a.length() != b.length()) return false;
        int num[2][26];
        vector<int> cnt[2];
        memset(num, 0, sizeof(num));
        cnt[0].clear();
        cnt[1].clear();
        for (char c : a) {
            num[0][c - 'a']++;
        }
        for (char c : b) {
            num[1][c - 'a']++;
        }
        //가지고 있는 알파벳 종류가 같아야 한다.
        for (int i=0; i< 26; i++) {
            if ((!!num[0][i]) ^ (!!num[1][i])) return false;
        }
        for (int k=0; k < 2; k++) {
            for (int i=0; i < 26; i++) {
                if (num[k][i])
                    cnt[k].push_back(num[k][i]);
            }
        }
        sort(cnt[0].begin(), cnt[0].end());
        sort(cnt[1].begin(), cnt[1].end());
        
        //가지고 있는 알파뱃 종류별 갯수가 같아야 한다.
        for (int i=0; i < cnt[0].size(); i++) {
            if (cnt[0][i] != cnt[1][i]) return false;
        }
        return true;
    }
};
