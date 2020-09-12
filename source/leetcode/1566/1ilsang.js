/**
 * @param {number[]} arr
 * @param {number} m
 * @param {number} k
 * @return {boolean}
 */
const containsPattern = (arr, m, k) => {
  let count = 1;
  const str = arr.join("");

  for (let i = 0; i < arr.length; i++) {
    const target = str.slice(i, i + m);
    for (let j = i + m; j + m <= arr.length; j += m) {
      const cur = str.slice(j, j + m);
      if (target === cur) count++;
      else break;
      if (count === k) return true;
    }
    count = 1;
  }

  return false;
};