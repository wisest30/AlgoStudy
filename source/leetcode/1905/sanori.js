/**
 * @param {number[][]} grid1
 * @param {number[][]} grid2
 * @return {number}
 */
 var countSubIslands = function(grid1, grid2) {
  const m = grid1.length;
  const n = grid1[0].length;
  
  const dirs = [0, 1, 0, -1, 0];
  let comps1 = Array(m).fill(null).map(() => Array(n).fill(0));
  let comps2 = Array(m).fill(null).map(() => Array(n).fill(0));
  const genDfs = (gid = 1) => {
    const grid = (gid === 1) ? grid1 : grid2;
    const comps = (gid === 1) ? comps1 : comps2;
    const dfs = (r, c, comp=1) => {
      if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] !== 1 || comps[r][c] !== 0) {
        return;
      }
      comps[r][c] = comp;
      for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i], nc = c + dirs[i+1];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] !== 1 || comps[nr][nc] !== 0) {
          continue;
        }
        dfs(nr, nc, comp);
      }
    };
    return dfs;
  };
  
  const dfs1 = genDfs(1);
  for (let r = 0, comp = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (grid1[r][c] === 1 && comps1[r][c] === 0) {
        comp++;
        dfs1(r, c, comp);
      }
    }
  }
  const dfs2 = genDfs(2);
  for (let r = 0, comp = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (grid2[r][c] === 1 && comps2[r][c] === 0) {
        comp++;
        dfs2(r, c, comp);
      }
    }
  }
  // console.log({comps1, comps2});
  
  const isSubset = (a, b) => {
    for (const e of a) {
      if (!b.has(e)) {
        return false;
      }
    }
    return true;
  };
  
  const comps1Sets = [];
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (comps1[r][c] !== 0) {
        const idx = comps1[r][c] - 1;
        if (comps1Sets[idx] === undefined) {
          comps1Sets[idx] = new Set();
        }
        comps1Sets[idx].add(r * 1000 + c);
      }
    }
  }
  
  const comps2Sets = [];
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (comps2[r][c] !== 0) {
        const idx = comps2[r][c] - 1;
        if (comps2Sets[idx] === undefined) {
          comps2Sets[idx] = new Set();
        }
        comps2Sets[idx].add(r * 1000 + c);
      }
    }
  }
  
  // console.log({comps1Sets, comps2Sets});
  let res = 0;
  for (const s of comps2Sets) {
    const elem = Array.from(s)[0];
    const r = Math.floor(elem / 1000);
    const c = elem % 1000;
    const idx1 = comps1[r][c];
    // console.log({s, r, c, idx1});
    if (idx1 === 0) { continue };
    if (isSubset(s, comps1Sets[idx1-1])) {
      res++;
    };
  }
  return res;
};
