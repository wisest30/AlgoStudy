function canMouseWin(grid: string[], catJump: number, mouseJump: number): boolean {
  const m = grid.length;
  if (m < 1) {
    return false;
  }
  const n = grid[0].length;
  type Pos = [number, number];
  
  let catPos: Pos, mousePos: Pos;
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (grid[r][c] === 'C') {
        catPos = [r, c];
        grid[r] = grid[r].replace('C', '.');
      } else if (grid[r][c] === 'M') {
        mousePos = [r, c];
        grid[r] = grid[r].replace('M', '.');
      }
    }
  }
  
  const memo = {};
  
  function toIdx(cPos: Pos, mPos: Pos, turn: number) {
    const cc = cPos[0] * 10 + cPos[1];
    const mm = mPos[0] * 10 + mPos[1];
    return `${cc},${mm},${turn}`;
  }
  
  const dirs = [0, 1, 0, -1, 0];
  function traverse(cPos: Pos, mPos: Pos, turn: number = 0): boolean {
    if (turn >= 100) return false;
    const cTurn = ((turn % 2) === 1);
    const idx = toIdx(cPos, mPos, turn);
    if (memo[idx] === undefined) {
      let res = false;
      if (cTurn) {
        res = true;
        for (let d = 0; d < 4; d++) {
          for (let j = 1; j <= catJump; j++) {
            const nr = cPos[0] + j * dirs[d];
            const nc = cPos[1] + j * dirs[d+1];
            if (nr < 0 || m <= nr || nc < 0 || n <= nc ||
                grid[nr][nc] === '#' ) break;
            if (grid[nr][nc] === 'F' ||
                (nr === mPos[0] && nc === mPos[1]) ||
                !traverse([nr, nc], mPos, turn+1)) {
              res = false;
              break;
            }
          }
          if (!res) {
            break;
          }
        }
        if (res) {
          res = traverse(cPos, mPos, turn + 1);
        }
      } else {
        res = false;
        for (let d = 0; d < 4; d++) {
          for (let j = 1; j <= mouseJump; j++) {
            const nr = mPos[0] + j * dirs[d];
            const nc = mPos[1] + j * dirs[d+1];
            if (nr < 0 || m <= nr || nc < 0 || n <= nc ||
                grid[nr][nc] === '#') break;
            if (nr === cPos[0] && nc === cPos[1]) continue;
            if (grid[nr][nc] === 'F' || traverse(cPos, [nr, nc], turn+1)) {
              res = true;
              break;
            }
          }
          if (res) {
            break;
          }
        }
        if (!res) {
          res = traverse(cPos, mPos, turn+1);
        }
      }
      memo[idx] = res;
    }
    return memo[idx];
  }
  const res = traverse(catPos, mousePos);
  // console.log({memo});
  return res;
};