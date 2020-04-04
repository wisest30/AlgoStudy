class Solution {
	public:
		bool hasValidPath(vector<vector<int>>& grid) {
			int m = grid.size();
			int n = grid[0].size();
			vector<vector<bool>> v(m,vector<bool>(n,false));
			function<bool(int,int,char)> dfs = [&](int y, int x, char last)->bool{
				if(y<0||y>m-1||x<0||x>n-1||v[y][x]) return false;	
				if(last=='l' && (grid[y][x]==2||grid[y][x]==3||grid[y][x]==5)) return false;
				if(last=='r' && (grid[y][x]==2||grid[y][x]==4||grid[y][x]==6)) return false;
				if(last=='u' && (grid[y][x]==1||grid[y][x]==5||grid[y][x]==6)) return false;
				if(last=='d' && (grid[y][x]==1||grid[y][x]==3||grid[y][x]==4)) return false;

				if(y==m-1 && x==n-1) return true;
				
        v[y][x] = true;
				if(grid[y][x]==1) return dfs(y,x+1,'r')||dfs(y,x-1,'l');
				if(grid[y][x]==2) return dfs(y+1,x,'d')||dfs(y-1,x,'u');
				if(grid[y][x]==3) return dfs(y+1,x,'d')||dfs(y,x-1,'l');
				if(grid[y][x]==4) return dfs(y+1,x,'d')||dfs(y,x+1,'r');
				if(grid[y][x]==5) return dfs(y-1,x,'u')||dfs(y,x-1,'l');
				if(grid[y][x]==6) return dfs(y-1,x,'u')||dfs(y,x+1,'r');
				return false;
			};
			return dfs(0,0,'a');
		}
};
