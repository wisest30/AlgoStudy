var minimumOneBitOperations = function(n) {
  let res = 0;
  while (n) {
    res ^= n;
    n = n >> 1;
  }
  return res;
};