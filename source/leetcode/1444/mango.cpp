#include <vector>
using namespace std;
#define mod 1000000007
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int row = pizza.size();
        int col = pizza[0].size();
        vector<vector<int>> apple_sum = vector<vector<int>>(row, vector<int>(col));
        vector<vector<vector<int>>> visit(row, vector<vector<int>>(col, vector<int>(k + 1, -1)));
        for(int i = 0; i < row; i++){
            for(int j = 0; j< col; j++){
                if( i )
                    apple_sum[i][j] += apple_sum[i-1][j];
                if( j )
                    apple_sum[i][j] += apple_sum[i][j-1];
                if( i && j )
                    apple_sum[i][j] -= apple_sum[i-1][j-1];
                if( pizza[i][j] == 'A')
                    apple_sum[i][j]++;
                apple_sum[i][j] %= mod;
            }
            
        }
        
        int num_ways = cut_pizza(apple_sum, visit, 0, 0, k - 1, apple_sum[row-1][col-1]);
        
        return num_ways;
    }
private:
    int cut_pizza(vector<vector<int>> &apple_sum, vector<vector<vector<int>>>& visit, int x, int y, int k, int remain){
        if( !k ){
            return 1;
        }
        if( visit[x][y][k] != -1)
            return visit[x][y][k];
        
        int num_cut = 0;
        int r = apple_sum.size() - 1;
        int c = apple_sum[0].size() - 1;
        for(int i = x + 1; i <= r; i++){
            int piece = apple_sum[i-1][c] - (x > 0? apple_sum[x-1][c]:0) - (y > 0 ? apple_sum[i-1][y-1]:0) + (x > 0 && y > 0 ? apple_sum[x-1][y-1]:0);
            if(piece && (remain - piece))
                num_cut += cut_pizza(apple_sum, visit, i, y , k - 1, remain - piece);
            num_cut %=mod;
        }
        for(int j = y+1; j <= c; j++){
            int piece = apple_sum[r][j-1] - (x > 0? apple_sum[x-1][j-1]:0) - (y > 0 ? apple_sum[r][y-1]:0) + (x > 0 && y > 0 ? apple_sum[x-1][y-1]:0);
            if(piece && (remain - piece))
                num_cut += cut_pizza(apple_sum, visit, x, j , k - 1, remain - piece);
            num_cut %=mod;
        }
        visit[x][y][k] = num_cut;
        return num_cut;
    }
};
