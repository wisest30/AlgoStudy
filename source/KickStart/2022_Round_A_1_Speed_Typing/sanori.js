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
 * @param {String} given
 * @param {String} typed
 * @returns {Number}
 */
function solve(given, typed) {
  const m = given.length;
  const n = typed.length;
  if (n < m) return -1;
  let res = 0, gIdx = 0, tIdx = 0;
  while (gIdx < m && tIdx < n) {
    if (given[gIdx] === typed[tIdx]) {
      gIdx++;
      tIdx++;
    } else {
      tIdx++;
      res++;
    }
  }
  if (gIdx < m) {
    return -1;
  }

  return res + (n - tIdx);
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const given = (await getLine());
    const typed = (await getLine());
    const res = solve(given, typed);
    console.log(`Case #${i+1}:`, (res === -1) ? 'IMPOSSIBLE' : res);
  }
}

if (require.main === module) {
  main();
}