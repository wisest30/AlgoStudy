/**
 * @param {string} command
 * @return {string}
 */
var interpret = function(command) {
  const n = command.length;
  const resArr = [];
  for (let i = 0; i < n; i++) {
    if (command[i] === 'G') {
      resArr.push('G');
    } else if (command[i] === '(') {
      i++;
      if (command[i] === ')') {
        resArr.push('o');
      } else {  // a
        i += 2;
        resArr.push('al');
      }
    }
  }
  return resArr.join('');
};
