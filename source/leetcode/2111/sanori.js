/**
 * @param {number[]} nums
 * @return {number}
 */
 var lengthOfLIS = function(nums) {
  const n = nums.length;
  if (n < 1) {
    return 0;
  }
  const sub = [nums[0]];
  for (let i = 1; i < n; i++) {
    const num = nums[i];
    if (num >= sub[sub.length -1]) {
      sub.push(num);
    } else {
      let lo = 0, hi = sub.length;
      while (lo < hi) {
        const mi = (lo + hi) >> 1;
        const val = sub[mi];
        if (val <= num) {
          lo = mi + 1;
        } else {
          hi = mi;
        }
      }
      sub[lo] = num;
    }
  }
  return sub.length;
};


/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var kIncreasing = function(arr, k) {
  const n = arr.length;
  let res = 0;
  for (let s = 0; s < k; s++) {
    const subArr = [];
    for (let i = s; i < n; i += k) {
      subArr.push(arr[i]);
    }
    res += (subArr.length - lengthOfLIS(subArr));
  }
  return res;
};
