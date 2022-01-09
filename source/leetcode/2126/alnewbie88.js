/**
 * @param {number} mass
 * @param {number[]} asteroids
 * @return {boolean}
 */
var asteroidsDestroyed = function(mass, asteroids) {
    asteroids.sort((a, b) => { return a - b; });
    
    let curMass = mass;
    for (let i = 0; i < asteroids.length; i++) {
        if (curMass < asteroids[i]) {
            return false;
        }
        curMass += asteroids[i];
    }
    
    return true;
};