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

const aCode = 'a'.charCodeAt(0);
/**
 *
 * @param {String} s
 * @param {String} f
 * @returns {Number}
 */
function solve(s, f) {
  const m = s.length;
  const n = f.length;
  const freq = Array(26).fill(0);
  for (let i = 0; i < m; i++) {
    const c = s.charCodeAt(i) - aCode;
    freq[c]++;
  }
  const fArr = [];
  for (let i = 0; i < n; i++) {
    fArr[i] = f.charCodeAt(i) - aCode;
  }
  let res = 0;
  for (let i = 0; i < 26; i++) {
    if (freq[i] === 0) continue;
    const diffs = fArr.map(x => {
      const diff = Math.abs(x - i);
      return Math.min(diff, 26 - diff);
    })
    res += Math.min(...diffs) * freq[i];
  }
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const s = (await getLine());
    const f = (await getLine());
    const res = solve(s, f);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}
