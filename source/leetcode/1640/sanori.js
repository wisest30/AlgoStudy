/**
 * @param {number[]} arr
 * @param {number[][]} pieces
 * @return {boolean}
 */
var canFormArray = function(arr, pieces) {
  const n = arr.length;
  const pSet = new Set(pieces.map(x => x.toString()));
  // console.log({pSet});
  for(let i = 0; i < n; ) {
    let j = 1, match = false;
    for (; i + j <= n; j++) {
      const aStr = arr.slice(i, i + j).toString();
      if (pSet.has(aStr)) {
        match = true;
        i += j
        break;
        pSet.delete(aStr);
      }
    }
    if (!match) {
      return false;
    }
  }
  return true;
};