/**
 * @param {number} numArrows
 * @param {number[]} aliceArrows
 * @return {number[]}
 */
var maximumBobPoints = function(numArrows, aliceArrows) {
    let q = [];
    const needArrowForWinSection11 = aliceArrows[11] + 1;
    q.push({section: 10, points: 0, remainArrows: numArrows, arr: [0]});
    if (numArrows >= needArrowForWinSection11) {
        q.push({section: 10, points: 11, remainArrows: numArrows - needArrowForWinSection11, arr: [needArrowForWinSection11]});
    }
    
    let maxPoints = 0;
    let maxPointsBobArrows = [];
    while (q.length > 0) {
        const elem = q.shift();
        const section = elem.section;
        if (section === -1) {
            if (elem.points > maxPoints) {
                maxPoints = elem.points;
                maxPointsBobArrows = elem.arr;
            }
            continue;
        }
        
        const nextSection = elem.section - 1;
        const points = elem.points;
        const remainArrows = elem.remainArrows;
        const needArrowForWinSection = aliceArrows[section] + 1;
        let arr =  elem.arr.slice();
        arr.push(section === 0 ? remainArrows : 0);
        q.push({section: nextSection, points: points, remainArrows: remainArrows, arr: arr});
        
        if (remainArrows >= needArrowForWinSection) {
            let arr2 = elem.arr.slice();
            arr2.push(needArrowForWinSection);
            q.push({section: nextSection, points: points + section, remainArrows: remainArrows - needArrowForWinSection, arr: arr2});
        }
    }
	
    return maxPointsBobArrows.reverse();
};