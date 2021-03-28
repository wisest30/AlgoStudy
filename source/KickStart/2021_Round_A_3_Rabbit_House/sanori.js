#!/usr/bin/env node
'use strict';

const { createInterface } = require('readline');
const rl = createInterface({
  input: process.stdin,
  crlfDelay: Infinity
});

const buf = [];
const prom = [];
let maxBuf = 0;
let maxProm = 0;
rl.on('line', (line) => {
  if (prom.length > 0) {
    maxProm = Math.max(maxProm, prom.length);
    const [resolve, reject] = prom.shift();
    resolve(line);
  } else {
    rl.pause();
    buf.push(line);
    maxBuf = Math.max(maxBuf, buf.length);
  }
});

rl.on('close', () => {
  // console.error({maxProm, maxBuf});
});

async function getLine() {
  return new Promise((resolve, reject) => {
    if (buf.length > 0) {
      const line = buf.shift();
      resolve(line);
    } else {
      prom.push([resolve, reject]);
      rl.resume();
    }
  });
}

function idx(r, c) {
  return r * 10000 + c;
}
/**
 *
 * @param {Number[][]} grid
 * @returns {Number}
 */
function solve(grid) {
  const m = grid.length;
  const n = grid[0].length;
  const dirs = [0, 1, 0, -1, 0];
  let res = 0;
  const peaks = [];
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i];
        const nc = c + dirs[i+1];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n ) continue;
        if (grid[r][c] - grid[nr][nc] > 1) {
          peaks.push([grid[r][c], r, c]);
          break;
        }
      }
    }
  }
  peaks.sort((a,b) => a[0] - b[0]);

  while (peaks.length > 0) {
    const [maxH, maxR, maxC] = peaks.pop();
    if (grid[maxR][maxC] > maxH) { // updated
      continue;
    }
    const checked = new Set();
    const q = [[maxR, maxC]];
    while (q.length > 0) {
      const [r, c] = q.shift();
      if (checked.has(idx(r, c))) {
        continue;
      }
      const h = grid[r][c];
      for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i];
        const nc = c + dirs[i+1];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
          checked.has(idx(nr, nc))) {
            continue;
          }
        if (Math.abs(h - grid[nr][nc]) <= 1) {
          q.push([nr, nc]);
        } else if (h > grid[nr][nc]){
          res += h - grid[nr][nc] - 1;
          grid[nr][nc] = h - 1;
          q.push([nr, nc]);
        }
      }
      checked.add(idx(r, c));
    }
  }
  // console.error({grid});
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const [m, n] = (await getLine()).split(' ').map(Number);
    const grid = Array(m);
    for (let j = 0; j < m; j++) {
      grid[j] = (await getLine()).split(' ').map(Number);
    }
    const res = solve(grid);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}

