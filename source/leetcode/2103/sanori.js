/**
 * @param {string} rings
 * @return {number}
 */
var countPoints = function (rings) {
  const n2 = rings.length;
  const n = Math.floor(n2 / 2);
  const rods = Array(10).fill(0);

  for (let i = 0; i < n; i++) {
    const color = rings[2 * i];
    const rod = Number(rings[2 * i + 1]);
    const mask = (color === 'R') ? 1 : ((color === 'G') ? 2 : 4);
    rods[rod] |= mask;
  }
  return rods.filter(x => x === 7).length;
};
