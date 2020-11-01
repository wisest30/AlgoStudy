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
 * @param {Number []} trans
 * @returns {String}
 */
function solve(trans) {
  const stack = [];
  const res = [];
  while (trans.length > 0) {
    const t = trans.pop();
    if (t === 0) {
      if (stack.length < 1) {
        return 'NO';
      }
      res.push(stack.pop());
    } else if (stack.length > 0 && stack[stack.length-1] < t) {
      return 'NO';
    } else {
      stack.push(t);
    }
  }
  res.reverse();
  return 'YES\n' + res.join(' ');
}
 
async function main() {
  const n = Number(await getLine());
  const trans = [];
  for (let i = 0; i < 2 * n; i++) {
    const l = (await getLine()).split(' ');
    if (l[0] === '+') {
      trans[i] = 0;
    } else {
      trans[i] = Number(l[1]);
    }
  }
  const res = solve(trans);
  console.log(res);
}
 
if (require.main === module) {
  main();
}
