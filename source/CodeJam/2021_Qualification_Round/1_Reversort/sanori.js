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

/**
 * 
 * @param {Number[]} l
 * @returns {Number}
 */
function solve(l) {
  const n = l.length;
  let res = 0;
  for (let i = 0; i < n - 1; i++) {
    let minVal = l[i], minIdx = i;
    for (let j = i + 1; j < n; j++) {
      if (l[j] < minVal) {
        minVal = l[j];
        minIdx = j;
      }
    }
    res += minIdx - i + 1;
    let lo = i, hi = minIdx;
    while (lo < hi) {
      const t = l[lo];
      l[lo] = l[hi];
      l[hi] = t;
      --hi, lo++;
    }
  }
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const l = (await getLine()).split(' ').map(Number);
    const res = solve(l);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}