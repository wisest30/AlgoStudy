/**
 * @param {number} n
 * @param {number} k
 * @return {character}
 */
const findKthBit = (n, k) => {
  const s = [0];
  while (n-- > 0) {
    const reverseArr = [...s].reverse().map((e) => (e === 0 ? 1 : 0));
    s.push(1, ...reverseArr);
  }
  return `${s[k - 1]}`;
};
