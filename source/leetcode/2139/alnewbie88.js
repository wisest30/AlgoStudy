/**
 * @param {number} target
 * @param {number} maxDoubles
 * @return {number}
 */
var minMoves = function(target, maxDoubles) {
    if (target === 1) {
        return 0;
    }
	
    let move = 0;
    while (target !== 1) {
        if (maxDoubles > 0) {
            const remained = target % 2;
            target = Math.floor(target / 2);
            move++;
            maxDoubles--;
            if (remained) {
                move++;
            }
        } else {
            move += target - 1;
            break;
        }
    }
    
    return move;
};