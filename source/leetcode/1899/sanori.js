/**
 * @param {number[][]} triplets
 * @param {number[]} target
 * @return {boolean}
 */
 var mergeTriplets = function(triplets, target) {
  const n = triplets.length;  
  const maxes = [0, 0, 0];
  for (const t of triplets) {
    if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
      continue;
    }
    for (let j = 0; j < 3; j++) {
      maxes[j] = Math.max(maxes[j], t[j]);
    }
  }
  return (maxes[0] === target[0] && maxes[1] === target[1] && maxes[2] === target[2]);
};
