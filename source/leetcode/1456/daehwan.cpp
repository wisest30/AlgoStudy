class Solution {
public:
    int maxVowels(string s, int k) {
        int l = s.length();
        vector<int> pref(l,0);
        auto f = [](char c)->int{
            if(c=='a'|c=='e'|c=='i'|c=='o'|c=='u') return 1;
            else return 0;
        };
        pref[0] = f(s[0]);
        for(int i=1; i<l; i++){
            pref[i] = pref[i-1] + f(s[i]);
        }
        int ret = pref[k-1];
        for(int i=k; i<l; i++){
            ret = max(ret, pref[i]-pref[i-k]);
        }
        return ret;
    }
};
