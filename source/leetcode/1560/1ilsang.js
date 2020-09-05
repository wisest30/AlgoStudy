/**
 * @param {number} n
 * @param {number[]} rounds
 * @return {number[]}
 */
const mostVisited = (n, rounds) => {
  const [start, end] = [rounds[0], rounds[rounds.length - 1]];
  const ret = [];

  if (start <= end)
    for (let i = start; i <= end; i++) ret.push(i);
  else {
    for (let i = 1; i <= end; i++) ret.push(i);
    for (let i = start; i <= n; i++) ret.push(i);
  }

  return ret;
}