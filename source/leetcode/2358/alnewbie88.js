let memo = new Array(1000).fill(0);
function func(num) {
    if (num === 0) {
        return 0;
    }
    if (num === 1) {
        return 1;
    } 
        
    if (memo[num] > 0) {
        return memo[num];
    }
    
    memo[num] = func(num - 1) + num;
    return memo[num];
}

/**
 * @param {number[]} grades
 * @return {number}
 */
var maximumGroups = function(grades) {
    const n = grades.length;
    let i = 1;
    for (; i <= 1000; i++) {
        if (n < func(i)) {
            break;
        }
    }
    return i - 1;
};