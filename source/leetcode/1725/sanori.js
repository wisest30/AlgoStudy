/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var countGoodRectangles = function(rectangles) {
  const freq = rectangles.reduce((acc, cur) => {
    const s = Math.min(...cur);
    acc[s] = acc[s] + 1 || 1;
    return acc;
  }, {});
  const maxS = Math.max(...Object.keys(freq).map(Number));
  return freq[maxS];
};
