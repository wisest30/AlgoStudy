/**
 * @param {number[]} obstacles
 * @return {number}
 */
 var minSideJumps = function(obstacles) {
  const n = obstacles.length;
  const nextObs = Array(n).fill(null).map(() => []);
  for (let i = 0; i < 3; i++) {
    nextObs[n-1][i] = n;
  }
  for (let i = n-2; i >= 0; --i) {
    for (let j = 0; j < 3; j++) {
      nextObs[i][j] = (obstacles[i] - 1 === j) ? i : nextObs[i+1][j];
    }
  }
  let res = 0, curLane = 2;
  for (let i = 0; i < n - 1; i++) {
    if (obstacles[i+1] !== curLane) continue;
    let nextLane = 1, maxVal = nextObs[i][0];
    for (let j = 1; j < 3; j++) {
      if (nextObs[i][j] > maxVal) {
        nextLane = j + 1;
        maxVal = nextObs[i][j];
      }
    }
    curLane = nextLane;
    res++;
  }
  return res;
};
