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
 * @param {Number[]} s
 * @returns {Number}
 */
function solve(s) {
  s.sort((a, b) => b - a);
  let res = 1;
  while (s.length > 0) {
    const k = s.pop();
    if (k >= res) {
      res++;
    }
  }
  return res - 1;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const s = (await getLine()).split(' ').map(Number);
    const res = solve(s);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}