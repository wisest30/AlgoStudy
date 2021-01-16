/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
var maximumUnits = function(boxTypes, truckSize) {
  boxTypes.sort((a,b) => b[1] - a[1]);
  const n = boxTypes.length;
  let res = 0;
  for (let i = 0; i < n && truckSize > 0; i++) {
    const box = Math.min(truckSize, boxTypes[i][0]);
    res += boxTypes[i][1] * box;
    truckSize -= box;
  }
  return res;
};
