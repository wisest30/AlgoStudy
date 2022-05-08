/**
 * @param {string} number
 * @param {character} digit
 * @return {string}
 */
 var removeDigit = function(number, digit) {
  let res = 0n;
  let idx = number.indexOf(digit);
  while (idx >= 0) {
    const nNumArr = number.split('');
    nNumArr.splice(idx, 1);
    const nNum = BigInt(nNumArr.join(''));
    if (res < nNum) {
      res = nNum;
    }
    idx = number.indexOf(digit,idx + 1);
  }
  return res.toString();
};
