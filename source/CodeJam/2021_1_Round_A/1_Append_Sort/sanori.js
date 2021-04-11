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
 * @param {Number[]} x
 * @returns {Number}
 */
function solve(x) {
  const n = x.length;
  let res = 0, last = x[0];
  for (let i = 1; i < n; i++) {
    let cur = x[i];
    if (last >= cur) {
      const diffDigits = Math.floor(Math.log10(last)) -
        Math.floor(Math.log10(cur));
      if (diffDigits === 0) {
          cur *= 10;
          res++;
      } else {
        const lo = cur * (10 ** diffDigits);
        const hi = lo + (10 ** diffDigits) - 1;
        if (last < lo) {
          cur = lo;
          res += diffDigits;
        } else if (last >= hi) {
          cur = lo * 10;
          res += diffDigits + 1;
        } else {
          cur = last + 1;
          res += diffDigits;
        }
      }
    }
    last = cur;
  }
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const x = (await getLine()).split(' ').map(Number);
    const res = solve(x);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}