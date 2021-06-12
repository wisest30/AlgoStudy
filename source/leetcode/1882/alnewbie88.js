/**
 * @param {number[]} servers
 * @param {number[]} tasks
 * @return {number[]}
 */
var assignTasks = function(servers, tasks) {
    const pqWork = new MinPriorityQueue({ priority: (elem) => elem.processEndTime });
    const pqIdle = new MinPriorityQueue({ priority: (elem) => elem.weight + elem.index * 0.000001 });
    for (let i = 0; i < servers.length; i++) {
        pqIdle.enqueue({index: i, weight: servers[i]});
    }
    
    let ans = new Array(tasks.length).fill(-1);
    let curTime = 0;
    for (let i = 0; i < tasks.length; i++) {
        while (!pqWork.isEmpty() && pqWork.front().element.processEndTime <= curTime) {
            let server = pqWork.dequeue().element;
            pqIdle.enqueue({index: server.index, weight: server.weight});
        }
        
        let processingTime = tasks[i];
        if (!pqIdle.isEmpty()) {
            let server = pqIdle.dequeue().element;
            ans[i] = server.index;
            pqWork.enqueue({index: server.index, weight: server.weight, processEndTime: curTime + processingTime});
            if (curTime <= i) {
                curTime++;
            }
        } else {
            let minSpendTime = pqWork.front().element.processEndTime - curTime;
            curTime += minSpendTime;
            i--;
        }
    }
    
    return ans;
};