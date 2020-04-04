package leetcode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class JiHaeng {
	// left, right, upper, down
	private static int[][] dirs = new int[][] {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

	public boolean hasValidPath(int[][] grid) {
		Map<Integer, int[]> streetMap = new HashMap<>();
		streetMap.put(1, new int[] {0, 1}); // left, right
		streetMap.put(2, new int[] {2, 3});
		streetMap.put(3, new int[] {0, 3});
		streetMap.put(4, new int[] {1, 3});
		streetMap.put(5, new int[] {0, 2});
		streetMap.put(6, new int[] {1, 2});

		int m = grid.length;
		int n = grid[0].length;
		boolean[][] visited = new boolean[m][n];

		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {0, 0});
		visited[0][0] = true;

		while (!q.isEmpty()) {
			int[] cur = q.poll();
			if (cur[0] == m - 1 && cur[1] == n - 1) {
				return true;
			}

			int street = grid[cur[0]][cur[1]];
			for (int dir : streetMap.get(street)) {
				int nextRow = cur[0] + dirs[dir][0];
				int nextCol = cur[1] + dirs[dir][1];

				if (isInGrid(nextRow, nextCol, m, n)
					&& !visited[nextRow][nextCol]
					&& isConnected(dir, streetMap.get(grid[nextRow][nextCol]))) {

					q.offer(new int[] {nextRow, nextCol});
					visited[nextRow][nextCol] = true;
				}
			}
		}

		return false;
	}

	private boolean isInGrid(int row, int col, int m, int n) {
		return row >= 0 && row < m && col >= 0 && col < n;
	}

	private boolean isConnected(int curDir, int[] nextDirs) {
		if (curDir == 0 && (nextDirs[0] == 1 || nextDirs[1] == 1)) {
			return true;
		}

		if (curDir == 1 && (nextDirs[0] == 0 || nextDirs[1] == 0)) {
			return true;
		}

		if (curDir == 2 && (nextDirs[0] == 3 || nextDirs[1] == 3)) {
			return true;
		}

		if (curDir == 3 && (nextDirs[0] == 2 || nextDirs[1] == 2)) {
			return true;
		}
		return false;
	}
}