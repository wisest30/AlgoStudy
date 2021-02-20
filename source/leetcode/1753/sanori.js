/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var maximumScore = function(a, b, c) {
  const inst = [a, b, c];
  inst.sort((a,b) => a - b);
  let res = 0;
  while (inst[0] !== 0 || inst[1] !== 0) {
    if (inst[0] + inst[1] <= inst[2]) {
      const d = inst[0] + inst[1];
      inst[0] = 0;
      inst[1] = 0;
      inst[2] -= d;
      res += d;
    } else if (inst[1] === inst[2]) {
      let d = Math.floor(inst[0] / 2);
      if (d === 0) {
        d = inst[1];
        inst[1] -= d;
        inst[2] -= d;
        res += d;
      } else {
        inst[0] -= 2 * d;
        inst[1] -= d;
        inst[2] -= d;
        res += 2 * d;
      }
    } else {
      const d = Math.min(inst[2] - inst[1], inst[0]);
      inst[0] -= d;
      inst[2] -= d;
      res += d;
    }
    inst.sort((a,b) => a - b);
  }
  return res;
};
