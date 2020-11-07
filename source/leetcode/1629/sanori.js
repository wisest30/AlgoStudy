/**
 * @param {number[]} releaseTimes
 * @param {string} keysPressed
 * @return {character}
 */
var slowestKey = function(releaseTimes, keysPressed) {
  const n = releaseTimes.length;
  let maxTime = releaseTimes[0];
  let maxKey = [keysPressed[0]];
  for (let i = 1; i < n; i++) {
    const t = releaseTimes[i] - releaseTimes[i-1];
    if (t > maxTime) {
      maxTime = t;
      maxKey = [keysPressed[i]];
    } else if (t === maxTime) {
      maxKey.push(keysPressed[i]);
    }
  }
  maxKey.sort();
  // console.log({maxTime, maxKey});
  const res = maxKey.pop();
  return res;
};
