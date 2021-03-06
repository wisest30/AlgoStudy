/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
 var longestPalindrome = function(word1, word2) {
  const n1 = word1.length;
  const n2 = word2.length;
  const s = word1 + word2;
  const n = s.length;

  const dp = Array(n).fill(null).map(() => []);
  for (let l = 0; l < n; l++) {
    dp[l][l] = 1;
  }

  for (let l = 0; l < n - 1; l++) {
    dp[l][l+1] = (s[l] === s[l+1]) ? 2 : 1;
  }

  for (let len = 2; len < n; len++) {
    for (let l = 0; l < n - len; l++) {
      const r = l + len;
      const idx = `${l},${r}`;
      if (s[l] === s[r]) {
        dp[l][r] = dp[l+1][r-1] + 2;
      } else {
        dp[l][r] = Math.max(dp[l][r-1], dp[l+1][r]);
      }
    }
  }
  // console.log({dp});

  let res = 0;
  for (let i = 0; i < n1; i++) {
    for (let j = 0; j < n2; j++) {
      if (s[i] === s[n - j - 1]) {
        res = Math.max(res, dp[i][n-j-1]);
        break;
      }
    }
  }
  return res;
};
