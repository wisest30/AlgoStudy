/**
 * @param {number} n
 * @param {number[][]} preferences
 * @param {number[][]} pairs
 * @return {number}
 */
var unhappyFriends = function(n, preferences, pairs) {
  const counterpart = [];  
  for (const [a, b] of pairs) {
    counterpart[a] = b;
    counterpart[b] = a;
  }
  const overs = Array(n);
  for (let i = 0; i < n; i++) {
    const idx = preferences[i].indexOf(counterpart[i]);
    overs[i] = preferences[i].slice(0, idx);
  }

  let res = 0;
  for (let i = 0; i < n; i++) {
    for (const c of overs[i]) {
      if (overs[c].indexOf(i) >= 0) {
        res++;
        break;
      }
    }
  }
  return res;
};
