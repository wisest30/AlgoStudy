/**
 * @param {number[][]} tasks
 * @return {number[]}
 */
var getOrder = function(tasks) {
    // sort by enqueueTime (asc)
    tasks.sort(function(a, b) { return a[0] - b[0]; });
    
    let pq = new MinPriorityQueue({ priority: (task) => task.processingTime + Number(task.index) * 0.00001 });   // 0 <= index < 99999
    var enqueueAvailableTasks = function(curTime, startIdx) {
        let i = startIdx;
        for (; i < tasks.length; i++) {
            let task = tasks[i];
            if (curTime < task[0]) {
                break;
            }
            
            pq.enqueue({
                enqueueTime: task[0],
                processingTime: task[1],
                index: i
            });
        }
        return i;
    }
    
    let curTime = tasks[0][0]; // initalize startTime
    let proceedOrder = [];
    let taskIdx = 0;
    while (!pq.isEmpty() || taskIdx < tasks.length) {
        taskIdx = enqueueAvailableTasks(curTime, taskIdx);
        if (!pq.isEmpty()) {
            let task = pq.dequeue().element;
            proceedOrder.push(task.index);
            curTime += task.processingTime;
        }
    }
    
    return proceedOrder;
};