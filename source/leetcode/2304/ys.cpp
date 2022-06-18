#include <iostream>
#include <vector>

using namespace std;

const int LIMIT = 12345;
vector<vector<int>> s_grid;
vector<vector<int>> s_moveCost;
int R, C;

int cache[50][50] = {
	0,
};

int process(int row, int col)
{
	if (row == R - 1)
	{
		return s_grid[row][col];
	}

	if (cache[row][col] > 0)
	{
		return cache[row][col];
	}

	int value = s_grid[row][col];
	auto &costs = s_moveCost[value];

	int res = LIMIT;
	for (int c = 0; c < C; ++c)
	{
		res = std::min(res, value + costs[c] + process(row + 1, c));
	}

	return cache[row][col] = res;
}

int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
{
	R = grid.size();
	C = grid.front().size();
	s_grid = std::move(grid);
	s_moveCost = std::move(moveCost);

	int res = LIMIT;
	for (int c = 0; c < C; ++c)
	{
		res = std::min(res, process(0, c));
	}
	return res;
}
