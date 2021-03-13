/**
 * @param {number[]} baseCosts
 * @param {number[]} toppingCosts
 * @param {number} target
 * @return {number}
 */
 var closestCost = function(baseCosts, toppingCosts, target) {
  const n = baseCosts.length;
  const m = toppingCosts.length;
  let res = baseCosts[0], rDiff = Math.abs(target - res);
  const traverse = (offset, idx = 0) => {
    const oDiff = Math.abs(target - offset);
    if (oDiff < rDiff || (oDiff === rDiff && offset < res)) {
      res = offset;
      rDiff = Math.abs(target - res);
    }
    if (idx >= m || res === target)  {
      return;
    }
    traverse(offset, idx + 1);
    traverse(offset + toppingCosts[idx], idx + 1);
    traverse(offset + 2 * toppingCosts[idx], idx + 1);
  };
  for (const b of baseCosts) {
    traverse(b, 0);
  }
  return res;
}; 
