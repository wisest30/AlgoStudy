struct Entity
{
	int two;
	int five;
};

Entity operator-(const Entity& a, const Entity& b)
{
	Entity res;

	res.two = a.two - b.two;
	res.five = a.five - b.five;

	return res;
}

Entity operator+(const Entity& a, const Entity& b)
{
	Entity res;

	res.two = a.two + b.two;
	res.five = a.five + b.five;

	return res;
}

struct Cell
{
	int r;
	int c;
};

class Solution {
public:
	int R;
	int C;

	int getZeros(vector<vector<Entity>>& cumulativeColumnGrid, vector<vector<Entity>>& cumulativeRowGrid, Cell from, Cell to)
	{
		if (from.r == 0 && from.c == 2 && to.r == 3 && to.c == 4)
		{
			from.r = 0;
		}

		// column 먼저
		Entity columnEntity{};
		int columnFirstRes = INT_MAX;

		if (from.c < to.c)
		{
			if (from.c == 0) columnEntity = cumulativeColumnGrid[from.r][to.c - 1];
			else columnEntity = cumulativeColumnGrid[from.r][to.c - 1] - cumulativeColumnGrid[from.r][from.c - 1];
		}
		else columnEntity = cumulativeColumnGrid[from.r][from.c] - cumulativeColumnGrid[from.r][to.c];

		if (from.r < to.r)
		{
			if (from.r == 0) columnEntity = columnEntity + cumulativeRowGrid[to.r][to.c];
			else columnEntity = columnEntity + cumulativeRowGrid[to.r][to.c] - cumulativeRowGrid[from.r - 1][to.c];
		}
		else
		{
			if (to.r == 0) columnEntity = columnEntity + cumulativeRowGrid[from.r][to.c];
			else columnEntity = columnEntity + cumulativeRowGrid[from.r][to.c] - cumulativeRowGrid[to.r - 1][to.c];
		}
		columnFirstRes = min(columnEntity.two, columnEntity.five);

		// row 먼저
		Entity rowEntity{};
		int rowFirstRes = INT_MAX;

		if (from.r < to.r)
		{
			if (from.r == 0) rowEntity = cumulativeRowGrid[to.r - 1][from.c];
			else rowEntity = cumulativeRowGrid[to.r - 1][from.c] - cumulativeRowGrid[from.r - 1][from.c];
		}
		else rowEntity = cumulativeRowGrid[from.r][from.c] - cumulativeRowGrid[to.r][from.c];

		if (from.c < to.c)
		{
			if (from.c == 0) rowEntity = rowEntity + cumulativeColumnGrid[to.r][to.c];
			else rowEntity = rowEntity + cumulativeColumnGrid[to.r][to.c] - cumulativeColumnGrid[to.r][from.c - 1];
		}
		else
		{
			if (to.c == 0) rowEntity = rowEntity + cumulativeColumnGrid[to.r][from.c];
			else rowEntity = rowEntity + cumulativeColumnGrid[to.r][from.c] - cumulativeColumnGrid[to.r][to.c - 1];
		}
		rowFirstRes = min(rowEntity.two, rowEntity.five);

		return max(columnFirstRes, rowFirstRes);
	}

	int maxTrailingZeros(vector<vector<int>>& grid) {
		R = grid.size();
		C = grid[0].size();

		vector<vector<Entity>> entityGrid(R, vector<Entity>(C, { 0, 0 }));
		vector<vector<Entity>> cumulativeColumnGrid(R, vector<Entity>(C, { 0, 0 }));
		vector<vector<Entity>> cumulativeRowGrid(R, vector<Entity>(C, { 0, 0 }));

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				while (grid[i][j] % 2 == 0)
				{
					grid[i][j] /= 2;
					entityGrid[i][j].two++;
				}
				while (grid[i][j] % 5 == 0)
				{
					grid[i][j] /= 5;
					entityGrid[i][j].five++;
				}

				if (j == 0) cumulativeColumnGrid[i][j] = entityGrid[i][j];
				else
				{
					cumulativeColumnGrid[i][j].two = cumulativeColumnGrid[i][j - 1].two + entityGrid[i][j].two;
					cumulativeColumnGrid[i][j].five = cumulativeColumnGrid[i][j - 1].five + entityGrid[i][j].five;
				}

				if (i == 0) cumulativeRowGrid[i][j] = entityGrid[i][j];
				else
				{
					cumulativeRowGrid[i][j].two = cumulativeRowGrid[i - 1][j].two + entityGrid[i][j].two;
					cumulativeRowGrid[i][j].five = cumulativeRowGrid[i - 1][j].five + entityGrid[i][j].five;
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < R; i++) ans = max(ans, getZeros(cumulativeColumnGrid, cumulativeRowGrid, { i, 0 }, { i, C - 1 }));
		for (int i = 0; i < C; i++) ans = max(ans, getZeros(cumulativeColumnGrid, cumulativeRowGrid, { 0, i }, { R - 1, i }));

		vector<Cell> rowCells, columnCells;

		for (int i = 0; i < C; i++)
		{
			rowCells.push_back({ 0, i });
			rowCells.push_back({ R - 1, i });
		}
		for (int i = 0; i < R; i++)
		{
			columnCells.push_back({ i, 0 });
			columnCells.push_back({ i, C - 1 });
		}

		for (int i = 0; i < rowCells.size(); i++)
		{
			for (int j = 0; j < columnCells.size(); j++)
			{
				int res = getZeros(cumulativeColumnGrid, cumulativeRowGrid, rowCells[i], columnCells[j]);
				ans = max(ans, res);
			}
		}

		return ans;
	}
};
