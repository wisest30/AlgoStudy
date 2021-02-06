/**
 * @param {string} time
 * @return {string}
 */
var maximumTime = function(time) {
  const res = [];
  res[0] = (time[0] === '?') ? ((Number(time[1]) > 3) ? '1' : '2') : time[0];
  res[1] = (time[1] === '?') ? ((res[0] === '2') ? '3' : '9'): time[1];
  res[2] = ':';
  res[3] = (time[3] === '?') ? '5' : time[3];
  res[4] = (time[4] === '?') ? '9' : time[4];
  
  return res.join('');
};
