/**
 * @param {number} numArrows
 * @param {number[]} aliceArrows
 * @return {number[]}
 */
var maximumBobPoints = function(numArrows, aliceArrows) {
  let resScore = 0, res = [];
  for (let bits = 1; bits < 4096; bits++) {
    let arrows = 0, score = 0;
    const shots = Array(12).fill(0);
    for (let i = 0; i < 12; i++) {
      if (bits & (1 << i)) {
        arrows += aliceArrows[i] + 1;
        score += i;
        shots[i] = aliceArrows[i] + 1;
      }
    }
    if (arrows <= numArrows && score > resScore) {
      resScore = score;
      res = shots;
    }
  }
  const sum = res.reduce((a,b) => a + b, 0);
  res[0] = numArrows - sum;
  return res;
};

