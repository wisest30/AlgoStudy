/**
 * @param {number} n
 * @param {number[]} startPos
 * @param {string} s
 * @return {number[]}
 */
var executeInstructions = function(n, startPos, s) {
    let answer = [];
    const m = s.length;
    for (let i = 0; i < m; i++) {
        let curRow = startPos[0];
        let curCol = startPos[1];
        let numExec = 0;
        const sub = s.substring(i, m);
        for (let j = 0; j < sub.length; j++) {
            switch (sub[j]) {
                case 'L': curCol--; break;
                case 'R': curCol++; break;
                case 'U': curRow--; break;
                case 'D': curRow++; break;
            }
            if (curCol < 0 || curCol >= n || curRow < 0 || curRow >= n) {   // out of grid
                break;
            }
            numExec++;
        }
        answer.push(numExec);
    }
    
    return answer;
};