/**
 * @param {number[]} plantTime
 * @param {number[]} growTime
 * @return {number}
 */
var earliestFullBloom = function(plantTime, growTime) {
    const n = plantTime.length;
    let flowers = [];
    for (let i = 0; i < n; i++) {
        flowers.push({pt: plantTime[i], gt: growTime[i], plantedTime: -1});
    }
    
    flowers.sort((a, b) => { return b.gt - a.gt; });    // bigger GrowTime is first (desc)

    let plantedFlowers = [];
    let elapsedTimeForPlanting = 0;
    for (let i = 0; i < n; i++) {
        const flower = flowers[i];
        flower.plantedTime = elapsedTimeForPlanting + flower.pt;
        plantedFlowers.push(flower);
        elapsedTimeForPlanting += flower.pt;
    }
    
    let spentTimeForLastBloom = 0;
    for (let i = 0; i < n; i++) {
        const flower = plantedFlowers[i];
        const bloomTime = flower.plantedTime + flower.gt;
        if (bloomTime > elapsedTimeForPlanting) { // not yet bloomed
            spentTimeForLastBloom = Math.max(spentTimeForLastBloom, bloomTime - elapsedTimeForPlanting);
        }
    }
    
    return elapsedTimeForPlanting + spentTimeForLastBloom;
};