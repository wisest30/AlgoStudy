const mod = BigInt(1e9 + 7);
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSumMinProduct = function(nums) {
  const preSum = nums.reduce((acc, cur) => {
    acc.push(acc[acc.length-1] + cur);
    return acc;
  }, [0]);
  const n = nums.length;
  const lBound = Array(n);
  let stack = [];

  for (let i = 0; i < n; i++) {
    while(stack.length > 0 && nums[stack[stack.length-1]] >= nums[i]) {
      stack.pop();
    }
    lBound[i] = (stack.length < 1) ? 0 : stack[stack.length-1] + 1;
    stack.push(i);
  }

  let res = 0n;
  stack = [];
  for (let i = n-1; i >= 0; --i) {
    while(stack.length > 0 && nums[stack[stack.length-1]] >= nums[i]) {
      stack.pop();
    }
    const rBound = (stack.length < 1) ? n : stack[stack.length-1];
    const cand = BigInt(preSum[rBound] - preSum[lBound[i]]) * BigInt(nums[i]);
    if (res < cand) {
      res = cand;
    }
    stack.push(i);
  }
  return Number(res % mod);
};
