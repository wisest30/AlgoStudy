/**
 * @param {number[]} milestones
 * @return {number}
 */
var numberOfWeeks = function(milestones) {
    milestones.sort(function(a, b) { return b - a; });
    console.log(milestones);
    
    let biggest = milestones[0];
    let sumWithoutBiggest = milestones.reduce((accum, cur) => accum + cur, 0) - biggest;
    if (biggest > sumWithoutBiggest) {
        return sumWithoutBiggest * 2 + 1;
    }
    
    return biggest + sumWithoutBiggest;
};