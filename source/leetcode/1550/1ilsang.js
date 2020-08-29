/**
 * @param {number[]} arr
 * @return {boolean}
 */
const threeConsecutiveOdds = (arr) => {
    let count = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] % 2 === 0) {
            count = 0;
            continue;
        } else if (++count === 3) {
            return true;
        }
    }
    return false;
};