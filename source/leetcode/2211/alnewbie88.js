/**
 * @param {string} directions
 * @return {number}
 */
var countCollisions = function(directions) {
    let cnt = 0;
    
    // collisions L&R or L&S
    let stack = []; // L&S stack
    for (let i = 0; i < directions.length; i++) {
        const dir = directions[i];
        if (dir === 'L') {
            let poped = stack.pop();
            if (poped !== undefined) {
                if (poped === 'R') {
                    cnt += 2;
                } else if (poped === 'S') {
                    cnt ++;
                }
                stack.push('S');
            }
        } else {
            stack.push(dir);
        }
    }
    
    // collisions by R&S
    directions = stack;
    stack = [];    // S stack
    for (let i = directions.length - 1; i >= 0; i--) {
        const dir = directions[i];
        if (dir === 'R') {
            if (stack.pop() !== undefined) {
                cnt++;
                stack.push('S');
            }
        } else {
            stack.push(dir);
        }
    }
    
    return cnt;
};