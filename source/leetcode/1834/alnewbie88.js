/**
 * @param {number[][]} tasks
 * @return {number[]}
 */
var getOrder = function(tasks) {
    // make tasks with index
    for (let i = 0; i < tasks.length; i++) {
        tasks[i].push(i);
    }
    
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
                index: task[2]
            });
        }
        
        return i;
    }
    
    let curTime = tasks[0][0]; // initalize startTime
    let proceedOrder = [];
    let taskIdx = 0;
    while (true) {
        taskIdx = enqueueAvailableTasks(curTime, taskIdx);
        if (!pq.isEmpty()) {
            let task = pq.dequeue().element;
            proceedOrder.push(task.index);
            curTime += task.processingTime;
        } else {
            if (taskIdx >= tasks.length) {
                break;  // all task proceed.
            }
            curTime = tasks[taskIdx][0];    // idleling
        }
    }
    
    return proceedOrder;
};