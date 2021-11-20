class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        // sz를 rows로 나누면 column
        int cols = encodedText.size()/rows;
        
        vector<string> board(rows, string(cols, ' '));
        
        int r = 0, c = 0, cur = 0;
        
        while(cur < encodedText.size())
        {
            board[r][c] = encodedText[cur++];
            c++;
            if(c == cols)
            {
                r++;
                c = 0;
            }
        }
        
        string ans;
        
        for(int i=0;i<cols;i++)
        {
            for(int j=0;j+i<cols && j<rows;j++) ans += board[j][j+i];
        }
        
        while(ans.back() == ' ') ans.pop_back();
        
        return ans;
    }
};
