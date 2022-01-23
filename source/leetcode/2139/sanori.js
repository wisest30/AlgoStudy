/**
 * @param {number} target
 * @param {number} maxDoubles
 * @return {number}
 */
 var minMoves = function(target, maxDoubles) {
  let res = 0;
  let cur = target;
  while (cur > 1) {
    if (maxDoubles > 0) {
      res += 1 + cur % 2;
      maxDoubles--;
      cur = Math.floor(cur/2);
    } else {
      res += cur - 1;
      cur = 1;
    }
  }
  return res;
};
