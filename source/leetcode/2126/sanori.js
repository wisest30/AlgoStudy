/**
 * @param {number} mass
 * @param {number[]} asteroids
 * @return {boolean}
 */
 var asteroidsDestroyed = function(mass, asteroids) {
  const n = asteroids.length;
  asteroids.sort((a, b) => a - b);
  let cur = mass;
  for (let i = 0; i < n; i++) {
    if (mass < asteroids[i]) {
      return false;
    }
    mass += asteroids[i];
  }
  return true;
};
