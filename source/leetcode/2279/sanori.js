/**
 * @param {number[]} capacity
 * @param {number[]} rocks
 * @param {number} additionalRocks
 * @return {number}
 */
 var maximumBags = function(capacity, rocks, additionalRocks) {
  const n = capacity.length;
  const remains = capacity.map((x, i) => x - rocks[i]);
  remains.sort((a,b) => a - b);
  let i = 0;
  for (; i < n && additionalRocks > 0; i++) {
    if (remains[i] === 0) continue;
    if (remains[i] <= additionalRocks) {
      additionalRocks -= remains[i];
      remains[i] = 0;
    } else {
      break;
    }
  }
  return i;
};
