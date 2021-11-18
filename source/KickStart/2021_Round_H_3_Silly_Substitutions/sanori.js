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
 * @returns {String}
 */
function solve(s) {
  let last = s.split('').map(Number);
  let changed = false;
  do {
    changed = false;
    // console.log({last});
    for (let i = 0; i <= 9; i++) {
      const next = [];
      for (let j = 0; j < last.length; j++) {
        if (last[j] === i && last[j + 1] === ((i + 1) % 10)) {
          next.push((i + 2) % 10);
          j++;
          changed = true;
        } else if (j < last.length) {
          next.push(last[j]);
        }
        // console.error({i, j, next})
      }
      // console.error({i, last, next});
      last = next;
    }
  } while (changed)
  return last.join('');
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const n = Number(await getLine());
    const s = (await getLine());
    const res = solve(s);
    console.log(`Case #${i + 1}:`, res);
  }
}

if (require.main === module) {
  main();
}
