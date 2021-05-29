/**
 * @param {string} s
 * @return {number}
 */
 var minSwaps = function(s) {
  const n = s.length;
  if (n < 2) {
    return 0;
  }

  const search = (parity) => {
    const ss = s.split('');
    let p0, p1;
    if (!parity) {
      p0 = 0;
      p1 = 1;
    } else {
      p0 = 1;
      p1 = 0;
    }
    let res = 0;
    while (p0 < n && p1 < n) {
      while (p0 < n && ss[p0] === '0') {
        p0 += 2;
      }
      while (p1 < n && ss[p1] === '1') {
        p1 += 2;
      }
      if (p0 < n && ss[p0] === '1' && p1 < n && ss[p1] === '0') {
        ss[p0] = '0';
        ss[p1] = '1';
        res++;
      } else {
        break;
      }
    }

    return (p0 < n || p1 < n) ? Infinity : res;
  }

  // try to start "01"
  const res1 = search(0);
  const res2 = search(1);
  const res = Math.min(res1, res2);
  // console.log({res1, res2, res})
  return (res === Infinity) ? -1 : res;
};
