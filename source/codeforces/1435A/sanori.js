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
 * @param {Number []} a
 * @returns {Number []}
 */
function solve(a) {
  const n = a.length;
  const res = [];
  for (let i = 1; i < n; i += 2) {
    res.push(a[i], -a[i-1]);
  }
  return res;
}
 
async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const a = (await getLine()).split(' ').map(Number);
    const res = solve(a);
    console.log(res.join(' '));
  }
}
 
if (require.main === module) {
  main();
}
