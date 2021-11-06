/**
 * @param {number[]} nums
 * @param {number} start
 * @param {number} goal
 * @return {number}
 */
var minimumOperations = function(nums, start, goal) {
    let visited = new Array(1001).fill(false);
    let q = new Queue();
    q.enqueue({operCnt: 0, val: start});
    while(!q.isEmpty()) {
        const cur = q.dequeue();
        if (cur.val === goal) {
            return cur.operCnt;
        } else if (cur.val < 0 || cur.val > 1000 || visited[cur.val]) {
            continue;
        }
        
        visited[cur.val] = true;
        
        const newOperCnt = cur.operCnt + 1;
        for (let i = 0; i < nums.length; i++) {
            let oper1Res = cur.val + nums[i];
            let oper2Res = cur.val - nums[i];
            let oper3Res = cur.val ^ nums[i];
            q.enqueue({operCnt: newOperCnt, val: oper1Res});
            q.enqueue({operCnt: newOperCnt, val: oper2Res});
            q.enqueue({operCnt: newOperCnt, val: oper3Res});
        }
    }
    
    return -1;
};
