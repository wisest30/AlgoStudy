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
 * @param {Number} x
 * @param {Number} y
 * @returns {Number}
 */
function solve(s, x, y) {
  const n = s.length;
  let res = 0;
  let last = s[0];
  for (let i = 1; i < n; i++) {
    if (s[i] === '?') continue;
    if (s[i] === 'C') {
      if (last === 'J') {
        res += y;
      }
    } else {
      if (last === 'C') {
        res += x;
      }
    }
    last = s[i];
  }
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const [x, y, s] = (await getLine()).split(' ');
    const res = solve(s, Number(x), Number(y));
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}