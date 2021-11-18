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

const trans = {
  U: 0, R: 4, Y: 2, B: 1,
  O: 6, P: 5, G: 3, A: 7
};

/**
 *
 * @param {String} p
 * @returns {Number}
 */
function solve(p) {
  const n = p.length;
  const bits = p.split('').map(x => trans[x]);

  let res = 0;
  for (let i = 0; i < 3; i++) {
    const mask = 1 << i;
    let last = 0;
    for (let j = 0; j < n; j++) {
      if (bits[j] & mask) {
        if (last === 0) {
          res++;
          last = 1;
        }
      } else {
        last = 0;
      }
    }
  }
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const p = (await getLine());
    const res = solve(p);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}
