/**
 * @param {number[]} plants
 * @param {number} capacityA
 * @param {number} capacityB
 * @return {number}
 */
var minimumRefill = function (plants, capacityA, capacityB) {
  const n = plants.length;
  let res = 0;
  let a = 0, b = n - 1, aw = capacityA, bw = capacityB;
  for (; a < b; a++, --b) {
    if (aw < plants[a]) {
      aw = capacityA;
      res++;
    }
    aw -= plants[a];
    if (bw < plants[b]) {
      bw = capacityB;
      res++;
    }
    bw -= plants[b];
  }
  if (a === b) {
    if (aw >= bw) {
      if (aw < plants[a]) {
        res++;
      }
    } else {
      if (bw < plants[a]) {
        res++;
      }
    }
  }

  return res;
};
