/**
 * @param {string} word
 * @return {number}
 */
 var countVowelSubstrings = function(word) {
  const n = word.length;
  const vowels = new Set('aeiou'.split(''));
  let freq = {a:0, e:0, i:0, o:0, u:0};
  let res = 0;
  for (let i = 0; i < n; i++) {
    if (!vowels.has(word[i])) continue;
    for (let j = i; j < n && vowels.has(word[j]); j++) {
      freq[word[j]]++;
      if (Math.min(...Object.values(freq)) > 0) {
        res++;
      }
    }
    freq = {a:0, e:0, i:0, o:0, u:0};
  }
  return res;
};
