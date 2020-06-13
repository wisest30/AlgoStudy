/**
 * @param {number} h
 * @param {number} w
 * @param {number[]} horizontalCuts
 * @param {number[]} verticalCuts
 * @return {number}
 */
var maxArea = function(h, w, horizontalCuts, verticalCuts) {
  const mod = 1e9 + 7;
  horizontalCuts.sort((a, b) => a - b);
  verticalCuts.sort((a, b) => a - b);
  
  let maxH = 0, lastH = 0;
  for (const hh of horizontalCuts) {
    const size = hh - lastH;
    maxH = Math.max(maxH, size);
    lastH = hh;
  }
  maxH = Math.max(maxH, h - lastH);
  
  let maxV = 0, lastV = 0;
  for (const vv of verticalCuts) {
    const size = vv - lastV;
    maxV = Math.max(maxV, size);
    lastV = vv;
  }
  maxV = Math.max(maxV, w - lastV);
   
  return (maxH * maxV) % mod;
};