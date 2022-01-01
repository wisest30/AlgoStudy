/**
 * @param {number[]} arr
 * @return {number[]}
 */
var getDistances = function (arr) {
  const n = arr.length;
  const dict = {};
  for (let i = 0; i < n; i++) {
    const v = arr[i];
    if (dict[v] === undefined) {
      dict[v] = { rSum: 0, rCnt: 0, lSum: 0, lCnt: 0, last: i };
    }
    dict[v].rSum += (i - dict[v].last);
    dict[v].rCnt++;
  }
  // console.log({dict});

  const res = [];
  for (let i = 0; i < n; i++) {
    const o = dict[arr[i]];
    const d = i - o.last;
    o.last = i;
    o.rSum -= o.rCnt * d;
    o.rCnt--;
    o.lSum += (o.lCnt) * d;
    o.lCnt++;
    res[i] = o.rSum + o.lSum;
    // console.log({v: arr[i], o})
  }
  return res;
};
