/**
 * @param {number[]} stoneValue
 * @return {string}
 */
var stoneGameIII = function(stoneValue) {
  const n = stoneValue.length;
  const helper = (idx = 0, scores = [0, 0], turn = 0) => {
    if (idx >= n) {
      return scores[1] - scores[0];
    }
    
    let newValue = 0;
    let res = (turn !== 0) ? -1e9 : 1e9;
    for (let i = 0; i < 3 && idx + i < n; i++) {
      const newScore = [scores[0], scores[1]];
      newValue += stoneValue[idx + i];
      newScore[turn] += newValue;
      const result = helper(idx + i + 1, newScore, 1 - turn);
      res = (turn !== 0) ? Math.max(res, result) : Math.min(res, result);
    }
    return res;
  };
  const res = helper(0);
  if (res < 0) {
    return 'Alice';
  } else if (res > 0) {
    return 'Bob';
  } else {
    return 'Tie';
  }
};
