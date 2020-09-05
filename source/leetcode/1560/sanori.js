/**
 * @param {number} n
 * @param {number[]} rounds
 * @return {number[]}
 */
var mostVisited = function(n, rounds) {
  const counts = Array(n).fill(0);
  for (let i = 1; i < rounds.length; i++) {
    const last = (rounds[i] < rounds[i - 1]) ?  rounds[i] + n : rounds[i];
    for (let j = rounds[i-1] - 1; j < last - 1; j++) {
      counts[j % n]++;
    }
  }
  counts[rounds[rounds.length-1]- 1]++;
  const max = Math.max(... counts);
  const res = [];
  for (let i = 0; i < n; i++) {
    if (counts[i] === max) {
      res.push(i+1);
    }
  }
  return res;
};