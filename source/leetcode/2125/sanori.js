/**
 * @param {string[]} bank
 * @return {number}
 */
 var numberOfBeams = function(bank) {
  const m = bank.length;
  let res = 0, last = 0, r = 0;
  for (;r < m && last === 0; r++) {
    const row = bank[r];
    for (let c = 0; c < row.length; c++) {
      if (row[c] === '1') {
        last++;
      }
    }
  }

  for (; r < m; r++) {
    const row = bank[r];
    let ones = 0;
    for (let c = 0; c < row.length; c++) {
      if (row[c] === '1') {
        ones++;
      }
    }
    if (ones < 1) {
      continue;
    }
    res += last * ones;
    last = ones;
  }
  return res;
};
