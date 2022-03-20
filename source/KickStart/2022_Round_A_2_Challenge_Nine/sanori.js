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
 * @param {String} nstr
 * @returns {String}
 */
function solve(nstr) {
  const residual = nstr.split('')
    .reduce((acc, cur) => (acc + Number(cur)) % 9, 0);
  const target = (9 - residual) % 9;
  if (target === 0) {
    return nstr.slice(0,1) + '0' + nstr.slice(1);
  }
  let loc = 0;
  while (loc < nstr.length && Number(nstr[loc]) <= target) {
    loc++;
  }
  return nstr.slice(0, loc) + target.toString() + nstr.slice(loc);
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const nstr = (await getLine());
    const res = solve(nstr);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}