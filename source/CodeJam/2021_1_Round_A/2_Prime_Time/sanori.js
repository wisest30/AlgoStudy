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
 * @param {Number [][]} cards
 * @returns {Number}
 */
function solve(cards) {
  const totalSum = cards.reduce((acc, cur) => acc + cur[0] * cur[1], 0);
  let res = 0;
  const initEntries = cards.slice().sort((a, b) => a[0] - b[0]);
  // console.error({totalSum, initEntries});
  const traverse = (idx = 0, sum=totalSum, prod=1, entries=initEntries) => {
    if (sum === prod) {
      return sum;
    }
    if (sum < prod || idx >= entries.length) {
      return 0;
    }
    const limit = Math.floor(sum / prod);
    let res = traverse(idx + 1, sum, prod, entries);
    const [p, n] = entries[idx];
    for (let j = 1; j <= n && (p ** j) <= limit; j++) {
      const nSum = sum - (j * p);
      const nProd = prod * (p ** j);
      if (nSum < nProd) break;
      if (nSum === nProd) {
        // console.error({idx, j, sum, prod, nSum, nProd, entries});
        res = Math.max(res, nSum);
        break;
      }
      entries[idx][1] -= j;
      res = Math.max(res, traverse(idx + 1, nSum, nProd, entries));
      entries[idx][1] += j;
    }
    return res;
  }

  res = traverse();
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const m = Number(await getLine());
    const cards = [];
    for (let j = 0; j < m; j++) {
      const [p, n] = (await getLine()).split(' ').map(Number);
      cards.push([p, n]);
    }
    const res = solve(cards);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}