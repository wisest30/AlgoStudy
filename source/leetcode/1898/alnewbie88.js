/**
 * @param {string} s
 * @param {string} p
 * @param {number[]} removable
 * @return {number}
 */
var maximumRemovals = function(s, p, removable) {
    var binarySearch = function(arr, pred) {
        let l = 0;
        let r = arr.length;
        while (l < r) {
            let m = Math.floor((l + r) / 2);
            if (pred(m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return r - 1;
    }
    
    var isSubsequence = function(s1, s2) {
        let j = 0;
        for (let i = 0; i < s2.length && j < s1.length; i++) {
            if (s1[j] === s2[i]) {
                j++;
            }
        }
        return j === s1.length;
    }
    
    let res = binarySearch(removable, idx => {
        let strArr = s.split('');
        for (let i = 0; i <= idx; i++) {
            let removeIdx = removable[i];
            strArr[removeIdx] = '';
        }
        let str = strArr.join('');
        return isSubsequence(p, str);
    });
    
    return res + 1;
};
