/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var digitSum = function(s, k) {
    while (s.length > k) {
        let s2 = '';
        for (let i = 0; i < s.length; i += k) {
            const group = s.substring(i, i + k);
            let sum = 0;
            group.split('').forEach(num => sum += parseInt(num));
            s2 += sum.toString();
        }
        s = s2;
    }
    
    return s;
};