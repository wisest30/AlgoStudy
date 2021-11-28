/**
 * @param {number[]} plants
 * @param {number} capacity
 * @return {number}
 */
var wateringPlants = function(plants, capacity) {
    let remainedWater = capacity;
    let steps = 0;
    for (let i = 0; i < plants.length; i++) {
        if (remainedWater >= plants[i]) {   // watering
            remainedWater -= plants[i];
            steps++;
        } else {    // refill
            remainedWater = capacity;
            steps += i * 2;
            i--;
        }
    }
    
    return steps;
};