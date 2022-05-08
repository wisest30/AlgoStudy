/**
 * @param {number[]} cards
 * @return {number}
 */
var minimumCardPickup = function(cards) {
    let m = new Map();
    for (let i = 0; i < cards.length; i++) {
        const val = cards[i];
        if (m.has(val)) {
            m.get(val).push(i);
        } else {
            m.set(val, [i]);
        }
    }
    
    let minDist = 100000;
    m.forEach((value, key) => {
        const indexes = value;
        for (let i = 0; i < indexes.length - 1; i++) {   
            const dist = indexes[i + 1] - indexes[i];
            minDist = Math.min(minDist, dist)
        }
    });
    
    return minDist === 100000 ? -1 : minDist + 1;
};