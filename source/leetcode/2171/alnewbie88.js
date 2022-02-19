/**
 * @param {number[]} beans
 * @return {number}
 */
var minimumRemoval = function(beans) {
    beans.sort((a, b) => { return a - b; });
    let remained = 0;
    for (let i = 0; i < beans.length; i++) {
        remained = Math.max(remained, beans[i] * (beans.length - i));
    }
    
    const totalBeans = beans.reduce((accum, curVal) => accum + curVal, 0);
    return totalBeans - remained;
};