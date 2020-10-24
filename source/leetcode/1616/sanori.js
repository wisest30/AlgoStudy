const isPalindrome = (a, i, j) => {
  while (i < j) {
    if (a[i] !== a[j]) {
      break;
    }
    i++;
    j--;
  }
  return (i >= j);
};

const check = (a, b) => {
  let i = 0, j = b.length-1;
  while(i < j) {
    if (a[i] !== b[j]) {
      break;
    }
    i++;
    j--;
  }
  return isPalindrome(a, i, j) || isPalindrome(b, i, j);
};

/**
 * @param {string} a
 * @param {string} b
 * @return {boolean}
 */
var checkPalindromeFormation = function(a, b) {
  return check(a, b) || check(b, a);
};
