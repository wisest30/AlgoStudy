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
 * @param {String} s
 * @param {Number} k
 * @returns {Number}
 */
function solve(s, k) {
  const n = s.length;
  let g = 0, lo = 0, hi = n - 1;
  while (hi > lo) {
    if (s[lo] !== s[hi]) {
      g++;
    }
    lo++;
    hi--;
  }
  return Math.abs(k - g);
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const [n, k] = (await getLine()).split(' ').map(Number);
    const s = (await getLine());
    const res = solve(s, k);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}

