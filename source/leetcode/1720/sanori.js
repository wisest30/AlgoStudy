/**
 * @param {number[]} encoded
 * @param {number} first
 * @return {number[]}
 */
var decode = function(encoded, first) {
  const n = encoded.length;
  const res = [first];
  for (let i = 0; i < n; i++) {
    res[i+1] = res[i] ^ encoded[i];
  }
  return res;
};
