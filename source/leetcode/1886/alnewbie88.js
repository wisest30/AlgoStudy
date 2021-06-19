/**
 * @param {number[][]} mat
 * @param {number[][]} target
 * @return {boolean}
 */
var findRotation = function(mat, target) {
    let n = mat.length;
    var rotate90deg = function(inMat) {
        let res = new Array(n);
        for (let i = 0; i < n; i++) {
            res[i] = new Array(n);
        }
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                res[i][j] = inMat[n-1-j][i];
            }
        }
        return res;
    }
    
    var checkEqualBetween = function(matA, matB) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (matA[i][j] !== matB[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    if (checkEqualBetween(mat, target)) {
        return true;
    }
    
    for (let rotCnt = 1; rotCnt <= 3; rotCnt++) {
        mat = rotate90deg(mat);
        if (checkEqualBetween(mat, target)) {
            return true;
        }
    }
    
    return false;
};