/**
 * @param {string} s
 * @param {character} letter
 * @return {number}
 */
 var percentageLetter = function(s, letter) {
  const n = s.length;
  let cnt = 0;
  for (let i = 0; i < n; i++) {
    if (s[i] === letter) {
      cnt++;
    }
  }
  return Math.floor(cnt * 100 / n);
};
