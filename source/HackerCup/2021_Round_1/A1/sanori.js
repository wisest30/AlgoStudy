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
// @param {String} s
// @returns {Number}
function solve(w) {
  const n = w.length;
  let cur = '', res = 0;
  for (let i = 0; i < n; i++) {
    if (w[i] === 'O') {
      if (cur === 'X') {
        res++;
      }
      cur = 'O';
    } else if (w[i] === 'X') {
      if (cur === 'O') {
        res++;
      }
      cur = 'X';
    }
  }
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const w = await getLine();
    const res = solve(w);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}

