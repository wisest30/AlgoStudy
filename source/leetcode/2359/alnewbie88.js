/**
 * @param {number[]} edges
 * @param {number} node1
 * @param {number} node2
 * @return {number}
 */
var closestMeetingNode = function(edges, node1, node2) {
    let iterate = function(startNode, map) {
        let node = startNode;
        let dist = -1;
        do {
            map.set(node, ++dist);
            node = edges[node];
        } while (node !== -1 && !map.has(node));
    }
    
    let map1 = new Map();
    let map2 = new Map();
    iterate(node1, map1);
    iterate(node2, map2);
    
    let minDist = 999999;
    let minDistNode = -1;
    for (const node of map1.keys()) {
        const dist1 = map1.get(node);
        if (map2.has(node)) {
            const dist2 = map2.get(node);
            const dist = Math.max(dist1, dist2);
            if (dist === minDist) {
                minDistNode = Math.min(minDistNode, node);
            } else if (dist < minDist) {
                minDist = dist;
                minDistNode = node;
            }
        }
    }
    
    return minDistNode;
};