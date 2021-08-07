/**
 * @param {number[][]} students
 * @param {number[][]} mentors
 * @return {number}
 */
var maxCompatibilitySum = function(students, mentors) {
    let m = students.length;
    let n = students[0].length;
    
    // nPr
    var permutation = function(arr, selectNum) {
        let result = [];
        if (selectNum === 1) return arr.map((v) => [v]);
        arr.forEach((v, idx, arr) => {
            const fixer = v;
            const restArr = arr.filter((_, index) => index !== idx);
            const permuationArr = permutation(restArr, selectNum - 1);
            const combineFixer = permuationArr.map((v) => [fixer, ...v]);
            result.push(...combineFixer);
        });
        return result;
    }
    
    let studentIndexes = new Array(m);
    for (let i = 0; i < m; i++) {
        studentIndexes[i] = i;
    }
    
    let perm = permutation(studentIndexes, m);
    let maxScoreSum = 0;
    for (let i = 0; i < perm.length; i++) {
        let studentsOrder = perm[i];
        let scoreSum = 0;
        for (let j = 0; j < studentsOrder.length; j++) {
            let student = students[studentsOrder[j]];
            let mentor = mentors[j];
            let score = 0;
            for (let k = 0; k < n; k++) {
                score += student[k] === mentor[k] ? 1 : 0;
            }
            scoreSum += score;
        }
        
        if (scoreSum > maxScoreSum) {
            maxScoreSum = scoreSum;
        }
    }
    
    return maxScoreSum;
};
