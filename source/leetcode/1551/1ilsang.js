/**
 * @param {number} n
 * @return {number}
 */
const minOperations = (n) => {
    let answer = 0;
    for (let i = 0; i < n / 2; i++) {
        const x = (2 * i) + 1;
        const y = (2 * (n - i - 1)) + 1;
        answer += (y - x) / 2;
    }
    return answer;
};