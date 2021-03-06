/**
 * @param {string} boxes
 * @return {number[]}
 */
 var minOperations = function(boxes) {
  const n = boxes.length;
  const res = Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    if (boxes[i] === '0') continue;
    for (let j = 0; j < n; j++) {
      res[j] += Math.abs(i - j);
    }
  }
  return res;
};
