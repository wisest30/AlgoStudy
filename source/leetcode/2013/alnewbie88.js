var points;
var numPoints;
var DetectSquares = function() {
    points = new Array();
    numPoints = new Array(1001);
    for (let i = 0; i < numPoints.length; i++) {
        numPoints[i] = new Array(1001).fill(0);
    }
};

/** 
 * @param {number[]} point
 * @return {void}
 */
DetectSquares.prototype.add = function(point) {
    points.push(point);
    numPoints[point[0]][point[1]]++;
};

/** 
 * @param {number[]} point
 * @return {number}
 */
DetectSquares.prototype.count = function(point) {
    let ret = 0;
    const a = point;
    points.forEach(d => {
        const w = Math.abs(d[0] - a[0]);
        const h = Math.abs(d[1] - a[1]);
        if (w !== 0 && w === h) {
            ret += numPoints[d[0]][a[1]] * numPoints[a[0]][d[1]];
        }
    });
    
    return ret;
};

/** 
 * Your DetectSquares object will be instantiated and called as such:
 * var obj = new DetectSquares()
 * obj.add(point)
 * var param_2 = obj.count(point)
 */