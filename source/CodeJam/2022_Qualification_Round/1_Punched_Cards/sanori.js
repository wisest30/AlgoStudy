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
 * @param {Number} r
 * @param {Number[]} c
 * @returns {void}
 */
function solve(r, c) {
  if (r < 1 || c < 1) return;
  const resArr = [
    '..+' + '-+'.repeat(c-1),
    '..|' + '.|'.repeat(c-1)
  ];
  for (let i = 1; i < r; i++) {
    resArr.push('+' + '-+'.repeat(c));
    resArr.push('|' + '.|'.repeat(c));
  }
  resArr.push('+' + '-+'.repeat(c));
  return resArr.join('\n');
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const [r, c] = (await getLine()).split(' ').map(Number);
    const res = solve(r, c);
    // console.error({res});
    console.log(`Case #${i+1}:\n${res}`);
  }
}

if (require.main === module) {
  main();
}