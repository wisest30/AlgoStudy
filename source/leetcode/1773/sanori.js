/**
 * @param {string[][]} items
 * @param {string} ruleKey
 * @param {string} ruleValue
 * @return {number}
 */
 var countMatches = function(items, ruleKey, ruleValue) {
  let res = 0;
  for (const [t, c, n] of items) {
    if (ruleKey === 'type') {
      if (t === ruleValue) {
        res++;
      }
    } else if (ruleKey === 'color') {
      if (c === ruleValue) {
        res++;
      }
    } else {
      if (n === ruleValue) {
        res++;
      }
    }
  }
  return res;
};
