/**
 * @param {number[][]} logs
 * @param {number} k
 * @return {number[]}
 */
var findingUsersActiveMinutes = function(logs, k) {
    let userActionData = new Map();   // key : userId, value : Set of unique active minute
    for (const logData of logs) {
        let id = logData[0];
        let minute = logData[1];
        if (!userActionData.has(id)) {
            userActionData.set(id, new Set());
        }
        userActionData.get(id).add(minute);
    }
    
    let userCountOnUAM = new Array(k).fill(0);
    for (let [key, value] of userActionData) {
        let uam = value.size;
        userCountOnUAM[uam - 1]++;    // uam - 1 : 1-indexed
    }
    
    return userCountOnUAM;
};