/**
 * @param {number} num
 * @return {number}
 */
var smallestNumber = function(num) {
    let splited = num.toString().split('');
    const negative = splited[0] === '-';
    if (negative) {
        splited.shift();    // remove '-'
        splited.sort((a, b) => { return b - a; });
        return Number(splited.join('')) * -1;
    }
    
    // positive case
    splited.sort((a, b) => { return a - b; });
    
    let foundIndex = -1;
    for (let i = 0; i < splited.length; i++) {
        if (splited[i] !== '0') {
            foundIndex = i;
            break;
        }
    }

    const temp = splited[foundIndex];
    splited.splice(foundIndex, 1);
    splited.unshift(temp);   // push front
    return Number(splited.join(''));
};