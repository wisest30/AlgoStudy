/**
 * @param {number[]} dist
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function(dist, speed) {
    let n = dist.length;
    let monsterArriveTimes = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        let arriveTimeMin = dist[i] / speed[i];
        monsterArriveTimes[i] = arriveTimeMin;
    }
	
	monsterArriveTimes.sort(function(a, b) { return a - b; });
	
	const MAX_TIME_MIN = 100000;    // maxDist / minSpeed
	let killCnt = 1;                // first monster die on zero min
    let nextTargetIdx = 1;
	for (let curMin = 1; curMin <= MAX_TIME_MIN; curMin++) {
		if (killCnt === n) {
			break;
		}
        
		if (monsterArriveTimes[nextTargetIdx] <= curMin) {
			break;  // monster reach the city
		}
		
		killCnt++;
		nextTargetIdx++;
    }
    
    return killCnt;
};