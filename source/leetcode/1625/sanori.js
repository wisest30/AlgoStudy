/**
 * @param {string} s
 * @param {number} a
 * @param {number} b
 * @return {string}
 */
var findLexSmallestString = function(s, a, b) {
  const n = s.length;
  if (n < 2) {
    return s;
  }

  const add = (ss) => {
    const res = ss.split('');
    for (let i = 1; i < n; i += 2) {
      res[i] = (Number(ss[i]) + a) % 10;
    }
    return res.join('');
  };

  const rotate = (ss) => ss.slice(n - b) + ss.slice(0, n - b);

  const visited = new Set();
  let res = s;

  const traverse = (ss) => {
    if (visited.has(ss)) {
      return;
    }
    visited.add(ss);
    if (res > ss) {
      res = ss;
    }
    traverse(add(ss));
    traverse(rotate(ss));
  };

  traverse(s);
  return res;
};
