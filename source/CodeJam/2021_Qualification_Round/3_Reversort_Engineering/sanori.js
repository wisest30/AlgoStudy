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

function reverse(arr, i, j) {
  while (i < j) {
    const t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
    i++, --j;
  }
}

/**
 * 
 * @param {Number} n
 * @param {Number} c
 * @returns {Number []}
 */
function solve(n, c) {
  if (c < n - 1 || c > ((n + 1) * n)/2 - 1) {
    return null;
  }
  const res = Array(n).fill(null).map((x,i) => i + 1);
  let remain = c - n + 1;
  for (let i = n - 2; i >= 0; --i) {
    // console.error({i, remain, res});
    if (remain > 0) {
      const cut = Math.min(n - i - 1, remain);
      reverse(res, i, i + cut);
      remain -= cut;
    }
  }
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const [n, c] = (await getLine()).split(' ').map(Number);
    const res = solve(n, c);
    console.log(`Case #${i+1}:`, res ? res.join(' ') : 'IMPOSSIBLE');
  }
}

if (require.main === module) {
  main();
}