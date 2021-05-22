/**
 * @param {number[][]} logs
 * @return {number}
 */
 var maximumPopulation = function(logs) {
  const event = Array(101).fill(0);
  for (const [b, d] of logs) {
    event[b - 1950]++;
    event[d - 1950]--;
  }
  let res = 0, curPop = 0, maxPop = 0;
  for (let i = 0; i < 101; i++) {
    curPop += event[i];
    if (curPop > maxPop) {
      res = i;
      maxPop = curPop;
    }
  }
  return res + 1950;
};
