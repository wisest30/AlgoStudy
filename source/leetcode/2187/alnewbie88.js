/**
 * @param {number[]} time
 * @param {number} totalTrips
 * @return {number}
 */
var minimumTime = function(time, totalTrips) {
    let check = function(val) {
        let trips = 0;
        for (let i = 0; i < time.length; i++) {
            trips += Math.floor(val / time[i]);
            if (trips >= totalTrips) {
                return true;
            }
        }
        return false;
    }
    
    let l = 0;
    let r = 100000000000000;  // worst case = time = [10^7], totalTrips = 10^7 = 10^7 * 10^7
    while (l < r) {
        let m = Math.floor((l + r) / 2);
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    return r;
};