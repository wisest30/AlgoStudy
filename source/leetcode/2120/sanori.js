const move = {
  L: [0, -1],
  R: [0, 1],
  U: [-1, 0],
  D: [1, 0]
}
/**
 * @param {number} n
 * @param {number[]} startPos
 * @param {string} s
 * @return {number[]}
 */
var executeInstructions = function (n, startPos, s) {
  const res = [];
  for (let i = 0; i < s.length; i++) {
    let curIdx = i, curPos = startPos.slice(), dist = 0;
    let stay = true;
    while (curIdx < s.length && stay) {
      curPos[0] += move[s[curIdx]][0];
      curPos[1] += move[s[curIdx]][1];
      if (0 <= curPos[0] && curPos[0] < n && 0 <= curPos[1] && curPos[1] < n) {
        dist++;
        curIdx++;
      } else {
        stay = false;
      }
    }
    res[i] = dist;
  }
  return res;
};
