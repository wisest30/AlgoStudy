/**
 * @param {number[]} time
 * @param {number} totalTrips
 * @return {number}
 */
 var minimumTime = function(time, totalTrips) {
  const n = time.length;
  const isFeasible = (t) => {
    let trips = 0;
    for (let i = 0; i < n && trips < totalTrips; i++) {
      trips += Math.floor(t/time[i]);
    }
    return (trips >= totalTrips);
  };

  let lo = 0;
  let hi = totalTrips * Math.max(...time);
  while (lo < hi) {
    const mi = Math.floor((lo + hi) / 2);
    const r = isFeasible(mi);
    if (!r) {
      lo = mi + 1;
    } else {
      hi = mi;
    }
  }
  return hi;
};
