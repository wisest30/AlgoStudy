/**
 * @param {string} s
 * @param {number} minJump
 * @param {number} maxJump
 * @return {boolean}
 */
var canReach = function(s, minJump, maxJump) {
    const n = s.length - 1;
    if (s[n] !== '0') {
        return false;
    }
    
    let q = [];
    q.push(0);
    let pushedMax = 0;
    while(q.length > 0) {
        let cur = q.shift();
        let min = Math.max(cur + minJump, pushedMax + 1);
        let max = Math.min(cur + maxJump, n);
        if (min > n) {
            continue;
        }
        
        for (let i = min; i <= max; i++) {
            if (i === n) {
                return true;
            }
            if (s[i] === '0') {
                q.push(i);
            }
        }
        pushedMax = max;
    }
    
    return false;
};
