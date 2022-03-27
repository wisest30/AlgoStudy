/**
 * @param {string} directions
 * @return {number}
 */
var countCollisions = function(directions) {
  const n = directions.length;
  let res = 0, rights = 0, blocked = false;
  for (let i = 0; i < n; i++) {
    if (directions[i] === 'R') {
      blocked = true;
      rights++;
    } else if (directions[i] === 'S') {
      blocked = true;
      res += rights;
      rights = 0;
    } else if (blocked) {
      res += rights + 1;
      rights = 0;
    }
  }
  return res;
};

