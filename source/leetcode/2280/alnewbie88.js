/**
 * @param {number[][]} stockPrices
 * @return {number}
 */
var minimumLines = function(stockPrices) {
    stockPrices.sort((a, b) => { return a[0] - b[0]; });
    
    let prevDeltaX = BigInt(0);
    let prevDeltaY = BigInt(0);
    let prevSlope = undefined;
    let lines = 0;
    for (let i = 1; i < stockPrices.length; i++) {
        const deltaX = BigInt(stockPrices[i][0] - stockPrices[i - 1][0]);
        const deltaY = BigInt(stockPrices[i][1] - stockPrices[i - 1][1]);
        const slope = deltaY / deltaX;
        //if (i === 1 || slope != prevSlope) { // error on "[[1,1],[500000000,499999999],[1000000000,999999998]]"
        if (i === 1 || (prevDeltaY * deltaX !== prevDeltaX * deltaY)) {
            lines++;
        }
        
        prevDeltaX = deltaX;
        prevDeltaY = deltaY;
        prevSlope = slope;
    }
    
    return lines;
};