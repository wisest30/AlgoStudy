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
 * @param {Number[]} f
 * @param {Number[]} p
 * @returns {Number}
 */
function solve(f, p) {
  const n = f.length;
  const parent = p.map(x => (x === 0) ? undefined : x - 1);
  const inDeg = Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    if (parent[i] === undefined) continue;
    inDeg[parent[i]]++;
  }

  const fromChild = Array(n).fill(null).map(() => []);
  let res = 0;
  const q = [];
  for (let i = 0; i < n; i++) {
    if (inDeg[i] === 0) {
      q.push([parent[i], f[i]]);
    }
  }

  while (q.length > 0) {
    const [u, val] = q.shift();
    if (u === undefined) {
      res += val;
      continue;
    }
    const arr = fromChild[u];
    arr.push(val);
    if (arr.length === inDeg[u]) {
      const min = Math.min(...arr);
      const sum = arr.reduce((a, b) => a + b, 0);
      res += sum - min;
      q.push([parent[u], Math.max(f[u], min)]);
    }
  }
  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const f = (await getLine()).split(' ').map(Number);
    const p = (await getLine()).split(' ').map(Number);
    const res = solve(f, p);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}