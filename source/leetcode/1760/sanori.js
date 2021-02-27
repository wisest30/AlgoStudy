/**
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */
var minimumSize = function(nums, maxOperations) {
  const n = nums.length;
  if (n < 1) {
    return 0;
  }
  nums.sort((a,b) => b - a);
  const sum = nums.reduce((a,b) => a+b, 0);
  const overflowBag = (bs) => {
    let ops = maxOperations;
    for (let i = 0; i < n; i++) {
      if (nums[i] > bs) {
        ops -= Math.ceil(nums[i]/bs) - 1;
        if (ops < 0) {
          return true;
        }
      }
    }
    return false;
  };

  let lo = Math.ceil(sum/(maxOperations+n), nums[0]/(maxOperations+1));
  let hi = nums[0] + 1;
  while (lo < hi) {
    const mi = Math.floor((lo+hi)/2);
    const of = overflowBag(mi);
    if (of) {
      lo = mi + 1;
    } else {
      hi = mi;
    }
  }
  return hi;
};
