#!/usr/bin/env node
'use strict';

const { createInterface } = require('readline');
const rl = createInterface({
  input: process.stdin,
  crlfDelay: Infinity
});

function Q() {
  this._stack1 = [];
  this._stack2 = [];
}

Q.prototype = {
  push(item) {
    this._stack1.push(item);
  },
  shift() {
    if (this._stack2.length === 0) {
      const tmp = this._stack2;
      this._stack2 = this._stack1.reverse();
      this._stack1 = tmp;
    }
    return this._stack2.pop();
  },
  get length() {
    return this._stack1.length + this._stack2.length;
  }
};

const buf = new Q();
const prom = new Q();
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
 * @param {String} f
 * @returns {String}
 */
function solve(s) {
  const n = s.length;
  const resArr = [];
  let acc = 1;
  for (let i = 1; i < n; i++) {
    if (s[i-1] < s[i]) {
      resArr.push(s[i-1].repeat(acc * 2));
      acc = 1;
    } else if (s[i-1] === s[i]){
      acc++;
    } else {
      resArr.push(s[i-1].repeat(acc));
      acc = 1;
    }
  }
  resArr.push(s[n-1].repeat(acc));
  return resArr.join('');
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const s = (await getLine());
    const res = solve(s);
    console.log(`Case #${i+1}:`, res);
  }
}

if (require.main === module) {
  main();
}