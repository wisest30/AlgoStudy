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
const mod = 1e9 + 7;
function solve(w) {
  const n = w.length;
  const lefts = [], rights = [];
  let cur = '', res = 0;
  let firstX = -1, lastX = -1;
  let firstO = -1, lastO = -1;
  for (let i = 0; i < n; i++) {
    if (w[i] === 'O') {
      if (cur === 'X') {
        firstO = i;
        if (firstX >= 0) {
          rights.push(firstO - firstX);
          const k = rights.length;
          for (let i = 1; i <= k; i++) {
            res = (res + (rights[k - 1] * lefts[k - i] * i) % mod) % mod;
          }
        }
        lefts.push(lastX - lastO);
      }
      cur = 'O';
      lastO = i;
    } else if (w[i] === 'X') {
      if (cur === 'O') {
        firstX = i;
        if (firstO >= 0) {
          rights.push(firstX - firstO);
          const k = rights.length;
          for (let i = 1; i <= k; i++) {
            res = (res + (rights[k - 1] * lefts[k - i] * i) % mod) % mod;
          }
        }
        lefts.push(lastO - lastX);
      }
      cur = 'X';
      lastX = i;
    }
  }
  if (lefts.length > 0) {
    if (cur === 'X') {
      rights.push(n - firstX);
    } else if (cur === 'O') {
      rights.push(n - firstO);
    }
    const k = rights.length;
    for (let i = 1; i <= k; i++) {
      res = (res + (rights[k - 1] * lefts[k - i] * i) % mod) % mod;
    }
  }

  // console.error({ lefts, rights });
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const w = await getLine();
    const res = solve(w);
    console.log(`Case #${i + 1}:`, res);
  }
}

if (require.main === module) {
  main();
}

