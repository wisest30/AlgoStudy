/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var largestMerge = function(word1, word2) {
  const seqs = [word1.split('').reverse(), word2.split('').reverse()];
  const res = [];

  const comp = (a, b) =>  {
    let ia = a.length - 1;
    let ib = b.length - 1;
    while (ia >= 0 && ib >= 0) {
      if (a[ia] < b[ib]) {
        return -1;
      } else if (a[ia] > b[ib]) {
        return 1;
      }
      ia--;
      ib--;
    }
    return ia - ib;
  }

  while (seqs[0].length * seqs[1].length > 0) {
    if (comp(seqs[0], seqs[1]) > 0) {
      res.push(seqs[0].pop());
    } else {
      res.push(seqs[1].pop());
    }
  }

  for (let i = 0; i < 2; i++) {
    while(seqs[i].length > 0) {
      res.push(seqs[i].pop());
    }
  }

  return res.join('');
};
