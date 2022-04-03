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
 * @param {Number[][]} input
 * @returns {Number[]}
 */
function solve(input) {
  const config = [Infinity, Infinity, Infinity, Infinity];
  for (let i = 0; i < input.length; i++) {
    for (let j = 0; j < 4; j++) {
      config[j] = Math.min(config[j], input[i][j]);
    }
  }
  const sum = config.reduce((a, b) => a + b, 0);
  if (sum < 1e6) {
    return;
  }
  let remain = sum - 1e6;
  let i = 0;
  while (remain > 0 && i < 4) {
    const cut = Math.min(config[i], remain);
    config[i] -= cut;
    remain -= cut;
    i++;
  }
  return config;
}

async function main() {
  const t = Number(await getLine());
  for (let i = 0; i < t; i++) {
    const input = [];
    for (let j = 0; j < 3; j++) {
      const c = (await getLine()).split(' ').map(Number);
      input.push(c);
    }
    const res = solve(input);
    console.log(`Case #${i+1}:`,
      (res === undefined) ? 'IMPOSSIBLE' : res.join(' '));
  }
}

if (require.main === module) {
  main();
}