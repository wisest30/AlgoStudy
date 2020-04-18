/**
 * @param {string} s
 * @return {number}
 */
var numSteps = function(s) {
  const sArr = s.split('').map(Number);
  sArr.reverse();
  let res = 0, i = 0;
  while (i < sArr.length) {
    if (sArr[i] === 0) {
      i++;
    } else if (i < sArr.length - 1){
      let j = i;
      for (; j < sArr.length && sArr[j] === 1; j++) {
        sArr[j] = 0;
      }
      sArr[j] = 1;
    } else {
      break;
    }
    res++;
  }
  return res;
};