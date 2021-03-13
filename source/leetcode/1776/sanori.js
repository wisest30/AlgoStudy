/**
 * @param {number[][]} cars
 * @return {number[]}
 */
 var getCollisionTimes = function(cars) {
  const n = cars.length;
  const stack = [];
  const res = Array(n).fill(-1);
  for (let i = n - 1; i >= 0; --i) {
    const [p, s] = cars[i];
    while (stack.length > 0) {
      const tIdx = stack[stack.length-1];
      if (s > cars[tIdx][1] && (
          res[tIdx] < 0 ||
         (cars[tIdx][0] - p)/(s - cars[tIdx][1]) < res[tIdx])) {
        break;
      }
      stack.pop();
    }

    if (stack.length > 0) {
      const tIdx = stack[stack.length-1];
      res[i] = (cars[tIdx][0] - p)/(s - cars[tIdx][1]);
    }
    stack.push(i);
  }

  return res;
};
