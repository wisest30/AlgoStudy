/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function(a, b, c) {
  const helper = (aa, bb, cc, cha = 'a', chb = 'b', chc = 'c') => {
    if (aa < bb) {
      return helper(bb, aa, cc, chb, cha, chc);
    }
    if (bb < cc) {
      return helper(aa, cc, bb, cha, chc, chb);
    }
    if (bb == 0) {
      return cha.repeat(Math.min(2, aa));
    }
    const repA = Math.min(2, aa);
    const repB = (aa - repA >= bb) ? 1 : 0;
    return cha.repeat(repA) + chb.repeat(repB) + helper(aa - repA, bb - repB, cc, cha, chb, chc);
  };
  return helper(a, b, c);
};