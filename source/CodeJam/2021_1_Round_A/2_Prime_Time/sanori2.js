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
  const totalSum = cards.reduce((acc, cur) => acc + cur[0] * cur[1], 0n);
  const check = (prod, sumMinus) => {
    // console.error('init', {prod, sumMinus});
    for (let i = 0; i < cards.length; i++) {
      const f = cards[i][0];
      let j = 0;
      while (prod % f == 0) {
        prod /= f;
        sumMinus -= f;
        j++;
      }
      if (j > cards[i][1]) return false;
    }
    // console.error({prod, sumMinus});
    return (prod == 1) && (sumMinus == 0);
  };

  for (let i = 1n; i < totalSum && i < 29941n; i++) {
    if (check(totalSum - i, i)) {
      return totalSum - i;
    }
  }
  return 0n;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const m = Number(await getLine());
    const cards = [];
    for (let j = 0; j < m; j++) {
      const [p, n] = (await getLine()).split(' ').map(BigInt);
      cards.push([p, n]);
    }
    const res = solve(cards);
    console.log(`Case #${i+1}:`, res.toString());
  }
}

if (require.main === module) {
  main();
}