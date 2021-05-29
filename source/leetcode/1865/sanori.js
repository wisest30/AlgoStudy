/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 */
 var FindSumPairs = function(nums1, nums2) {
  this.n1 = nums1;
  this.n2 = nums2;
  const freq1 = nums1.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
  this.freq1Arr = Object.entries(freq1);
  this.freq2 = nums2.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
FindSumPairs.prototype.add = function(index, val) {
  const prev = this.n2[index];
  this.n2[index] += val;
  const next = this.n2[index];
  this.freq2[prev]--;
  this.freq2[next] = this.freq2[next] + 1 || 1;
};

/** 
 * @param {number} tot
 * @return {number}
 */
FindSumPairs.prototype.count = function(tot) {
  let res = 0;
  for (const [v, c] of this.freq1Arr) {
    const target = tot - v;
    if (this.freq2[target] > 0) {
      res += c * this.freq2[target];
    }
  }
  return res;
};