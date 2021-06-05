/**
 * @param {number[]} dist
 * @param {number} hour
 * @return {number}
 */
var minSpeedOnTime = function(dist, hour) {
    if (hour <= dist.length - 1) {
        return -1;
    }
    
    var getTotalTime = function(speed) {
        let totalTime = 0;
        for (let i = 0; i < dist.length; i++) {
            let time = dist[i] / speed;
            if (i == dist.length - 1) { // no need waiting after final train arrival.
                totalTime += time;
            } else {
                totalTime += Math.ceil(time);
            }
        }
        return totalTime;
    }
    
    let l = 1;
    let r = 1000000000;
    let m;
    let minSpeed = 1;
    while (l <= r) {
        m = Math.floor((l + r) / 2);
        let totalTime = getTotalTime(m);
        if (totalTime === hour) {
            return m;
        }
        
        if (totalTime > hour) {
            l = m + 1;
        }
        else {
            minSpeed = m;
            r = m - 1;
        }
    }
    
    return minSpeed;
};
