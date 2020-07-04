/**
 * @param {number} n
 * @param {number} start
 * @return {number}
 */
const xorOperation = (n, start) => {
  if (n === 1) return start;

  let answer = start ^ (start + 2);
  start += 4;

  for (let i = 2; i < n; i++) {
    answer ^= start;
    start += 2;
  }

  return answer;
};
