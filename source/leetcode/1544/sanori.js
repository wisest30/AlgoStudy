/**
 * @param {string} s
 * @return {string}
 */
var makeGood = function(s) {
  const n = s.length;
  if (n < 2) {
    return s;
  }
  const stack = [];
  stack.push(s[0]);
  let i = 1;
  while (i < n) {
    if (stack.length > 0 &&
          Math.abs(stack[stack.length - 1].charCodeAt(0) - s.charCodeAt(i)) === 32) {
      stack.pop();
    } else {
      stack.push(s[i]);
    }
    i++;
  }
  return stack.join('');
};