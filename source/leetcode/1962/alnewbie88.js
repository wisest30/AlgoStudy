/**
 * @param {number[]} piles
 * @param {number} k
 * @return {number}
 */
var minStoneSum = function(piles, k) {
    let pq = new MaxPriorityQueue({ priority: (val) => val});
    let totalStones = 0;
    for (let i = 0; i < piles.length; i++) {
        pq.enqueue(piles[i]);
        totalStones += piles[i];
    }
    
    let totalRemovedStones = 0;
    for (let i = 0; i < k; i++) {
        let stones = pq.dequeue().element;
        let removedStones = Math.floor(stones / 2);
        totalRemovedStones += removedStones;
        pq.enqueue(stones - removedStones);
    }
    
    return totalStones - totalRemovedStones;
};