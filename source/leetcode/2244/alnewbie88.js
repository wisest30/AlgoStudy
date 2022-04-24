/**
 * @param {number[]} tasks
 * @return {number}
 */
var minimumRounds = function(tasks) {
    let m = new Map();
    tasks.forEach(task => {
        if (m.has(task)) {
            m.set(task, m.get(task) + 1);
        } else {
            m.set(task, 1);
        }
    });
    
    let minRounds = 0;
    let impossible = false;
    m.forEach((value, key) => {
        if (value === 1) {
            impossible = true;
            return;
        }
        
        let div = Math.floor(value / 3);
        let mod = value % 3;
        minRounds += mod === 0 ? div : div + 1;
    });
    
    return impossible ? -1 : minRounds;
};