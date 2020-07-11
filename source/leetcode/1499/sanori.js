/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number}
 */
var findMaxValueOfEquation = function(points, k) {
  let res = -Infinity;
  const q = [];
  for (const [x, y] of points) {
    while (q.length > 0 && q[0][1] < x - k) {
      q.shift();
    }
    console.log({m:'1st', q});
    if (q.length > 0) {
      res = Math.max(res, q[0][0] + y + x);
    }
    while (q.length > 0 && q[q.length-1][0] <= y - x) {
      q.pop();
    }
    console.log({m:'2nd', q});
    q.push([y - x, x]);
  }
  return res;
};