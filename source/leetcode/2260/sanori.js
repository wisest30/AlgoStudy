/**
 * @param {number[]} cards
 * @return {number}
 */
 var minimumCardPickup = function(cards) {
  const n = cards.length;
  let res = Infinity;
  const idx = {};
  for (let i = 0; i < n; i++) {
    const e = cards[i];
    if (idx[e] !== undefined) {
      res = Math.min(res, i - idx[e] + 1);
    }
    idx[e] = i;
  }
  return (res === Infinity) ? -1 : res;
};
