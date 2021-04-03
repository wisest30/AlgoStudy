/**
 * @param {number[][]} orders
 * @return {number}
 */
var getNumberOfBacklogOrders = function(orders) {
    let pq_buy = new MaxPriorityQueue({ priority: (order) => order[0]});
    let pq_sell = new MinPriorityQueue({ priority: (order) => order[0]});
    
    let orderIdx = 0;
    for (const order of orders) {
        //let price = order[0];
        //let amount = order[1];
        //let type = order[2];
        //console.log("order[" + orderIdx + "]=" + order);
        while (order[1] > 0) {
            if (order[2] === 0) {
                if (pq_sell.isEmpty()) {
                    pq_buy.enqueue(order);
                    break;
                } else {
                    let minPriceSellOrder = pq_sell.front().element;
                    if (order[0] >= minPriceSellOrder[0]) {
                        let matched = Math.min(order[1], minPriceSellOrder[1]);
                        minPriceSellOrder[1] -= matched; 
                        order[1] -= matched;
                        if (minPriceSellOrder[1] === 0) {
                            pq_sell.dequeue();
                        }
                    } else {
                        pq_buy.enqueue(order);
                        break;
                    }
                }
            } else {
                if (pq_buy.isEmpty()) {
                    pq_sell.enqueue(order);
                    break;
                } else {
                    let maxPriceBuyOrder = pq_buy.front().element;
                    if (order[0] <= maxPriceBuyOrder[0]) {
                        let matched = Math.min(order[1], maxPriceBuyOrder[1]);
                        maxPriceBuyOrder[1] -= matched; 
                        order[1] -= matched;
                        if (maxPriceBuyOrder[1] === 0) {
                            pq_buy.dequeue();
                        }
                    } else {
                        pq_sell.enqueue(order);
                        break;
                    }
                }
            }
        }
        orderIdx++;
    }
    
    let sumAmount = 0;
    while (!pq_buy.isEmpty()) {
        sumAmount += pq_buy.dequeue().element[1];
    }
    while (!pq_sell.isEmpty()) {
        sumAmount += pq_sell.dequeue().element[1];
    }
    
    return sumAmount % (1000000000 + 7);
};