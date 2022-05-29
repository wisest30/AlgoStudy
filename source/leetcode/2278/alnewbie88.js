/**
 * @param {string} s
 * @param {character} letter
 * @return {number}
 */
var percentageLetter = function(s, letter) {
    let cnt = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === letter) {
            cnt++;
        }
    }
    
    return Math.floor((cnt / s.length) * 100);
};