/**
 * @param {number[][]} questions
 * @return {number}
 */
var mostPoints = function(questions) {
    const n = questions.length;
    let memo = new Array(n).fill(-1); // memo[i] means maximum points after questions[i]
    var dfs = function(i) {
        let maxPoints = 0;
        let q = [];
        q.push({index: i, solve: true, totalPoints: questions[i][0]});  // ith question must solve
        while (q.length > 0) {
            let elem = q.pop();
            let newIndex = elem.index + 1;
            if (elem.solve) {
                newIndex += questions[elem.index][1];
            }
            
            if (newIndex >= n) {
                maxPoints = Math.max(maxPoints, elem.totalPoints);
                continue;
            }
            
            if (memo[newIndex] > -1) {
                maxPoints = elem.totalPoints + memo[newIndex];
                continue;
            }

            q.push({index: newIndex, solve: true, totalPoints: elem.totalPoints + questions[newIndex][0]});
            q.push({index: newIndex, solve: false, totalPoints: elem.totalPoints});
        }
        
        return maxPoints;
    }
    
    let maxPoints = 0;
    for (let i = n - 1; i >= 0; i--) {
        let ret = dfs(i);
        maxPoints = Math.max(maxPoints, ret);
        memo[i] = maxPoints;
    }
    
    //console.log(`memo=${JSON.stringify(memo)}`);
    
    return maxPoints;
};