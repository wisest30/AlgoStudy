/**
 * @param {string} word
 * @return {number}
 */
 var countVowels = function(word) {
  const n = word.length;  
  const n2 = Math.floor(n/2);
  const vowels = new Set('aeiou'.split(''));
  let res = 0;
  for (let i = 0; i < n2; i++) {
    if (vowels.has(word[i])) {
      res += (n - i) * (i+1);
    }
    if (vowels.has(word[n-i-1])) {
      res += (n - i) * (i+1);
    }
  }
  if (n % 2 === 1 && vowels.has(word[n2])) {
    res += (n - n2) * (n2 + 1);
  }
  return res;
};
