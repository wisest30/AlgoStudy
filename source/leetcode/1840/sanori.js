/**
 * @param {number} n
 * @param {number[][]} restrictions
 * @return {number}
 */
 var maxBuilding = function(n, restrictions) {
  if (restrictions.length < 1) {
    return n - 1;
  }
  const limits = restrictions.slice();
  limits.push([1, 0]);
  limits.sort((a, b) => a[0] - b[0]);
  const m = limits.length;

  let last = 1, height = 0;
  for (let i = 0; i < m; i++) {
    const [x, hl] = limits[i];
    const maxHeight = height + x - last;
    if (maxHeight < hl) {
      limits[i][1] = maxHeight;
    }
    last = x;
    height = limits[i][1];
  }

  const [x, hl] = limits[limits.length-1];
  last = n, height = hl + n - x;
  let res = height;
  while (limits.length > 0) {
    const [x, hl] = limits.pop();
    const maxHeight = height + last - x;
    const minHeight = height - last + x;
    if (hl > maxHeight) {
      height = maxHeight;
      res = Math.max(res, height);
    } else {
      if (hl > minHeight) {
        const midHeight = Math.floor((height + last - x + hl)/2);
        // console.log({last, height, x, hl, midHeight});
        res = Math.max(res, midHeight);
      }
      height = hl;
    }
    last = x;
  }
  return res;
};
