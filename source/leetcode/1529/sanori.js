/**
 * @param {string} target
 * @return {number}
 */
var minFlips = function(target) {
  const n = target.length;
  let curState = '0';
  let res = 0;
  for (let i = 0; i < n; i++) {
    if (target[i] !== curState) {
      curState = target[i];
      res++;
    }
  }
  return res;
};