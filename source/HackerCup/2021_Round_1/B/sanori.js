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

// @brief Solve problem
// @param {Number} n
// @param {Number} m
// @param {Number} a
// @param {Number} b
// @returns {String}
function solve(n, m, a, b) {
  if (a < n + m - 1 || b < n + m - 1) {
    return 'Impossible';
  }
  const resStr = ['Possible'];
  for (let r = 0; r < n - 1; r++) {
    resStr.push(Array(m).fill(1).join(' '));
  }
  const last = Array(m).fill(1);
  last[0] = b - m - n + 2;
  last[m-1] = a - m - n + 2;
  resStr.push(last.join(' '));
  return resStr.join('\n');
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const [n, m, a, b] = (await getLine()).split(' ').map(Number);
    const res = solve(n, m, a, b);
    console.log(`Case #${i + 1}:`, res);
  }
}

if (require.main === module) {
  main();
}

