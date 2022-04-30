function binarySearch(arr, pred) {
    let l = 0;
    let r = arr.length;
    while (l < r) {
        let m = Math.floor((l + r) / 2);
        if (pred(arr[m])) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

function lowerBound(arr, val) {
    return binarySearch(arr, item => val <= item);
}

function upperBound(arr, val) {
    return binarySearch(arr, item => val < item);
}

/**
 * @param {number[][]} rectangles
 * @param {number[][]} points
 * @return {number[]}
 */
var countRectangles = function(rectangles, points) {
    let sortedRects = rectangles.slice();
    sortedRects.sort((a, b) => { return b[0] - a[0]; });    // l desc
    let m = new Map();
    sortedRects.forEach(rect => {
        const l = rect[0];
        const h = rect[1];
        if (!m.has(l)) {
            m.set(l, new Array(101).fill(0));
        }
        let arr = m.get(l);
        for (let i = 1; i <= h; i++) {
            arr[i]++;
        }
    });
    
    let keys = Array.from(m.keys());
    for (let i = 0; i < keys.length - 1; i++) {
        const l = keys[i];
        const l2 = keys[i + 1];
        const arr = m.get(l);
        let arr2 = m.get(l2);
        for (let j = 0; j < arr.length; j++) {
            arr2[j] = arr[j] + arr2[j];
        }
    }
    //m.forEach((val, key) => console.log(`key=${key}, val=${val}`));
    
    rectangles.sort((a, b) => { return a[0] - b[0]; });
    const lArr = rectangles.map(rect => rect[0]);
    
    let ans = [];
    points.forEach(point => {
        const x = point[0];
        const y = point[1];
        const foundIndex = lowerBound(lArr, x);
        if (foundIndex === lArr.length) {
            ans.push(0);
            return;
        }
        const l = lArr[foundIndex];
        ans.push(m.get(l)[y]);
    });
    
    return ans;
};