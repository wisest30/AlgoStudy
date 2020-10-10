/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
  let depth = 0;
  for (const op of logs) {
    if (op === '../') {
      depth = Math.max(0, depth - 1);
    } else if (op !== './') {
      depth++;
    }
  }
  return depth;
};