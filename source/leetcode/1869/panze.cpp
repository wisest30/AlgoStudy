class Solution {
public:
    bool checkZeroOnes(string s) {
        int longest[2] = {0, 0};
        
        char now = '0';
        int cnt = 0;
        for (const auto &c : s) {
          if (c == now) {
             cnt++; 
          } else {
              longest[now - '0'] = cnt > longest[now - '0'] ? cnt : longest[now - '0'];
              now = c;
              cnt = 1;
          }
        }
        longest[now - '0'] = cnt > longest[now - '0'] ? cnt : longest[now - '0'];
      
        return longest[1] > longest[0];
    }
};