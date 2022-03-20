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

function getDigitSum(k) {
  let res = 0;
  while (k > 0) {
    res += (k % 10);
    k = Math.floor(k / 10);
  }
  return res;
}

function getProductMod(k, mod) {
  let res = 1;
  while (k > 0 && res !== 0) {
    res = (res * (k % 10)) % mod;
    k = Math.floor(k / 10);
  }
  return res;
}


/**
 *
 * @param {Number} a
 * @param {Number} b
 * @returns {Number}
 */
function solve(a, b) {
  let res = 0;
  for (let i = a; i <= b; i++) {
    const mod = getDigitSum(i);
    const residual = getProductMod(i, mod);
    if (residual === 0) {
      res++;
    }
  }

  return res;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const [a, b] = (await getLine()).split(' ').map(Number);
    const res = solve(a, b);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}