/**
 * @param {string} number
 * @return {string}
 */
var reformatNumber = function(number) {
  const num = number.replace(/-/g, '').replace(/ /g, '');
  const n = num.length;
  
  const res = [];
  let i = 0;
  while ((n - i) > 4) {
    res.push(num.slice(i, i+3));
    i += 3;
  }
  if ((n-i) === 4) {
    res.push(num.slice(i, i+2));
    res.push(num.slice(i+2, i+4));
  } else {
    res.push(num.slice(i, n));
  }
  return res.join('-');
};
