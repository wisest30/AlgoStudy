/**
 * @param {number[][]} heights
 * @return {number}
 */
var minimumEffortPath = function(heights) {
  const m = heights.length;
  if (m < 1) {
    return 0;
  }
  const n = heights[0].length;
  const dist = Array(m).fill(null).map(() => []);
  dist[0][0] = 0;

  const moves = [0, 1, 0, -1, 0];
  const q = [[0,0]];
  while(q.length > 0) {
    const [r, c] = q.shift();
    for (let i = 0; i < 4; i++) {
      const nr = r + moves[i];
      const nc = c + moves[i+1];
      if (nr < 0 || nr >= m || nc < 0 || nc > n) continue;
      const w = Math.abs(heights[r][c] - heights[nr][nc]);
      const nd = Math.max(w, dist[r][c]);
      if (dist[nr][nc] === undefined || dist[nr][nc] > nd) {
        dist[nr][nc] = nd;
        q.push([nr, nc]);
      }
    }
  }
  return dist[m-1][n-1];
};
