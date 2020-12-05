/**
 * @param {number[][]} tasks
 * @return {number}
 */
var minimumEffort = function(tasks) {
  const nTasks = tasks.map(x => [x[0], x[1], x[1] - x[0]]);
  nTasks.sort((a, b) => (a[2] !== b[2]) ? b[2] - a[2] : b[1] - a[1]);
  // console.log({nTasks});

  let res = 0, rem = 0;
  for (const [a, s, d] of nTasks) {
    const need = Math.max(0, s - rem, a - rem);
    res += need;
    rem = rem + need - a;
  }
  return res;
};
